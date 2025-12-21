#include "instruct.h"

/* ================================================================ */

int main(int argc, char** argv) {

    short a = 0x010A;

    log_as_bytes(&a, sizeof(a));
    log_as_bits(&a, sizeof(a));

    set_bit((unsigned char*) &a + 1, sizeof(a), 14);
    log_as_bits(&a, sizeof(a));

    /* ======== */
    return EXIT_SUCCESS;
}

/* ================================================================ */