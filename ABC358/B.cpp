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
    int N, A;
    cin >> N >> A;
    vi T(N);
    for(int i = 0; i < N; i++) {
        cin >> T[i];
    }

    vi finish_time(N);
    int current_time = 0;

    for(int i = 0; i < N; i++) {
        if (T[i] > current_time) {
            current_time = T[i];
        }
        current_time += A;
        finish_time[i] = current_time;
    }

    for(int i = 0; i < N; i++) {
        cout << finish_time[i] << endl;
    }

    return 0;
}