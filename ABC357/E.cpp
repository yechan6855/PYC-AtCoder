#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int, int>
#define mi map<int, int>
#define qi queue<int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define endl "\n"
#define elif else if
#define MOD 998244353
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int main() {
    io;
    int N;
    cin >> N;

    vi a(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
    }

    vi visited(N + 1, 0);
    vi in_cycle(N + 1, 0);
    vi cnt(N + 1, 0);

    for (int i = 1; i <= N; ++i) {
        if (visited[i]) continue;

        vi path;
        int cur = i;

        while (!visited[cur]) {
            visited[cur] = 1;
            path.pb(cur);
            cur = a[cur];
        }

        bool inCycle = false;
        for (int j = 0; j < path.size(); ++j) {
            if (path[j] == cur) {
                inCycle = true;
                for (int k = j; k < path.size(); ++k) {
                    in_cycle[path[k]] = 1;
                }
                break;
            }
        }

        if (!inCycle) continue;

        for (int j = 0; j < path.size(); ++j) {
            if (in_cycle[path[j]]) {
                int count = 0;
                for (int k = j; k < path.size(); ++k) {
                    cnt[path[k]] = path.size() - j;
                    count++;
                }
                break;
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i <= N; ++i) {
        if (in_cycle[i]) {
            ans += cnt[i];
        } else {
            int count = 0;
            int cur = i;
            while (!in_cycle[cur]) {
                count++;
                cur = a[cur];
            }
            ans += count + cnt[cur];
        }
    }

    cout << ans << endl;
    return 0;
}