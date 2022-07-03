#include <string>
using std::string;

#include <unordered_map>
#include <array>
#include <random>

class Solution {
    inline static const string prefix = "https://tinurl.com/";

    std::unordered_map<string, string> map;
    static std::default_random_engine engine;
    constexpr static std::array<char, 62> chars{
        {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm','n', 'o', 'p', 'q', 'r', 's', 't', 'u', 
         'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L','M', 'N', 'O', 'P', 
         'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}};

    string findHash() {
        std::uniform_int_distribution<int> dis(0, 61);
        std::string res;
        for (int i = 0;i < 5;++i) {
            res.push_back(chars[dis(engine)]);
        }
        return res;
    }

    string findSuffix() {
        string res = findHash();
        while (map.find(res) != map.end()) {
            res = findHash();
        }
        return res;
    }
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string suffix = findSuffix();
        map[suffix] = longUrl;
        return prefix + suffix;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        std::size_t i = shortUrl.find_last_of('/', shortUrl.size());
        string key = shortUrl.substr(i + 1);
        return map[key];
    }
};