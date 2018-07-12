// LC #344
#include <iostream>
#include <string>

void reverseString(char* s) {
    if (!s) return;

    char* end = s;
    while (*end) ++end;
    --end;

    while (s < end) std::swap(*s++, *end--);
}

std::string reverseString(std::string s) {
    int n = s.length();
    for (int i = 0; i < n / 2; i++) std::swap(s[i], s[n - i - 1]);
    return s;
}

int main() {
    std::string s = "desire";
    reverseString(s);
    std::cout << s << std::endl;
    char c[] = "desire";
    reverseString(c);
    std::cout << c << std::endl;
    return 0;
}
