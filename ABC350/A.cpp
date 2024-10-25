#include <iostream>
#include <string>
using namespace std;

int main() {
    string S;
    cin >> S;
    
    if (S.substr(0, 3) != "ABC") {
        cout << "No" << endl;
        return 0;
    }
    
    int contestNumber = stoi(S.substr(3));
    
    if (contestNumber >= 1 && contestNumber <= 349 && contestNumber != 316) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}