#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <bitset>
using namespace std;

template <class T>
bitset<8*sizeof(T)> getBitExpression(T input) {
    return bitset<8*sizeof(T)> (input);
}

void printBit(int n) {
    printf("%12d %s\n", n, getBitExpression(n).to_string().c_str());
}

int swapBitPair(int n) {
    return ((unsigned)(n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
}

int main()
{
    srand(time(nullptr));
    int n = rand();

    printBit(n);
    printBit(swapBitPair(n));
}
