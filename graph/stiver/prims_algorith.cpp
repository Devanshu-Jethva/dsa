#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    int spanningTree(int V, unordered_map<int, vector<pair<int, int>>> &adj) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        vector<bool> visited(V, false);  // To track visited nodes.
        int totalWeight = 0;

        // Start from node 0
        pq.push({0, 0});  // {weight, node}

        while (!pq.empty()) {
            pair<int, int> top = pq.top();
            pq.pop();

            int weight = top.first;
            int node = top.second;

            // If the node is already visited, skip it
            if (visited[node]) continue;

            // Mark node as visited and add its weight to the MST sum
            visited[node] = true;
            totalWeight += weight;

            // Push all unvisited neighbours into the priority queue
            for (auto neighbour : adj[node]) {
                int neighbourNode = neighbour.first;
                int edgeWeight = neighbour.second;

                if (!visited[neighbourNode]) {
                    pq.push({edgeWeight, neighbourNode});
                }
            }
        }

        return totalWeight;
    }
};

// Test case
int main() {
    int V = 5;  // Number of vertices
    unordered_map<int, vector<pair<int, int>>> adj;

    // Adding edges to the adjacency list (undirected graph)
    adj[0] = {{1, 2}, {3, 6}};
    adj[1] = {{0, 2}, {2, 3}, {3, 8}, {4, 5}};
    adj[2] = {{1, 3}, {4, 7}};
    adj[3] = {{0, 6}, {1, 8}, {4, 9}};
    adj[4] = {{1, 5}, {2, 7}, {3, 9}};

    Solution sol;
    int mstWeight = sol.spanningTree(V, adj);

    cout << "Minimum Spanning Tree weight: " << mstWeight << endl;

    return 0;
}
