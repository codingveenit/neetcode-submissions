class Solution {
public:
    bool isAnagram(string s, string t) {

        unordered_map<int,int> str;
        for (auto x : s) {
            str[x - 'a']++;
        }

        for (auto x : t) {
            str[x - 'a']--;
        }

        for (auto x: str) {
            if (x.second > 0 || x.second < 0) return false;
        }

        return true;

        
        
    }
};
