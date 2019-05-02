#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

template <class T>
bitset<8*sizeof(T)> getBitExpression(T input) {
    return bitset<8*sizeof(T)> (input);
}

int flipBitToWin(int input) {
    int currLen = 0, prevLen = 0;
    int maxVal = 0;

    while (input) {
        if (input & 1) {  // 1
            currLen++;
        } else {          // 0
            prevLen = (input & 2) ? 0 : currLen;
            currLen = 0;
        }
        maxVal = max(maxVal, prevLen+currLen+1);
        input >>= 1;
    }

    return maxVal;
}

int main()
{
    int a = 17745;
    auto bitA = getBitExpression(a);
    cout << bitA << endl;
    cout << flipBitToWin(a) << endl;
}
