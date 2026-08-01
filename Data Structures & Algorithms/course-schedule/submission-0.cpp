class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for(int i = 0 ; i < prerequisites.size() ; i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }

        vector<int> topo;

        queue<int> q;

        for(int i = 0 ; i < numCourses ; i++) {
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto child: adj[node]) {
                indegree[child]--;
                if(indegree[child] == 0) {
                    q.push(child);
                }
            }
        }

        if(topo.size() == numCourses) return true;
        return false;
    }
};
