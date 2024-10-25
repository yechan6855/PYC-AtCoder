#include <iostream>
#include <vector>

int main() {
    using namespace std;

    vector<int> A;

    int num;
    while (cin >> num) {
        A.push_back(num);
    }

    for (int i = A.size() - 1; i >= 0; --i) {
        cout << A[i] << endl;
    }

    return 0;
}