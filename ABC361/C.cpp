#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define endl "\n"

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());
    
    ll min_diff = A[N-1] - A[0];
    for (int i = 0; i <= K; i++) {
        min_diff = min(min_diff, A[N-1-K+i] - A[i]);
    }

    cout << min_diff << endl;

    return 0;
}