#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;
template <typename T>

class Graph
{
public:
    unordered_map<T, list<T>> adjList;
    // unordered_map<T, list<pair<T,int>>> adjList; // for weighted graph

    void addEdge(T u, T v, bool direction)
    {
        // direction = 0 -> undirected graph
        // direction = 1 -> directed graph
        // create an adge from u to v
        adjList[u].push_back(v);
        if (direction == 0)
        {
            // undirected edge
            // create an adge from v to u
            adjList[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for (auto node : adjList)
        {
            cout << node.first << " -> ";
            for (auto neighbour : node.second)
            {
                cout << neighbour << ", ";
            }
            cout << endl;
        }
    }

    void bfs(T src, unordered_map<T, bool> &visited)
    {
        queue<T> q;

        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            T frontNode = q.front();
            q.pop();
            cout << frontNode << ", ";

            // insert neighbours
            for (auto neighbour : adjList[frontNode])
            {
                if (!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }

    void dfs(T src, unordered_map<T, bool> &visited)
    {
        cout << src << ", ";
        visited[src] = true;

        for (auto neighbour : adjList[src])
        {
            if (!visited[neighbour])
            {
                dfs(neighbour, visited);
            }
        }
    }
};

int main()
{
    Graph<int> g;
    // n -> number of nodes in graph
    int n = 5;
    g.addEdge(0, 1, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(0, 2, 0);
    g.addEdge(2, 4, 0);
    g.printAdjList();
    // g.bfs(0);

    unordered_map<int, bool> visited;
    // run a loop for all nodes
    cout << "printing BFS Traversal : " << endl;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.bfs(i, visited);
        }
    }

    unordered_map<int, bool> visited2;
    cout << endl
         << "printing DFS Traversal : " << endl;
    for (int i = 0; i < n; i++)
    {
        if (!visited2[i])
        {
            g.dfs(i, visited2);
        }
    }

    // Graph<char> g;
    // g.addEdge('a', 'b', 0);
    // g.addEdge('b', 'c', 0);
    // g.addEdge('c', 'a', 0);
    // g.printAdjList();

    /*
    // Graph<int> g;
    // g.addEdge(srcNode, destNode, weight, direction);


    // undirected edge input
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(0, 2, 0);
    cout << endl;

    g.printAdjList();


    // directed edge input
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(0, 2, 1);
    cout << endl;

    g.printAdjList();
    */

    /*
    int n;
    cout << "enter no of nodes : ";
    cin >> n;

    vector<vector<int>> adj(n, vector<int>(n, 0));

    int e;
    cout << "enter no of edges : ";
    cin >> e;

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
    }

    // printing
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    */

    return 0;
}
