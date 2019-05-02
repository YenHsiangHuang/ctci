// LC #22
#include <string>
#include <vector>
#include "printer.hpp"
void generateParenthesis(std::vector<std::string>& res, std::string s,
                         int leftRem, int rightRem) {
    if (leftRem == 0 && rightRem == 0) {
        res.push_back(s);
        return;
    }
    if (leftRem > 0)
        generateParenthesis(res, s + "(", leftRem - 1, rightRem);
    if (rightRem > leftRem)
        generateParenthesis(res, s + ")", leftRem, rightRem - 1);
}

std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> res;
    generateParenthesis(res, "", n, n);
    return res;
}

int main(int argc, const char* argv[]) {
    printVec(generateParenthesis(3));
    return 0;
}
