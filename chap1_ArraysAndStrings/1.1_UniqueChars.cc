// Implement an algorithm to determine if a string has all unique characters.
// What if you cannot use additional data structures?

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

bool isUniqueChars(string s) {
    // Assume the char set is ASCII, so the length of histogram can be 256
    bool histogram[256] = {false};
    for (auto &c : s) {
        if (histogram[(int)c]) return false;
        histogram[(int)c] = true;
    }
    return true;
}

bool isUniqueCharsBit(string s) {
    // Save some space by using bit array
    // Handles only chars from a-z and A-Z
    int histogram = 0;
    for (auto &c : s) {
        if ((int)c > 'a') c -= 'a';
        else              c -= 'A';

        if ((histogram >> c) & 1) return false;
        histogram = histogram | (1 << c);
    }
    return true;
}

int main()
{
    vector<string> svec = {"",
                           "12hi",
                           "helo",
                           "key",
                           "keqherkjoj",
                           "XXXXX"};
    for (auto &s : svec) cout << isUniqueChars(s) << " " << s << endl;

    cout << endl;

    vector<string> svecbit = {"",
                              "HH",
                              "helo",
                              "key",
                              "keqherkjoj",
                              "xxxxx"};
    for (auto &s : svecbit) cout << isUniqueCharsBit(s) << " " << s << endl;

    return 0;
}
