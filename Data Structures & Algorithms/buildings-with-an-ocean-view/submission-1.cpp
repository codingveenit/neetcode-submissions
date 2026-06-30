// class Solution {
// public:
//     vector<int> findBuildings(vector<int>& heights) {
//         stack<int, vector<int>> st;
//         int n = heights.size();
//         for(int i = 0 ; i < n ;i++) {
//             while(!st.empty() && heights[st.top()] <= heights[i]) {
//                 st.pop();
//             }
//             st.push(i);
//         }

//         vector<int> ans;
//         while(!st.empty()) {
//             ans.push_back(st.top());
//             st.pop();
//         }

//         reverse(ans.begin(), ans.end());

//         return ans;
//     }
// };

class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {

        vector<int> ans;
        int maxHeight = 0;

        for (int i = heights.size() - 1; i >= 0; i--) {

            if (heights[i] > maxHeight) {
                ans.push_back(i);
                maxHeight = heights[i];
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};