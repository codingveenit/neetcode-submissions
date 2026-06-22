class DSU {
public:
    vector<int> parent;
    vector<int> size;

    DSU (int n) {
        parent.resize(n);
        size.resize(n,1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    bool merge(int u, int v) {
        u = find(u);
        v = find(v);
        if(u == v) return false;
        if(size[u] < size[v]) swap(u,v);
        size[u] += size[v];
        parent[v] = u;
        return true;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        int components = n;
        for(int i = 0 ; i < edges.size(); i++) {
            if(dsu.merge(edges[i][0], edges[i][1])) {
                components--;
            }
        }
        return components;
        // int ans = 0;
        // for(int i = 0 ; i < n ; i++) {
        //     if(i == dsu.find(i)) ans++;
        // }

        // return ans;
    }
};
