#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<int>> tests(M);
    vector<char> results(M);

    for (int i = 0; i < M; ++i) {
        int Ci;
        cin >> Ci;
        tests[i].resize(Ci);
        for (int j = 0; j < Ci; ++j) {
            cin >> tests[i][j];
            tests[i][j]--;
        }
        cin >> results[i];
    }

    int valid_combinations = 0;

    for (int mask = 0; mask < (1 << N); ++mask) {
        bool valid = true;
        for (int i = 0; i < M && valid; ++i) {
            int real_keys_count = 0;
            for (int key : tests[i]) {
                if (mask & (1 << key)) {
                    real_keys_count++;
                }
            }
            if (results[i] == 'o' && real_keys_count < K) {
                valid = false;
            }
            if (results[i] == 'x' && real_keys_count >= K) {
                valid = false;
            }
        }
        if (valid) {
            valid_combinations++;
        }
    }

    cout << valid_combinations << endl;

    return 0;
}