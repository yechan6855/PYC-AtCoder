#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    vector<int> p(26);

    for (int i = 0; i < 26; i++) {
        p[s[i] - 'A'] = i;
    }

    int d = 0;
    int c = p[0];

    for (int i = 1; i < 26; i++) {
        d += abs(p[i] - c);
        c = p[i];
    }

    cout << d << endl;

    return 0;
}