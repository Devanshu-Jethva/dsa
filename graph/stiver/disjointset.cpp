#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> rank, parent, size;

   public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }

        rank.resize(n + 1, 0);

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

int main() {
    // DisjointSet ds(7);
    // ds.unionByRank(1, 2);
    // ds.unionByRank(2, 3);
    // ds.unionByRank(4, 5);
    // ds.unionByRank(6, 7);
    // ds.unionByRank(5, 6);
    // // if 3 & 7 are in same component or not
    // if (ds.findUltimateParent(3) == ds.findUltimateParent(7)) {
    //     cout << "Yes";
    // } else {
    //     cout << "No";
    // }
    // cout << endl;
    // ds.unionByRank(3, 7);
    // // if 3 & 7 are in same component or not
    // if (ds.findUltimateParent(3) == ds.findUltimateParent(7)) {
    //     cout << "Yes";
    // } else {
    //     cout << "No";
    // }
    // cout << endl;

    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    // if 3 & 7 are in same component or not
    if (ds.findUltimateParent(3) == ds.findUltimateParent(7)) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    cout << endl;
    ds.unionBySize(3, 7);
    // if 3 & 7 are in same component or not
    if (ds.findUltimateParent(3) == ds.findUltimateParent(7)) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    cout << endl;

    return 0;
}