#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;
template <typename T>

class Graph {
   public:
    unordered_map<T, list<T>> adjList;

    void addEdge(T u, T v, bool direction) {
        // direction = 0 -> undirected graph
        // direction = 1 -> directed graph
        // create an adge from u to v
        adjList[u].push_back(v);
        if (direction == 0) {
            // undirected edge
            // create an adge from v to u
            adjList[v].push_back(u);
        }
    }

    void printAdjList() {
        for (auto node : adjList) {
            cout << node.first << " -> ";
            for (auto neighbour : node.second) {
                cout << neighbour << ", ";
            }
            cout << endl;
        }
    }

    void topologicalSort(int src, unordered_map<int, bool> &visited,
                         stack<int> &ans) {
        visited[src] = true;

        for (auto neighbour : adjList[src]) {
            if (!visited[neighbour]) {
                topologicalSort(neighbour, visited, ans);
            }
        }

        // while returning, store the node in stack
        ans.push(src);
    }

    void topoSortBfs(int n, vector<int> &ans) {
        queue<int> q;
        unordered_map<int, int> indegree;

        // indegree calculate
        for (auto i : adjList) {
            int src = i.first;
            for (auto nbr : i.second) {
                indegree[nbr]++;
            }
        }

        // put all nodes inside queue, which has indegree = 0, for whole graph
        // this loop is running, so we will not require visited array
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // bfs logic
        while (!q.empty()) {
            int front = q.front();
            q.pop();

            ans.push_back(front);
            // or we can count++ for cycle detection

            for (auto nbr : adjList[front]) {
                indegree[nbr]--;
                // check for zero again
                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
    }
};

int main() {
    Graph<int> g;
    // n -> number of nodes in graph
    int n = 4;
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 1, 1);

    // g.addEdge(2, 4, 1);
    // g.addEdge(2, 5, 1);
    // g.addEdge(4, 6, 1);
    // g.addEdge(5, 3, 1);
    // g.addEdge(3, 7, 1);
    // g.addEdge(7, 0, 1);
    // g.addEdge(7, 1, 1);
    // g.addEdge(6, 7, 1);

    g.printAdjList();

    vector<int> ans;
    // connected or disconnected
    g.topoSortBfs(n, ans);

    if (ans.size() == n) {
        cout << "it is a valid topo sort (no cycle)" << endl;
    } else {
        cout << "cycle is present - invalid topo sort" << endl;
    }
    cout << endl << "printing topological sort using bfs" << endl;
    for (auto i : ans) {
        cout << i << " ";
    }

    /**
    unordered_map<int, bool> visited;
    stack<int> ans;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            g.topologicalSort(i, visited, ans);
        }
    }

    cout << "TOPO sort" << endl;
    while (!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
    }
    */

    return 0;
}
