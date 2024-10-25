#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int sqr(int x) {
    return x * x;
}

int main() {
    int xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    int ab2 = sqr(xb - xa) + sqr(yb - ya);
    int bc2 = sqr(xc - xb) + sqr(yc - yb);
    int ca2 = sqr(xa - xc) + sqr(ya - yc);

    if (ab2 + bc2 == ca2 || ab2 + ca2 == bc2 || bc2 + ca2 == ab2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}