# include <string>

std::string disemvowel(const std::string& str) {
    std::string vowels = "aeiouAEIOU";
    std::string word = str;
    for (int i = 0; i < word.length(); ++i) {
        if (vowels.find(word[i]) != std::string::npos) {
            word.erase(i, 1);
            --i;
        }
    }
    return word;
}