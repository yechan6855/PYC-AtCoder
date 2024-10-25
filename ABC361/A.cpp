#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);

    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b;
    for(int i = 0; i < k; ++i) {
        b.push_back(a[i]);
    }

    b.push_back(x);

    for(int i = k; i < n; ++i) {
        b.push_back(a[i]);
    }

    for(int i = 0; i < b.size(); ++i) {
        cout << b[i] << " ";
    }

    cout << endl;

    return 0;
}