#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;

    vector<int> parent(N + 1);
    vector<vector<int>> top10(N + 1, vector<int>());

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        top10[i].push_back(i);
    }

    function<int(int)> find_set = [&](int x) -> int {
        return parent[x] == x ? x : parent[x] = find_set(parent[x]);
    };

    for (int i = 0; i < Q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int u, v;
            cin >> u >> v;
            int pu = find_set(u);
            int pv = find_set(v);

            if (pu != pv) {
                if (top10[pu].size() < top10[pv].size()) {
                    swap(pu, pv);
                }
                parent[pv] = pu;

                vector<int> merged;
                int p1 = 0, p2 = 0;
                while (p1 < top10[pu].size() && p2 < top10[pv].size() && merged.size() < 10) {
                    if (top10[pu][p1] > top10[pv][p2]) {
                        merged.push_back(top10[pu][p1++]);
                    } else {
                        merged.push_back(top10[pv][p2++]);
                    }
                }
                while (p1 < top10[pu].size() && merged.size() < 10) {
                    merged.push_back(top10[pu][p1++]);
                }
                while (p2 < top10[pv].size() && merged.size() < 10) {
                    merged.push_back(top10[pv][p2++]);
                }
                top10[pu] = merged;
            }
        } else {
            int v, k;
            cin >> v >> k;
            int pv = find_set(v);
            if (top10[pv].size() >= k) {
                cout << top10[pv][k - 1] << "\n";
            } else {
                cout << "-1\n";
            }
        }
    }
}