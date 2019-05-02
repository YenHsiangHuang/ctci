#include <iostream>
void swap(int& x, int& y) {
    y -= x;
    x += y;
    y = x - y;
}

/**
   Two properties are used:
     1. Self-XOR = 0 (a ^ a = 0)
     2. XOR with 0 remains the same (a ^ 0 = a)
 */
void xorSwap(int& x, int& y) {
    x ^= y;  // x = x ^ y
    y ^= x;  // y = (x ^ y) ^ y = x
    x ^= y;  // x = (x ^ y) ^ (x ^ y ^ y) = y
}

int main(int argc, const char *argv[]) {
    int x = 3, y = 5;
    swap(x, y);
    std::cout << x << " " << y << std::endl;
    xorSwap(x, y);
    std::cout << x << " " << y << std::endl;
    return 0;
}
