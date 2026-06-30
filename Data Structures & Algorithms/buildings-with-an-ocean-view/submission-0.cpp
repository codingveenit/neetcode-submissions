class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        stack<int, vector<int>> st;
        int n = heights.size();
        for(int i = 0 ; i < n ;i++) {
            while(!st.empty() && heights[st.top()] <= heights[i]) {
                st.pop();
            }
            st.push(i);
        }

        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};