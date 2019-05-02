// LC #49
#include <string>
#include <unordered_map>
#include <vector>
#include "printer.hpp"

/**
   There are two ways to find out a anagram:
     1. Histogram
     2. Sort
   Sort is faster in this case because all words are short enough.
 */
std::vector<std::vector<std::string>> groupAnagrams(
    std::vector<std::string>& strs) {
    int id = 0;
    std::unordered_map<std::string, int> table;  // string, id
    std::vector<std::vector<std::string>> res;

    for (auto& s : strs) {
        auto tmp = s;
        sort(tmp.begin(), tmp.end());
        auto idx = table.find(tmp);
        if (idx != table.end()) {
            res[idx->second].push_back(s);
        } else {
            res.push_back(std::vector<std::string>{s});
            table[tmp] = id++;
        }
    }

    return res;
}

std::vector<std::vector<std::string>> groupAnagrams(
    std::vector<std::string>&& strs) {
    return groupAnagrams(strs);
}

int main(int argc, const char* argv[]) {
    std::vector<std::string> test = {"eat", "tea", "tan", "ate", "nat", "bat"};
    printVec2(groupAnagrams(test));
    return 0;
}
