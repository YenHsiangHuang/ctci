// The logic is pretty tricky. I would try more to get familiar with it.

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void removeDupChars(char c[]) {
    if (!(*c)) return;  // null array, return
    if (!(*(c+1))) return;  // single char, return

    int tail = 1;
    for (int i = 1; c[i]; i++) {
        int j;
        for (j = 0; j < tail; j++) {
            if (c[i] == c[j]) break;
        }
        if (j == tail) {
            c[tail] = c[i];
            tail++;
        }
    }
    c[tail] = 0;
}

int main()
{
    char a[] = "abcd", b[] = "abababaab", c[] = "aaaabbbb", d[] = "aaaaaa", e[] = "k", f[] = "";
    vector<char*> cvec = {a, b, c, d, e, f};

    for (auto &s : cvec) {
        cout << s << " | ";
        removeDupChars(s);
        cout << s << endl;
    }

    return 0;
}
