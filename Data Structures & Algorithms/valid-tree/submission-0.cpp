class DSU {
public:
    vector<int> parent;
    vector<int> size;

    DSU (int n) {
        parent.resize(n);
        size.resize(n, 1);
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

        if(size[u] < size[v]) swap(u, v);

        size[u] += size[v];
        parent[v] = u;
        return true;
    }
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        int m = edges.size();

        if(m != n - 1) return false;

        DSU dsu(n);

        for(auto e: edges) {
            if(!dsu.merge(e[0], e[1])) return false;
        }

        return true;
    }
};
