#include <stdio.h>
#include <string>

using std::string;

string compress(string s) {
    if (s.length() < 3) return s;

    string compressed;
    compressed.reserve(s.length()*2);  // Reserve space for string to prevent reallocation

    int i = 0, start;
    while (i < s.length()) {
        start = i;
        while (s[i+1] == s[start]) i++;
        compressed.append(s, start, 1);
        compressed.append(std::to_string(i-start+1));
        i++;
    }
    return (s.length() < compressed.length()) ? s : compressed;
}

int main()
{
    string s = "jkjjjjjj";
    printf("%s\n", compress(s).c_str());
    return 0;
}
