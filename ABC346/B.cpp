#include <bits/stdc++.h>

using namespace std;

bool isSubstringExists(int W, int B) {
    string pattern = "wbwbwwbwbwbw";
    int len = pattern.length();
    
    for (int start = 0; start < len; ++start) {
        int countW = 0, countB = 0;
        for (int i = start; countW <= W && countB <= B; i = (i + 1) % len) {
            countW += (pattern[i] == 'w');
            countB += (pattern[i] == 'b');
            if (countW == W && countB == B) return true;
        }
    }

    return false;
}

int main() {
    int W, B;
    cin >> W >> B;

    if (isSubstringExists(W, B))
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}