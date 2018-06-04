// Print out all permutations of a string
// (does not remove duplicate permutations)
#include <stdio.h>
#include <iostream>
#include <string>

using std::string;

void permutation(string s);
void permutation(string s, string prefix);



int main()
{
    string s = "hello";
    permutation(s);
}



void permutation(string s) {
    permutation(s, "");
}

void permutation(string s, string prefix) {
    static int cnt = 0;
    if (s.length() == 0) {
        printf("%5d: ", cnt++);
        printf("%s ", prefix.c_str());  // std::cout << prefix << " ";
        if (cnt % 10 == 0) printf("\n");
    } else {
        for (int i = 0; i < s.length(); i++) {
            string rem = s.substr(0, i) + s.substr(i+1);
            permutation(rem, prefix+s.at(i));
        }
    }
}
