// Whether two strings are anagrams or not

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

bool isAnagram(string a, string b) {
    // Solution 1: Histogram of two strings
    // Solution 2: return sort(a) == sort(b);

    // I use solution 1 here and
    // assume ASCII
    int aLen = a.length(), bLen = b.length();
    if (aLen != bLen) return false;

    int hist[256] = {0};
    for (auto &c : a) {
        hist[(int)c]++;
    }

    for (auto &c : b) {
        if (hist[(int)c] == 0) return false;
        hist[(int)c]--;
    }

    return true;

}

int main()
{
    string a = "hello", b = "ehlol";
    cout << isAnagram(a, b);
    return 0;
}
