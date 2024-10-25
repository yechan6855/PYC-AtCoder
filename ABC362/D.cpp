#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

const long long INF = 1e18;

struct Edge {
    int to;
    long long weight;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<long long> A(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }

    vector<vector<Edge>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long b;
        cin >> u >> v >> b;
        graph[u].push_back({v, b});
        graph[v].push_back({u, b});
    }

    vector<long long> dist(n + 1, INF);
    dist[1] = A[1];

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({A[1], 1});

    while (!pq.empty()) {
        auto [current_dist, u] = pq.top();
        pq.pop();
        if (current_dist > dist[u]) continue;

        for (auto& edge : graph[u]) {
            int v = edge.to;
            long long weight = edge.weight;
            long long new_dist = dist[u] + A[v] + weight;

            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({new_dist, v});
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}