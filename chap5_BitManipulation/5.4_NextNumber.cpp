/**
   Next Number

   Given a positive integer, find the next smallest and largest integer
   that have the same amount of 1 bits
 */
#include <iostream>
#include <bitset>
#include <climits>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

template <class T>
bitset<8*sizeof(T)> getBitExpression(T input) {
    return bitset<8*sizeof(T)> (input);
}

void printBit(int n) {
    printf("%11d %s\n", n, getBitExpression(n).to_string().c_str());
}

int hammingWeight(uint32_t n) {
    int cnt = 0;
    for (cnt = 0; n; cnt++) n &= (n - 1);
    return cnt;
}

/*
// This uses fewer arithmetic operations than any other known implementation on machines with slow multiplication.
// It uses 17 arithmetic operations.
int hammingWeight(uint32_t n) {
    n -= (n >> 1) & 0x55555555;                   // put count of each 2 bits into those 2 bits
    n = (n & 0x33333333) + (n >> 2 & 0x33333333); // put count of each 4 bits into those 4 bits
    n = (n + (n >> 4)) & 0x0F0F0F0F;              // put count of each 8 bits into those 8 bits
    n += n >> 8;                                  // put count of each 16 bits into those 8 bits
    n += n >> 16;                                 // put count of each 32 bits into those 8 bits
    return n & 0xFF;
}

// This uses fewer arithmetic operations than any other known implementation on machines with fast multiplication.
// It uses 12 arithmetic operations, one of which is a multiply.
int hammingWeight(uint32_t n) {
    n -= (n >> 1) & 0x55555555;                   // put count of each 2 bits into those 2 bits
    n = (n & 0x33333333) + (n >> 2 & 0x33333333); // put count of each 4 bits into those 4 bits
    n = (n + (n >> 4)) & 0x0F0F0F0F;              // put count of each 8 bits into those 8 bits
    return n * 0x01010101 >> 24;                  // returns left 8 bits of x + (x<<8) + (x<<16) + (x<<24)
}
*/

bool findNextNumber(int32_t input, int32_t& smallest, int32_t& largest) {
    assert(input > 0);

    /**
       smallest
       starting from the right side, finding the first 01xxxxxx
       move 1 bit one step forward, and push all the 1 bits in xxxxx backwards

       Use mask 100000s
       input & mask will give 0 at 01 pair

                    p
                    |
                    v         i
               xxxxx01 111111110000000000
               00000100000000000000000000
           & ----------------------------
               00000000000000000000000000
     */
    int32_t tmp = input;
    int p, i = 0;
    while ((tmp & 1) == 0 && tmp != 0) {
        i++;
        tmp >>= 1;
    }
    p = i;
    while (tmp & 1) {
        p++;
        tmp >>= 1;
    }

    smallest = input | (1 << p);     // Flip p-th bit to 1
    smallest &= ~((1 << p) - 1);     // Clear 0~p-2 th bits
    smallest |= (1 << (p-i-1)) - 1;  // Add ones to tail
    if (smallest <= input) return false;

    /**
       Largest

       Not optimized. It seems that I can implement a method to get previous
       largest number that has the same number of 1 bits.
     */
    int numOnes = hammingWeight(input);
    largest = ((1 << numOnes) - 1) << (31 - numOnes);
    if (largest <= input) return false;

    if (largest <= smallest) return false;
    return true;
}



int main()
{
    int32_t input, smallest, largest;
    srand(time(nullptr));
    for (int i = 0; i < 5; i++) {
        input = rand();
        findNextNumber(input, smallest, largest);
        printBit(   input);
        printBit(smallest);
        printBit( largest);
        printf("\n");
    }
}
