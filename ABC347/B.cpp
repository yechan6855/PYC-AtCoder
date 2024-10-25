#include <iostream>
#include <string>
#include <set>

using namespace std;

int countSubstrings(const string &s) {
    set<string> substrings;
    for (int i = 0; i < s.length(); ++i) {
        for (int len = 1; i + len <= s.length(); ++len) {
            substrings.insert(s.substr(i, len));
        }
    }
    return substrings.size();
}

int main() {
    string s;
    cin >> s;
    cout << countSubstrings(s) << endl;
    return 0;
}
