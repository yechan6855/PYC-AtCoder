#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(const string& str, int start, int len) {
    for (int i = 0; i < len / 2; ++i) {
        if (str[start + i] != str[start + len - 1 - i]) {
            return false;
        }
    }
    return true;
}

bool solve(const string& str, int K) {
    int N = str.length();
    for (int i = 0; i <= N - K; ++i) {
        if (isPalindrome(str, i, K)) {
            return true;
        }
    }
    return false;
}

int main() {
    int N, K;
    string S;
    cin >> N >> K >> S;

    set<string> per;
    sort(S.begin(), S.end());
    do {
        per.insert(S);
    } while (next_permutation(S.begin(), S.end()));

    int count = 0;
    for (const string& perm : per) {
        if (!solve(perm, K)) {
            ++count;
        }
    }

    cout << count << endl;
    return 0;
}