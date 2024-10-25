#include <iostream>
#define endl "\n"

using namespace std;

int main() {
    int a, b, c, d, e, f;
    int g, h, i, j, k, l;

    cin >> a >> b >> c >> d >> e >> f;
    cin >> g >> h >> i >> j >> k >> l;

    bool oX = (a < j && d > g);
    bool oY = (b < k && e > h);
    bool oZ = (c < l && f > i);

    if (oX && oY && oZ) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}