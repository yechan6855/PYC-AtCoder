#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> S(12);
    for (int i = 0; i < 12; i++) {
        cin >> S[i];
    }

    int count = 0;
    for (int i = 0; i < 12; i++) {
        if (S[i].length() == i + 1) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}