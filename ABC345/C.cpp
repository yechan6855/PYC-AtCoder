#include <iostream>
#include <string>
#include <vector>
using namespace std;

long long countUniqueSwaps(const string& S) {
    vector<int> alph(26, 0);
    bool hasDuplicate = false;
    
    for (char ch : S) {
        alph[ch - 'a']++;
        if (alph[ch - 'a'] > 1) {
            hasDuplicate = true;
        }
    }
    
    long long s = hasDuplicate ? 1 : 0;
    
    for (int i = 0; i < 26; ++i) {
        for (int j = i + 1; j < 26; ++j) {
            s += alph[i] * alph[j];
        }
    }

    return s;
}

int main() {
    string S;
    cin >> S;

    cout << countUniqueSwaps(S) << endl;
    return 0;
}