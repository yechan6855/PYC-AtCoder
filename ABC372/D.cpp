#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> H(N);
    for (auto &x : H) cin >> x;

    vector<int> last_greater(N, -1);
    stack<int> s;
    for (int j = 0; j < N; j++) {
        while (!s.empty() && H[s.top()] <= H[j]) s.pop();
        last_greater[j] = s.empty() ? -1 : s.top();
        s.push(j);
    }

    vector<int> delta(N + 1, 0);
    for (int j = 0; j < N; j++) {
        int l = last_greater[j] == -1 ? 0 : last_greater[j];
        int r = j - 1;
        if (l <= r) {
            delta[l] += 1;
            delta[r + 1] -= 1;
        }
    }

    vector<int> c(N, 0);
    c[0] = delta[0];
    for (int i = 1; i < N; i++) c[i] = c[i-1] + delta[i];

    for (int i = 0; i < N; i++) {
        cout << c[i] << (i < N - 1 ? " " : "\n");
    }
}