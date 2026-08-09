#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v, bool direction)
    {
        // direction = 1 -> undirected graph
        // direction = 0 -> directed graph
        adjList[u].push_back(v);
        if (direction == 1)
        {
            adjList[v].push_back(u);
        }
    }

    void dfsTOPO(int src, stack<int> &st, unordered_map<int, bool> &vis)
    {
        vis[src] = 1;

        for (auto nbr : adjList[src])
        {
            if (!vis[nbr])
            {
                dfsTOPO(nbr, st, vis);
            }
        }
        st.push(src);
    }

    void dfs2(int src, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adjNew)
    {
        vis[src] = 1;
        cout << src << ",";

        for (auto nbr : adjNew[src])
        {
            if (!vis[nbr])
            {
                dfs2(nbr, vis, adjNew);
            }
        }
    }

    int countSCC(int n)
    {
        stack<int> st;
        unordered_map<int, bool> visited;

        // find topo ordering
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfsTOPO(i, st, visited);
            }
        }

        // reverse all edges
        unordered_map<int, list<int>> adjNew;
        for (auto t : adjList)
        {
            for (auto nbr : t.second)
            {
                int u = t.first;
                int v = nbr;
                // v->u insert
                adjNew[v].push_back(u);
            }
        }

        // traverse using dfs topo ordering
        int count = 0;
        unordered_map<int, bool> visited2;

        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            if (!visited2[node])
            {
                cout << "printing " << count + 1 << "th SCC : " << endl;
                dfs2(node, visited2, adjNew);
                cout << endl;
                count++;
            }
        }

        return count;
    }

    void findBridges(int src, int parent, int &timer, vector<int> &tin, vector<int> &low, unordered_map<int, bool> &vis)
    {
        vis[src] = 1;
        tin[src] = timer;
        low[src] = timer;
        timer++;

        for (auto nbr : adjList[src])
        {
            if (nbr == parent)
            {
                continue;
            }
            if (!vis[nbr])
            {
                // dfs call
                findBridges(nbr, src, timer, tin, low, vis);

                // low update
                low[src] = min(low[src], low[nbr]);

                // check for bridge
                if (low[nbr] > low[src])
                {
                    cout << nbr << "--" << src << " is a bridge" << endl;
                }
            }
            else
            {
                // node is visited and not a parent
                // low update
                low[src] = min(low[src], low[nbr]);
            }
        }
    }
};

int main()
{
    Graph g;

    // g.addEdge(0, 1, 0);
    // g.addEdge(1, 2, 0);
    // g.addEdge(2, 3, 0);
    // g.addEdge(3, 1, 0);
    // g.addEdge(2, 4, 0);
    // g.addEdge(4, 5, 0);
    // g.addEdge(5, 6, 0);
    // g.addEdge(6, 7, 0);
    // g.addEdge(6, 4, 0);

    // int ans = g.countSCC(8);

    // cout << "No of strongly connected components are : " << ans << endl;

    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(0, 3, 1);
    g.addEdge(3, 4, 1);

    int n = 5;
    int timer = 0;
    vector<int> tin(n);
    vector<int> low(n);
    unordered_map<int, bool> vis;
    g.findBridges(0, -1, timer, tin, low, vis);

    return 0;
}