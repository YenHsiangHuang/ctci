#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <bitset>
using namespace std;

template <class T>
bitset<8*sizeof(T)> getBitExpression(T input) {
    return bitset<8*sizeof(T)> (input);
}

void printBit(int n) {
    printf("%12d %s\n", n, getBitExpression(n).to_string().c_str());
}
// ******************************************************************

typedef unsigned char byte_t;

void drawScreen(byte_t screen[], int wid, int hei) {
    for (int h = 0; h < hei; h++) {
        for (int w = 0; w < wid/8; w++) {
            printf("%s ", getBitExpression(screen[h*wid/8 + w]).to_string().c_str());
        }
        printf("\n");
    }
}

void drawLine(byte_t screen[], int wid, int x1, int x2, int y)  {
    assert (x2 >= x1);
    assert (x2 <= wid);
    assert (x1 >= 0);
    const int BYTESIZE = 8;
    int colStart = x1/BYTESIZE, colEnd = x2/BYTESIZE;
    int elemStart = y*wid/BYTESIZE + colStart;
    int elemEnd   = y*wid/BYTESIZE + colEnd;

    if (elemEnd > elemStart + 1) {
        for (int i = elemStart+1; i != elemEnd; i++) screen[i] = 0xff;
    }

    byte_t maskStart = 0xff >> (x1 - colStart*BYTESIZE);
    byte_t maskEnd   = ~(0xff >> ((x2 - colEnd*BYTESIZE)+1));

    if (elemStart == elemEnd) {
        screen[elemStart] |= (maskStart & maskEnd);
    } else {
        screen[elemStart] |= maskStart;
        screen[elemEnd]   |= maskEnd;
    }
}


int main()
{
    const int wid = 48, hei = 10;
    const int screenSize = wid*hei;
    byte_t screen[screenSize/8+1] = {0};
    screen[screenSize/8] = '\0';

    drawScreen(screen, wid, hei);
    printf("\n");

    drawLine(screen, wid, 0, 47, 5);

    drawScreen(screen, wid, hei);
    printf("\n");
}
