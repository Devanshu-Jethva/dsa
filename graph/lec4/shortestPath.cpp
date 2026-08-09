#include <bits/stdc++.h>
using namespace std;

class Graph {
   public:
    unordered_map<int, list<pair<int, int>>> adjList;

    void addEdge(int u, int v, int wt, bool direction) {
        // direction = 1 -> undirected graph
        // direction = 0 -> directed graph
        adjList[u].push_back({v, wt});
        if (direction == 1) {
            adjList[v].push_back({u, wt});
        }
    }

    void printAdjList() {
        for (auto i : adjList) {
            cout << i.first << " -> ";
            for (auto j : i.second) {
                cout << "(" << j.first << ", " << j.second << ")";
            }
            cout << endl;
        }
    }

    void shotestPathBfs(int src, int dest) {
        queue<int> q;
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;

        // initial step
        q.push(src);
        visited[src] = 1;
        parent[src] = -1;

        while (!q.empty()) {
            int fNode = q.front();
            q.pop();

            for (auto nbr : adjList[fNode]) {
                if (!visited[nbr.first]) {
                    q.push(nbr.first);
                    visited[nbr.first] = 1;
                    parent[nbr.first] = fNode;
                }
            }
        }

        // store path in ans, after traversing in the parent array
        vector<int> ans;
        int node = dest;
        while (node != -1) {
            ans.push_back(node);
            node = parent[node];
        }

        reverse(ans.begin(), ans.end());

        cout << "printing ans : " << endl;
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }

    void topologicalSortDfs(int src, unordered_map<int, bool> &visited,
                            stack<int> &ans) {
        visited[src] = true;

        for (auto nbr : adjList[src]) {
            int element = nbr.first;
            int weight = nbr.second;
            if (!visited[element]) {
                topologicalSortDfs(element, visited, ans);
            }
        }

        // while returning, store the node in stack
        ans.push(src);
    }

    void shotestPathDfs(int dest, stack<int> topoOrder, int n) {
        vector<int> dist(n, INT_MAX);

        int src = topoOrder.top();
        topoOrder.pop();
        dist[src] = 0;
        for (auto nbr : adjList[0]) {
            if (dist[0] + nbr.second < dist[nbr.first]) {
                dist[nbr.first] = dist[0] + nbr.second;
            }
        }

        while (!topoOrder.empty()) {
            int topEle = topoOrder.top();
            topoOrder.pop();

            if (dist[topEle] != INT_MAX) {
                for (auto nbr : adjList[topEle]) {
                    if (dist[topEle] + nbr.second < dist[nbr.first]) {
                        dist[nbr.first] = dist[topEle] + nbr.second;
                    }
                }
            }
        }

        cout << "printing :" << endl;
        for (int i = 0; i < n; i++) {
            cout << i << "-> " << dist[i] << endl;
        }
    }

    void shortestDistanceDijkstra(int src, int n) {
        vector<int> dist(n, INT_MAX);
        set<pair<int, int>>
            st;  // pair -> dist, node -> because dist k hisab se sorted chahiye

        // initial steps
        dist[src] = 0;
        st.insert({0, src});

        while (!st.empty()) {
            // fetch the smallest or first element from set
            auto topEle = *(st.begin());
            int nodeDistance = topEle.first;
            int node = topEle.second;

            // pop from set
            st.erase(st.begin());

            // neighbour traverse
            for (auto nbr : adjList[node]) {
                if (nodeDistance + nbr.second < dist[nbr.first]) {
                    // mujhe distance update karna hai
                    // finding entry in set
                    auto result = st.find({dist[nbr.first], nbr.first});
                    // if found then remove
                    if (result != st.end()) {
                        st.erase(result);
                    }
                    // updation in distance and set
                    dist[nbr.first] = nodeDistance + nbr.second;
                    st.insert(make_pair(dist[nbr.first], nbr.first));
                }
            }
        }

        for (int i = 0; i < dist.size(); i++) {
            cout << i << " -> " << dist[i] << endl;
        }
    }
};

int main() {
    Graph g;
    g.printAdjList();

    g.addEdge(0, 1, 5, 0);
    g.addEdge(0, 2, 6, 0);
    g.addEdge(2, 1, -3, 0);

    g.shortestDistanceDijkstra(0, 3);

    // g.addEdge(6, 3, 2, 1);
    // g.addEdge(6, 1, 14, 1);
    // g.addEdge(3, 1, 9, 1);
    // g.addEdge(3, 2, 10, 1);
    // g.addEdge(1, 2, 7, 1);
    // g.addEdge(2, 4, 15, 1);
    // g.addEdge(4, 3, 11, 1);
    // g.addEdge(6, 5, 9, 1);
    // g.addEdge(4, 5, 6, 1);

    // g.shortestDistanceDijkstra(6, 7);

    // g.addEdge(0, 1, 5, 0);
    // g.addEdge(0, 2, 3, 0);
    // g.addEdge(1, 3, 3, 0);
    // g.addEdge(2, 1, 2, 0);
    // g.addEdge(2, 3, 5, 0);
    // g.addEdge(2, 4, 6, 0);
    // g.addEdge(4, 3, 1, 0);
    // stack<int> topoOrder;
    // unordered_map<int, bool> visited;
    // g.topologicalSortDfs(0, visited, topoOrder);
    // g.shotestPathDfs(3, topoOrder, 5);

    // int src = 0;
    // int dest = 4;
    // g.shotestPathBfs(src, dest);

    return 0;
}