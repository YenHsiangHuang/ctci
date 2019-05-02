#include <stdio.h>
#include <string>
#include <cmath>

using std::string;

// Check if s2 can be obtained by edit only one char in s1
bool isEdit(string s1, string s2) {
    bool diff = false;
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] != s2[i]) {
            if (diff == true) {
                return false;
            }
            diff = true;
        }
    }
    return (diff == true) ? true : false;
}

// Check if s2 can be obtained by inserting only one char into s1
bool isInsert(string s1, string s2) {
    bool diff = false;
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] != s2[i]) {
            return !isEdit(s1.substr(i), s2.substr(i+1));
        }
    }
    return (diff == true) ? true : false;
}

bool isOneEditAway(string s1, string s2) {
    switch ((int)s1.length() - (int)s2.length()) {
        case  0:  // equal length
            return isEdit(s1, s2);
            break;
        case -1:  // s1 is shorter
            return isInsert(s1, s2);
            break;
        case  1:  // s1 is longer
            return isInsert(s2, s1);
            break;
        default:
            return false;
    }
}

int main()
{
    string s1 = "pale", s2 = "paele";
    printf("%d\n", isOneEditAway(s1, s2));

    s1 = "pale", s2 = "ple";
    printf("%d\n", isOneEditAway(s1, s2));

    s1 = "pale", s2 = "pake";
    printf("%d\n", isOneEditAway(s1, s2));

    s1 = "pale", s2 = "bake";
    printf("%d\n", isOneEditAway(s1, s2));
    return 0;
}
