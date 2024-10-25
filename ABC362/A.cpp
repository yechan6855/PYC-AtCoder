#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int r, g, b;
    string c;
    cin >> r >> g >> b;
    cin >> c;

    if (c == "Red") {
        cout << min(g, b) << endl;
    } else if (c == "Green") {
        cout << min(r, b) << endl;
    } else if (c == "Blue") {
        cout << min(r, g) << endl;
    }

    return 0;
}