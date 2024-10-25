#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define endl "\n"
using namespace std;

const int MAX_N = 2e5 + 5;
vector<pair<int, int>> graph[MAX_N];
ll tot = 0;
int farthest_node;
ll Max;

void dfs(int node, int parent, ll distance) {
    if (distance > Max) {
        Max = distance;
        farthest_node = node;
    }

    for (auto& edge : graph[node]) {
        int next_node = edge.first;
        int weight = edge.second;
        if (next_node != parent) {
            dfs(next_node, node, distance + weight);
        }
    }
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        graph[A].push_back({B, C});
        graph[B].push_back({A, C});
        tot += C;
    }

    Max = -1;
    dfs(1, 0, 0);

    Max = -1;
    dfs(farthest_node, 0, 0);

    cout << 2 * tot - Max << endl;

    return 0;
}