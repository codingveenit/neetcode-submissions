class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> mp;
        for(int i = 0 ; i < n; i++) {
            mp[nums[i]]++;
        }

        vector<vector<int>> bucket(n+1);

        for(auto c: mp) {
            bucket[c.second].push_back(c.first);
        }

        for(int i = n ; i >= 1 ; i--) {
            for(auto num : bucket[i]) {
                ans.push_back(num);
                if(ans.size() == k) return ans;
            }
        }
        
    }
};
