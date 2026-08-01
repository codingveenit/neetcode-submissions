// class Solution {
// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         vector<vector<int>> adj(numCourses);
//         vector<int> indegree(numCourses, 0);
//         for(int i = 0 ; i < prerequisites.size() ; i++) {
//             adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
//             indegree[prerequisites[i][0]]++;
//         }

//         vector<int> topo;

//         queue<int> q;

//         for(int i = 0 ; i < numCourses ; i++) {
//             if(indegree[i] == 0) q.push(i);
//         }

//         while(!q.empty()) {
//             auto node = q.front();
//             q.pop();
//             topo.push_back(node);
//             for(auto child: adj[node]) {
//                 indegree[child]--;
//                 if(indegree[child] == 0) {
//                     q.push(child);
//                 }
//             }
//         }

//         if(topo.size() == numCourses) return true;
//         return false;
//     }
// };


class Solution {
public:
    bool dfs(int i, vector<vector<int>>& adj, vector<int>& state) {
        state[i] = 1;
        for(auto child: adj[i]) {
            if(state[child] == 1) return true;
            if(dfs(child, adj, state)) return true;
        }

        state[i] = 2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i = 0 ; i < prerequisites.size() ; i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int> state(numCourses, 0);

        for(int i = 0 ; i < numCourses ; i++) {
            if(dfs(i, adj, state)) return false;
        }
        return true;
    }
};
