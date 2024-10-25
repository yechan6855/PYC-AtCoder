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
    string S;
    cin >> S;

    int ucnt = 0;
    int lcnt = 0;

    for (char c : S) {
        if (isupper(c)) {
            ucnt++;
        } else if (islower(c)) {
            lcnt++;
        }
    }

    if (ucnt > lcnt) {
        for (char &c : S) {
            if (islower(c)) {
                c = toupper(c);
            }
        }
    } else {
        for (char &c : S) {
            if (isupper(c)) {
                c = tolower(c);
            }
        }
    }

    cout << S << endl;

    return 0;
}