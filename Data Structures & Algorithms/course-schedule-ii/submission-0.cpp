class Solution {
public:
    bool dfs(int i, vector<vector<int>>& adj, vector<int>& state, vector<int>& ans) {
        state[i] = 1;
        for(auto x: adj[i]) {
            if(state[x] == 1) return true;
            if(state[x] == 0 && dfs(x, adj, state, ans)) return true;
        }
        ans.push_back(i);
        state[i] = 2;
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(numCourses);

        for (auto &p : prerequisites) {
            int course = p[0];
            int prereq = p[1];
            adj[prereq].push_back(course);
        }

        vector<int> state(n, 0);
        vector<int> ans;
        for(int i = 0 ; i < n ; i++) {
            if(state[i] == 0 && dfs(i,adj, state, ans)) {
                return {};
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;

    }
};
