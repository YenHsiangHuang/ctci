// Input: "Tact Coa"
// Output: true ("Taco Cat", "Atco Cta")

#include <stdio.h>
#include <string>

using std::string;

bool isPermutationOfPalindrome(string s) {
    int hist[26] = {0};
    for (int i = 0; i < s.length(); i++) {
        if ('a' <= s[i] && 'z' >= s[i]) {
            hist[s[i]-'a']++;
        } else if ('A' <= s[i] && 'Z' >= s[i]) {
            hist[s[i]-'A']++;
        }
    }

    bool oddCount = false;
    for (int i = 0; i < 26; i++) {
        if (hist[i]%2 != 0) {
            if (oddCount == false) oddCount = true;
            else return false;
        }
    }
    return true;
}

// Using bit vector instead of a histogram
bool isPermutationOfPalindromeBit(string s) {
    int bitVec = 0;
    for (int i = 0; i < s.length(); i++) {
        if ('a' <= s[i] && 'z' >= s[i]) {
            bitVec ^= 1 << (s[i]-'a');
        } else if ('A' <= s[i] && 'Z' >= s[i]) {
            bitVec ^= 1 << (s[i]-'A');
        }
    }

    return (bitVec == 0) || ((bitVec & (bitVec - 1)) == 0);
}

int main()
{
    string s = "Tact Coa";
    printf("%d\n", isPermutationOfPalindrome(s));
    printf("%d\n", isPermutationOfPalindromeBit(s));

    s = "app le e";
    printf("%d\n", isPermutationOfPalindrome(s));
    printf("%d\n", isPermutationOfPalindromeBit(s));
    return 0;
}
