#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> rank, parent, size;

   public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }

        size.resize(n + 1, 1);
    }

    int findUltimateParent(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);
        if (ulp_u == ulp_v) {
            return;
        }
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
   public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<pair<int, pair<int, int>>> edges;

        // might stores but discarded by DisjointSet
        // wt, u, v
        // 1,  1, 2
        // 1,  2, 1
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                int nbr = it[0];
                int edgeWt = it[1];
                int node = i;

                edges.push_back({edgeWt, {node, nbr}});
            }
        }

        sort(edges.begin(), edges.end());
        DisjointSet ds(V);
        int mstWt = 0;
        for (auto edge : edges) {
            int wt = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;

            if (ds.findUltimateParent(u) != ds.findUltimateParent(v)) {
                mstWt += wt;
                ds.unionBySize(u, v);
            }
        }
        return mstWt;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int V = 6;  // Number of vertices

    // Adjacency list representation of graph
    vector<vector<int>> adj[V + 1];

    // Graph edges (undirected)
    adj[1].push_back({5, 4});
    adj[1].push_back({2, 2});
    adj[1].push_back({4, 1});

    adj[2].push_back({1, 2});
    adj[2].push_back({4, 3});
    adj[2].push_back({3, 3});
    adj[2].push_back({6, 7});

    adj[3].push_back({4, 5});
    adj[3].push_back({2, 3});
    adj[3].push_back({6, 8});

    adj[4].push_back({5, 9});
    adj[4].push_back({1, 1});
    adj[4].push_back({2, 3});
    adj[4].push_back({3, 5});

    adj[5].push_back({1, 4});
    adj[5].push_back({4, 9});

    adj[6].push_back({2, 8});
    adj[6].push_back({3, 7});

    Solution sol;
    int mstWeight = sol.spanningTree(V, adj);
    cout << "Weight of the Minimum Spanning Tree: " << mstWeight << endl;

    return 0;
}