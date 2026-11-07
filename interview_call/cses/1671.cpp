#include <bits/stdc++.h>
using namespace std;

vector<long long> shortestDistanceDijkstra(
    vector<vector<pair<long long, long long>>> adjList, long long src,
    long long n) {
    vector<long long> dist(n, LLONG_MAX);

    priority_queue<pair<long long, long long>,
                   vector<pair<long long, long long>>,
                   greater<pair<long long, long long>>>
        pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto topEle = pq.top();

        long long nodeDistance = topEle.first;
        long long node = topEle.second;

        pq.pop();

        // Skip outdated entries
        if (nodeDistance > dist[node]) {
            continue;
        }
        for (auto& nbr : adjList[node]) {
            long long newDistance = nodeDistance + nbr.second;
            long long nbrNode = nbr.first;

            if (newDistance < dist[nbrNode]) {
                dist[nbrNode] = newDistance;
                pq.push({newDistance, nbrNode});
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;

    vector<vector<pair<long long, long long>>> adjList(n);

    while (m--) {
        long long u, v, w;
        cin >> u >> v >> w;

        adjList[u - 1].push_back({v - 1, w});
    }

    vector<long long> dist = shortestDistanceDijkstra(adjList, 0, n);

    for (auto it : dist) {
        cout << (it == LLONG_MAX ? -1 : it) << " ";
    }

    cout << '\n';

    return 0;
}