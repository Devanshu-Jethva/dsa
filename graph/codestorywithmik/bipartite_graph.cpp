#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool colorTheComponentBfs(vector<int>& color, vector<vector<int>>& graph,
                              int src) {
        color[src] = 0;

        queue<int> q;
        q.push(src);

        while (!q.empty()) {
            int front = q.front();
            q.pop();

            for (auto nbr : graph[front]) {
                if (color[nbr] == -1) {
                    color[nbr] = !color[front];
                    q.push(nbr);
                }
                // if nbr is already colored, we will check if nbr is colored
                // with same color or not
                else if (color[nbr] == color[front]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool colorTheComponentDfs(vector<int>& color, vector<vector<int>>& graph,
                              int src, int currColor) {
        color[src] = currColor;

        for (int nbr : graph[src]) {
            if (color[nbr] == -1) {
                bool future =
                    colorTheComponentDfs(color, graph, nbr, !currColor);
                if (!future) {
                    return future;
                }
            }
            // if nbr is already colored, we will check if nbr is colored with
            // same color or not
            else if (color[nbr] == color[src]) {
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);  // -1 means not colored yet, we will try to
                                   // color with either 0 or 1
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                // bool ans = colorTheComponentBfs(color, graph, i);
                bool ans = colorTheComponentDfs(color, graph, i, 0);
                if (ans == false) {
                    return ans;
                }
            }
        }
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 4;

    // Create an undirected graph
    vector<vector<int>> graph(n);

    // Edges: 0-1, 1-2, 2-3, 3-0
    graph[0].push_back(1);
    graph[1].push_back(0);

    graph[1].push_back(2);
    graph[2].push_back(1);

    graph[2].push_back(3);
    graph[3].push_back(2);

    graph[3].push_back(0);
    graph[0].push_back(3);

    // =============
    // graph[0].push_back(1);
    // graph[1].push_back(0);

    // graph[1].push_back(2);
    // graph[2].push_back(1);

    // graph[2].push_back(0);
    // graph[0].push_back(2);

    Solution obj;

    if (obj.isBipartite(graph)) {
        cout << "Graph is Bipartite" << endl;
    } else {
        cout << "Graph is NOT Bipartite" << endl;
    }

    return 0;
}