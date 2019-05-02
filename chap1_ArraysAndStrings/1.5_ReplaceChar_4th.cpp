#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

void replaceChar(string& s, string target, string source) {
    // This method is clean, though, it keep changing the string length
    size_t found = s.find(target);
    while (found != string::npos) {
        s.replace(found, target.length(), source);
        found = s.find(target, found+1);
    }

    // Try to do it with only one length change?
}

int main()
{
    string s = "How do you feel?";
    cout << s << endl;
    replaceChar(s, " ", "%20");
    cout << s << endl;
    return 0;
}
