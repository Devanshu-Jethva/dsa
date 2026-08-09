#include <iostream>
#include <list>
#include <queue>
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

    bool checkCycleUsingBfs(int src, unordered_map<int, bool>& visited) {
        queue<int> q;
        unordered_map<int, int> parent;

        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while (!q.empty()) {
            int frontNode = q.front();
            q.pop();

            for (auto nbr : adjList[frontNode]) {
                if (!visited[nbr]) {
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = frontNode;
                } else {
                    // already visited
                    if (parent[frontNode] != nbr) {
                        // nbr is not parent of the node we are processing &&
                        // already visited -> cycle
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool checkCycleUsingDfs(int src, unordered_map<int, bool>& visited,
                            int parent) {
        visited[src] = true;

        for (auto nbr : adjList[src]) {
            if (!visited[nbr]) {
                bool checkAagekaAns = checkCycleUsingDfs(nbr, visited, src);
                if (checkAagekaAns) {
                    return true;
                }
            } else {
                // nbr is visited
                if (nbr != parent) {
                    // nbr is not parent && already visited -> cycle
                    return true;
                }
            }
        }
        return false;
    }

    bool chechCyclicDirectedGraphUsingDfs(
        int src, unordered_map<int, bool>& visited,
        unordered_map<int, bool>& dfsVisited) {
        visited[src] = true;
        dfsVisited[src] = true;

        for (auto nbr : adjList[src]) {
            if (!visited[nbr]) {
                bool aageKaAns =
                    chechCyclicDirectedGraphUsingDfs(nbr, visited, dfsVisited);
                if (aageKaAns) {
                    return aageKaAns;
                }
            } else if (dfsVisited[nbr]) {
                // nbr is not parent && already visited -> cycle
                return true;
            }
        }
        // yahi pe fasega tu
        dfsVisited[src] = false;
        return false;
    }
};

int main() {
    Graph<int> g;
    // n -> number of nodes in graph
    int n = 3;
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(0, 2, 0);

    // g.addEdge(0, 1, 0);
    // g.addEdge(1, 2, 0);
    // g.addEdge(2, 3, 0);
    // g.addEdge(3, 4, 0);
    // g.addEdge(4, 0, 0);
    g.printAdjList();

    unordered_map<int, bool> visitedbfs;
    // run a loop for all nodes
    bool ansBfs = false;
    for (int i = 0; i < n; i++) {
        if (!visitedbfs[i]) {
            ansBfs = g.checkCycleUsingBfs(i, visitedbfs);
        }
        if (ansBfs) {
            break;
        }
    }
    if (ansBfs) {
        cout << "cycle is present" << endl;
    } else {
        cout << "cycle is not present" << endl;
    }

    unordered_map<int, bool> visitedDfs;
    // run a loop for all nodes
    bool ansDfs = false;
    for (int i = 0; i < n; i++) {
        if (!visitedDfs[i]) {
            ansDfs = g.checkCycleUsingDfs(i, visitedDfs, -1);
        }
        if (ansDfs == true) {
            break;
        }
    }
    if (ansDfs == true) {
        cout << "cycle is present" << endl;
    } else {
        cout << "cycle is not present" << endl;
    }

    /*

    Graph<int> g;
    int n = 5;
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);

    bool ans = false;
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            ans = g.chechCyclicDirectedGraphUsingDfs(i, visited, dfsVisited);
            if (ans == true)
                break;
        }
    }
    if (ans == true)
    {
        cout << "cycle is present" << endl;
    }
    else
    {
        cout << "cycle is not present" << endl;
    }
    */

    return 0;
}
