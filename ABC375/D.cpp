#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;
    int n = S.size();

    vector<vector<int>> char_positions(26, vector<int>());

    for(int i=0; i<n; i++){
        char c = S[i];
        char_positions[c - 'A'].push_back(i+1);
    }

    ll total_triples = 0;

    for(int c=0; c<26; c++){
        int m = char_positions[c].size();
        if(m < 2) continue;

        vector<ll> prefix_sum(m, 0);
        prefix_sum[0] = char_positions[c][0];
        for(int i=1; i<m; i++) prefix_sum[i] = prefix_sum[i-1] + char_positions[c][i];

        ll sum_c = 0;
        for(int j=1; j<m; j++){
            ll term = (ll)j * char_positions[c][j] - prefix_sum[j-1];
            sum_c += term;
        }

        ll pairs = ((ll)m * (m -1)) / 2;

        ll triples_c = sum_c - pairs;
        total_triples += triples_c;
    }

    cout << total_triples;
}