#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

// It's okey if there will be only one request.
int getFrequency(std::vector<std::string>& book, std::string word) {
    int cnt = 0;
    for (auto& w : book) if (w == word) ++cnt;
    return cnt;
}

namespace string {
inline std::string tolower(std::string w) {
    std::transform(w.begin(), w.end(), w.begin(), ::tolower);
    return std::move(w);
}
}  // namespace string

std::unordered_map<std::string, int> buildDictionary(std::vector<std::string>& book) {
    static std::unordered_map<std::string, int> dict;
    if (dict.empty()) {
        dict.reserve(book.size() / 2);
        for (auto& w : book) ++dict[string::tolower(w)];
    }
    return dict;
}

int getFrequency(std::unordered_map<std::string, int>& dict, std::string word) {
    return dict[string::tolower(word)];
}

int main(int argc, const char *argv[]) {
    std::vector<std::string> book = {"I", "want", "to", "live", "twice"};
    auto dict = buildDictionary(book);
    std::cout << getFrequency(dict, "I") << std::endl;
    std::cout << getFrequency(dict, "i") << std::endl;
    std::cout << getFrequency(dict, "hey") << std::endl;
    return 0;
}
