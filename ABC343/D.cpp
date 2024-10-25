#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int N, T;
    cin >> N >> T;

    vector<long long> scores(N, 0);
    unordered_map<long long, long long> scoreCount;
    scoreCount[0] = N;

    for (int i = 0; i < T; ++i) {
        long long A, B;
        cin >> A >> B;
        --A;

        if (--scoreCount[scores[A]] == 0) {
            scoreCount.erase(scores[A]);
        }
        scores[A] += B;
        ++scoreCount[scores[A]];

        cout << scoreCount.size() << "\n";
    }
    return 0;
}