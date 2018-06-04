#include <stdio.h>
#include <string>

using std::string;

bool isPermutation(string s1, string s2) {
    if (s1.length() != s2.length()) return false;

    int hist[256] = {0};
    for (int i = 0; i < s1.length(); i++) {
        hist[s1[i]]++;
    }
    for (int i = 0; i < s2.length(); i++) {
        if (hist[s2[i]] == 0) return false;
        hist[s2[i]]--;
    }
    return true;
}

int main()
{
    string s1 = "hello", s2 = "hlleo";
    printf("%d\n", isPermutation(s1, s2));
}
