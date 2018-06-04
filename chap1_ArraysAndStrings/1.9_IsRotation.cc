#include <iostream>
#include <string>

using std::cout;
using std::string;

bool isRotation(string s1, string s2) {
    return ((s1+s1).find(s2) != string::npos);
}

int main()
{
    string s1 = "waterbottle", s2 = "terbottlewa";
    cout << isRotation(s1, s2);

    return 0;
}
