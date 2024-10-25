#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<pair<int, int>> operations;
    vector<int> pos(N + 1);

    for (int i = 0; i < N; i++) {
        pos[A[i]] = i;
    }

    for (int i = 1; i <= N; i++) {
        if (pos[i] != i - 1) {
            operations.push_back({pos[i] + 1, i});
            pos[A[i - 1]] = pos[i];
            swap(A[pos[i]], A[i - 1]);
        }
    }

    int K = operations.size();
    cout << K << endl;
    for (const auto& op : operations) {
        cout << op.second<< " " << op.first << endl;
    }

    return 0;
}