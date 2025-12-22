#include "instruct.h"

/* ================================================================ */

int main(int argc, char** argv) {

    short a = 0x010A;
    short* ap = &a;

    log_as_bytesV(&a, sizeof(a));

    printf("\n");

    log_as_bytesV(&ap, sizeof(ap));
    printf("%p\n", &a);

    /* ======== */
    return EXIT_SUCCESS;
}

/* ================================================================ */