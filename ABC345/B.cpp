#include <iostream>
using namespace std;

long long ceilDivideByTen(long long X) {
    if (X >= 0) {
        return (X / 10) + (X % 10 != 0);
    } else {
        return X / 10;
    }
}

int main() {
    long long X;
    cin >> X;
    cout << ceilDivideByTen(X) << endl;
    return 0;
}