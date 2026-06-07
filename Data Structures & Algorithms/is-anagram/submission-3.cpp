// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if (s.size() != t.size()) return false;

//         unordered_map<char, int> mp;

//         for (char x : s) {
//             mp[x]++;
//         }

//         for (char x : t) {
//             mp[x]--;
//             if (mp[x] < 0) {
//                 return false;
//             }
//         }

//         return true;
//     }
// };

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        vector<int> freq(26, 0);

        for (char c : s) freq[c - 'a']++;
        for (char c : t) freq[c - 'a']--;

        for (int x : freq) {
            if (x != 0) return false;
        }

        return true;
    }
};