#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> B(N);
    for(int i=0; i<N; i++) {
        cin >> A[i] >> B[i];
    }

    ll total_strength = 0;
    for(auto b : B) total_strength += b;

    if(total_strength % 3 != 0){
        cout << "-1";
        return 0;
    }

    ll T = total_strength / 3;

    ll S1 = 0, S2 = 0, S3 = 0;
    for(int i=0; i<N; i++){
        if(A[i] == 1) S1 += B[i];
        else if(A[i] == 2) S2 += B[i];
        else S3 += B[i];
    }

    ll D1 = S1 - T;
    ll D2 = S2 - T;
    ll D3 = S3 - T;

    if(D1 ==0 && D2 ==0 && D3 ==0){
        cout << "0";
        return 0;
    }

    vector<vector<int>> DP(T+1, vector<int>(T+1, -1));
    DP[0][0] = 0;

    for(int i=0; i<N; i++){
        vector<vector<int>> nextDP(T+1, vector<int>(T+1, -1));
        for(int s1=0; s1<=T; s1++){
            for(int s2=0; s2<=T; s2++){
                if(DP[s1][s2] == -1) continue;

                if(s1 + B[i] <= T){
                    int kept = DP[s1][s2];
                    if(A[i] == 1) kept +=1;
                    nextDP[s1 + B[i]][s2] = max(nextDP[s1 + B[i]][s2], kept);
                }

                if(s2 + B[i] <= T){
                    int kept = DP[s1][s2];
                    if(A[i] == 2) kept +=1;
                    nextDP[s1][s2 + B[i]] = max(nextDP[s1][s2 + B[i]], kept);
                }

                int kept = DP[s1][s2];
                if(A[i] == 3) kept +=1;
                nextDP[s1][s2] = max(nextDP[s1][s2], kept);
            }
        }
        DP = move(nextDP);
    }

    if(DP[T][T] != -1){
        cout << (N - DP[T][T]);
    }
    else{
        cout << "-1";
    }
}