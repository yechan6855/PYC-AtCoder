#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<int> quotients;
    for (int i = 0; i < N; ++i) {
        if (A[i] % K == 0) {
            quotients.push_back(A[i] / K);
        }
    }

    sort(quotients.begin(), quotients.end());

    for (int i = 0; i < quotients.size(); ++i) {
        cout << quotients[i] << " ";
    }
    cout << endl;

    return 0;
}