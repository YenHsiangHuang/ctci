#include <iostream>
#include <bitset>
using namespace std;

template <class T>
bitset<8*sizeof(T)> getBitExpression(T input) {
    return bitset<8*sizeof(T)> (input);
}

void bitInsertion(int M, int& N, int i, int j) {
    int mask = ~(((1 << (j-i+1)) - 1) << i);
    N &= mask;
    N |= (M << i);
}


int main()
{
    int N = 502384;
    int i = 5, j = 8;
    int M = 9;
    bitset<8*sizeof(decltype(N))> bitN = getBitExpression(N);
    bitset<8*sizeof(decltype(M))> bitM = getBitExpression(M);
    cout << "N = " << bitN << endl;
    cout << "M = " << bitM << endl;
    bitInsertion(M, N, i, j);
    bitN = getBitExpression(N);
    cout << "N = " << bitN << endl;
}
