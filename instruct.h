#ifndef _INTERNAL_STRUCTURE_H
#define _INTERNAL_STRUCTURE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

/* ================================================================ */

/**
 * 
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
 * 
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
 * 
 */
static inline char get_endianness(void) {

    short t = 0x01;

    return (*((unsigned char*) &t) == 0x01) ? 'L' : 'B';
}

/**
 * 
 */
static inline unsigned char get_byte(const void* mem_reg, size_t num_bytes, int byte) {
    return *(((unsigned char*) mem_reg) + ((byte < 1) ? 0 : (byte > num_bytes) ? num_bytes - 1 : byte - 1));
}

/**
 * 
 */
static inline void set_byte(void* mem_reg, size_t num_bytes, int byte, unsigned char value) {
    *(((unsigned char*) mem_reg) + ((byte < 1) ? 0 : (byte > num_bytes) ? num_bytes - 1 : byte - 1)) = value;
}

/**
 * 
 */
static inline void set_bit(void* mem_reg, size_t num_bytes, int bit) {

    if (bit == 0) { return ; }

    *((unsigned char*) mem_reg) |= (1 << ((bit >= CHAR_BIT) ? 7 : bit - 1));
}

/* ================================================================ */

#ifdef __cplusplus
}
#endif

#endif /* _INTERNAL_STRUCTURE_H */