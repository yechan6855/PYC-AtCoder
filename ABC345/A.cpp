#include <iostream>
#include <string>

using namespace std;

string isBidirectionalArrowString(const string &S) {
    
    if (S.front() == '<' && S.back() == '>') {
        int equalsCount = 0;
        
        for (char ch : S) {
            if (ch == '=') {
                equalsCount++;
            }
        }
        if (equalsCount > 0 && S.length() == equalsCount + 2) {
            return "Yes";
        }
    }
    return "No";
}

int main() {
    string S;
    cin >> S;
    cout << isBidirectionalArrowString(S) << endl;
    return 0;
}