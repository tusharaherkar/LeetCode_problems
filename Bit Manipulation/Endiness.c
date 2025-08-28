#include <stdio.h>

// checkEndianness()
void checkEndianness() {
    unsigned int x = 1;
    char *c = (char*)&x;

    if (*c) {
        printf("Little-endian\n");
    } else {
        printf("Big-endian\n");
    }

}

int main() {
    checkEndianness();
    return 0;
}

// Converting Between Endianness

#include <stdio.h>
// Function to swap the bytes of a 32-bit integer
unsigned int swapEndianness(unsigned int x) {
    return ((x >> 24) & 0x000000FF) |
    ((x >> 8) & 0x0000FF00) |
    ((x << 8) & 0x00FF0000) |
    ((x << 24) & 0xFF000000);
}

int main() {
    unsigned int num = 0x12345678;
    printf("Original: 0x%x\n", num);
    unsigned int swapped = swapEndianness(num);
    printf("Swapped: 0x%x\n", swapped);
    return 0;
}