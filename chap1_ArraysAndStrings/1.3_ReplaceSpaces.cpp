// Input:  "Mr Black Smith    ", 13 <- true length of string
// Output: "Mr%20Black%20Smith"
#include <stdio.h>
#include <string>

void replaceSpaces(char s[], int len) {
    if (len == 0) return;
    int numSpace = 0;
    int i = 0;
    for (i = 0; i < len; i++) {
        if (s[i] == ' ') numSpace++;
    }
    i = len + numSpace*2 - 1;

    for (int cIdx = len-1; cIdx >= 0; cIdx--) {
        if (s[cIdx] != ' ') {
            s[i] = s[cIdx];
            i--;
        } else {
            s[i] = '0';
            s[i-1] = '2';
            s[i-2] = '%';
            i -= 3;
        }
    }
}


int main()
{
    char a[] = "Mr Black Smith    ";
    printf("%s\n", a);
    replaceSpaces(a, 14);
    printf("%s\n", a);

    char b[] = "a pp l e      ";
    printf("%s\n", b);
    replaceSpaces(b, 8);
    printf("%s\n", b);

    return 0;
}
