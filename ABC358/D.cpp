#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define pii pair<int,int>
#define mi map<int,int>
#define qi queue<int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define tiii tuple<int,int,int>
#define endl "\n"
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

int main() {
    io;
    int N, M;
    cin >> N >> M;
    vi A(N), B(M);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    priority_queue<int, vi, greater<int>> pq;
    int j = 0;
    ll total = 0;

    for (int i = 0; i < M; i++) {
        while (j < N && A[j] < B[i]) {
            j++;
        }

        if (j == N) {
            cout << -1 << endl;
            return 0;
        }

        total += A[j];
        j++;
    }

    cout << total << endl;
    return 0;
}