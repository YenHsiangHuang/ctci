// What it does?  (n & (n-1)) == 0
#include <stdio.h>

bool isPowerOf2(int n) {
    return (n & (n-1)) == 0;
}

int main() {
    printf("It checks whether n is the power of 2.\n");
}
