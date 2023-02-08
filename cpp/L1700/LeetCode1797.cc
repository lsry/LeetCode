#include <unordered_map>
#include <string>
using std::string;

class AuthenticationManager {
    int liveTime;
    std::unordered_map<string, int> map;
public:
    AuthenticationManager(int timeToLive): liveTime(timeToLive) {}
    
    void generate(string tokenId, int currentTime) {
        map[tokenId] = currentTime + liveTime;
    }
    
    void renew(string tokenId, int currentTime) {
        auto it{map.find(tokenId)};
        if (it == map.end()) {
            return;
        }
        if (it->second > currentTime) {
            it->second = currentTime + liveTime;
        } else {
            map.erase(it);
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int ans{0};
        for (auto &[id, time] : map) {
            if (time > currentTime) {
                ++ans;
            }
        }
        return ans;
    }
};