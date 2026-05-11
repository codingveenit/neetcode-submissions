class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> arr;

        for (int i = 0; i < nums.size(); i++) {
            arr[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {

            int y = target - nums[i];

            if (arr[y] > 0 && arr[y] != i) {
                return {i, arr[y]};
            }
        }

        return {};
    }
};