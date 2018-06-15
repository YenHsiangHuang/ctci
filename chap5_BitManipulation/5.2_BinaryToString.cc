#include <iostream>
#include <string>
#include <bitset>
using namespace std;

string binaryToString(double input) {
    if (input > 1.0 || input < 0.0) return string ("ERROR");

    int maxSize = 32;
    string s;
    s.resize(maxSize);
    int i = 0;
    s[i] = '.';

    while (input > 0) {
        if (i >= maxSize) return string("ERROR");

        double r = input * 2.0;
        if (r >= 1) {
            s[++i] = '1';
            input = r - 1;
        } else {
            s[++i] = '0';
            input = r;
        }
    }

    return s;
}

int main()
{
    double a = 0.5+0.125;
    cout << binaryToString(a) << endl;
}
