#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(M);
    for (int i = 0; i < M; ++i) {
        cin >> A[i];
    }

    vector<vector<int>> X(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> X[i][j];
        }
    }

    vector<int> totalNutrients(M, 0);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            totalNutrients[j] += X[i][j];
        }
    }

    bool goalMet = true;
    for (int i = 0; i < M; ++i) {
        if (totalNutrients[i] < A[i]) {
            goalMet = false;
            break;
        }
    }

    if (goalMet) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}