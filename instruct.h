#ifndef _INTERNAL_STRUCTURE_H
#define _INTERNAL_STRUCTURE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

/* ================================================================ */

/**
 * A utility that prints the raw memory contents at `mem_reg` (first `num_bytes` bytes) as a space-separated sequence of two-digit uppercase hexadecimal values.
 */
static inline void log_as_bytes(const void* mem_reg, size_t num_bytes) {

    unsigned char* byte = (unsigned char*) mem_reg;

    for (size_t i = 0; i < num_bytes; i++) {
        printf("%.2X", *byte++);

        putchar(' ');
    }
    printf("\n");
}

/**
 * A utility that prints the raw memory contents at `mem_reg` (first `num_bytes` bytes) as space-separated binary strings.
 */
static inline void log_as_bits(const void* mem_reg, size_t num_bytes) {

    unsigned char* byte = (unsigned char*) mem_reg;

    for (size_t i = 0; i < num_bytes; i++, byte++) {

        for (int b = CHAR_BIT - 1; b >= 0; b--) {
            putchar(*byte & (1u << b) ? '1' : '0');
        }

        putchar(' ');
    }
    putchar('\n');
}

/**
 * A utility that detects the system's endianness. It's either `L` (little-endian) or `B` (big-endian) 
 */
static inline char get_endianness(void) {

    short t = 0x01;

    return (*((unsigned char*) &t) == 0x01) ? 'L' : 'B';
}

/**
 * An accessor that safely extracts a specific byte from memory at `mem_reg` within `num_bytes` bounds.
 */
static inline unsigned char get_byte(const void* mem_reg, size_t num_bytes, int byte_idx) {
    return *(((unsigned char*) mem_reg) + ((byte_idx < 1) ? 0 : (byte_idx > num_bytes) ? num_bytes - 1 : byte_idx - 1));
}

/**
 * A utility that safely sets a specific byte in memory at `mem_reg` within `num_bytes` bounds to the given value.
 */
static inline void set_byte(void* mem_reg, size_t num_bytes, int byte_idx, unsigned char value) {
    *(((unsigned char*) mem_reg) + ((byte_idx < 1) ? 0 : (byte_idx > num_bytes) ? num_bytes - 1 : byte_idx - 1)) = value;
}

/**
 * A utility that sets a specific bit in the first byte of memory at `mem_reg` to `1`.
 */
static inline void set_bit(void* mem_reg, size_t num_bytes, int bit_idx) {

    if (bit_idx == 0) { return ; }

    *((unsigned char*) mem_reg) |= (1 << ((bit_idx >= CHAR_BIT) ? 7 : bit_idx - 1));
}

/**
 * A utility that sets a specific bit in the first byte of memory at `mem_reg` to `0`.
 */
static inline void clear_bit(void* mem_reg, size_t num_bytes, int bit_idx) {

    if (bit_idx == 0) { return ; }

    *((unsigned char*) mem_reg) &= ~(1 << ((bit_idx >= CHAR_BIT) ? 7 : bit_idx - 1));
}

/**
 * This prints each byte in a memory region along with its address
 */
static inline void log_as_bytesV(const void* mem_reg, size_t num_bytes) {

    for (size_t i = 0; i < num_bytes; i++) {
        printf("Address: %p\n", mem_reg + i);
        printf("Value  : ");
        log_as_bytes(mem_reg + i, sizeof(unsigned char));
    }
}

/**
 * This logs each byte of memory starting at `mem_reg` as a sequence of bits, printing the address and bit representation for each byte individually.
 */
static inline void log_as_bitsV(const void* mem_reg, size_t num_bytes) {

    for (size_t i = 0; i < num_bytes; i++) {
        printf("Address: %p\n", mem_reg + i);
        printf("Value  : ");
        log_as_bits(mem_reg + i, sizeof(unsigned char));
    }
}

/**
 * A utility that returns a pointer to the byte at the specified position in `mem_reg`.
 */
static inline unsigned char* ret_byte(const void* mem_reg, size_t num_bytes, int byte_idx) {
    return (((unsigned char*) mem_reg) + ((byte_idx < 1) ? 0 : (byte_idx > num_bytes) ? num_bytes - 1 : byte_idx - 1));
}

/* ================================================================ */

#ifdef __cplusplus
}
#endif

#endif /* _INTERNAL_STRUCTURE_H */