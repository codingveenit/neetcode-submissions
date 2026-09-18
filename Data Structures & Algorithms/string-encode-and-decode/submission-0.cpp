class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;
        for(auto s: strs) {
            ans += to_string(s.size());
            ans += "#";
            ans += s;
        }

        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        while(i < s.size()) {
            int count = 0;
            while(s[i] != '#') {
                count *= 10;
                count += s[i++] - '0';
            }
            i++;
            string str;
            for(int j = i ; j < i + count; j++) {
                str += s[j];
            }
            ans.push_back(str);
            i += count;
        }

        return ans;
    }
};
