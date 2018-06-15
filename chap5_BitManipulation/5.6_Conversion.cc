
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

// NOTE: n & (n-1) clears the least significant 1 bit of n
int bitFlipRequired(int a, int b) {
    int cnt = 0;
    for (int c = a^b; c != 0; c &= c-1) cnt++;
    return cnt;
}

int main()
{
    srand(time(nullptr));
    int a = rand(), b = rand();

    printBit(a);
    printBit(b);
    printf("\n");
    printf("%d bits should be fliped\n", bitFlipRequired(a, b));
}
