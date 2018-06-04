#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

void reverseString(string& s) {
    int n = s.length();
    for (int i = 0; i < n/2; i++) {
        char tmp = s[i];
        s[i] = s[n-i-1];
        s[n-i-1] = tmp;
    }
}

void reverseString(char c[]) {
    char* end = c;
    while (*end) end++;
    end--;

    while (end - c > 0) {
        char tmp = c[0];
        *c++ = *end;
        *end-- = tmp;
    }
}

int main()
{
    string s = "hello";
    cout << s << endl;
    reverseString(s);
    cout << s << endl;

    char c[] = "hello";
    cout << c << endl;
    reverseString(c);
    cout << c << endl;

    return 0;
}
