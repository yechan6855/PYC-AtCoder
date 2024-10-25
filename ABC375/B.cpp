#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<ll, ll>> points(N);
    for (int i = 0; i < N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    double total_cost = 0;
    ll current_x = 0, current_y = 0;

    for (int i = 0; i < N; ++i) {
        ll next_x = points[i].first;
        ll next_y = points[i].second;
        total_cost += sqrt((current_x - next_x) * (current_x - next_x) + (current_y - next_y) * (current_y - next_y));
        current_x = next_x;
        current_y = next_y;
    }
    
    total_cost += sqrt(current_x * current_x + current_y * current_y);
    
    cout.precision(15);
    cout << total_cost << endl;

    return 0;
}