class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hmap;
        for (auto s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            hmap[key].push_back(s);
        }

        vector<vector<string>> ans;

        for (auto it : hmap) {
            ans.push_back(it.second);
        }

        return ans;
    }
};
