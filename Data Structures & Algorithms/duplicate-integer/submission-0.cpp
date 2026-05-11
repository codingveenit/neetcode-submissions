class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> arr;
        for (int i = 0; i<nums.size();i++) {
            if (arr[nums[i]] == 1) {
                return true;
            }

            arr[nums[i]] = 1;
        }
        return false;
        
    }
};