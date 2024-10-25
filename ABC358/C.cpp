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
    vector<string> S(N);
    for(int i = 0; i < N; i++) {
        cin >> S[i];
    }

    int min_st = N;
    for(int mask = 1; mask < (1 << N); mask++) {
        vector<bool> flavor(M, false);
        int st = 0;
        for(int i = 0; i < N; i++) {
            if (mask & (1 << i)) {
                st++;
                for(int j = 0; j < M; j++) {
                    if (S[i][j] == 'o') {
                        flavor[j] = true;
                    }
                }
            }
        }

        bool all_fl = true;
        for(int j = 0; j < M; j++) {
            if (!flavor[j]) {
                all_fl = false;
                break;
            }
        }

        if (all_fl) {
            min_st = min(min_st, st);
        }
    }

    cout << min_st << endl;
    return 0;
}