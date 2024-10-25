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
#define MOD 998244353
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

ll mod_string(string base, ll exp, ll mod) {
    ll result = 1;
    ll base_mod = 0;

    for (char digit : base) {
        base_mod = (base_mod * 10 + (digit - '0')) % mod;
    }

    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base_mod) % mod;
        }
        base_mod = (base_mod * base_mod) % mod;
        exp /= 2;
    }
    return result;
}

ll mod_inv(ll a, ll mod) {
    return mod_string(to_string(a), mod - 2, mod);
}

int num_digits(const string &s) {
    return s.length();
}

int main() {
    io;
    string N_str;
    cin >> N_str;

    int d = num_digits(N_str);

    string base = "10";
    ll power_d = mod_string(base, d, MOD);

    ll N_mod = 0;
    for (char digit : N_str) {
        N_mod = (N_mod * 10 + (digit - '0')) % (MOD - 1);
    }

    ll exp = (d * N_mod) % (MOD - 1);
    ll pN = mod_string(base, exp, MOD);

    ll num = (pN - 1 + MOD) % MOD;
    ll den = (power_d - 1 + MOD) % MOD;

    ll N_int = 0;
    for (char digit : N_str) {
        N_int = (N_int * 10 + (digit - '0')) % MOD;
    }

    ll ans = (N_int * num % MOD) * mod_inv(den, MOD) % MOD;

    cout << ans << endl;

    return 0;
}