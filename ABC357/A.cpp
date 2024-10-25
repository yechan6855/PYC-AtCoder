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
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

int main() {
    io;
    int N, M;
    cin >> N >> M;
    vector<int> H(N);
    for(int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    int solve = M;
    int count = 0;

    for(int i = 0; i < N; ++i) {
        if(solve >= H[i]) {
            solve -= H[i];
            count++;
        } else {
            break;
        }
    }

    cout << count << endl;

    return 0;
}