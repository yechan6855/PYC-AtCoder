#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    using namespace std;

    int N, M, L, Q;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    cin >> M;
    vector<int> B(M);
    for (int i = 0; i < M; ++i) {
        cin >> B[i];
    }

    cin >> L;
    vector<int> C(L);
    for (int i = 0; i < L; ++i) {
        cin >> C[i];
    }

    cin >> Q;
    vector<int> X(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> X[i];
    }

    unordered_map<int, bool> sumAB; // Precomputed sums of A and B
    for (int a : A) {
        for (int b : B) {
            sumAB[a + b] = true;
        }
    }

    for (int i = 0; i < Q; ++i) {
        bool possible = false;

        for (int c : C) {
            int needed_ab = X[i] - c;
            if (sumAB.find(needed_ab) != sumAB.end()) {
                possible = true;
                break;
            }
        }

        cout << (possible ? "Yes" : "No") << endl;
    }

    return 0;
}