#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, T, P;
    cin >> N >> T >> P;
    vector<int> L(N);

    for (int i = 0; i < N; ++i) {
        cin >> L[i];
    }

    int count = 0;
    for (int i = 0; i < N; ++i) {
        if (L[i] >= T) {
            count++;
        }
    }

    if (count >= P) {
        cout << 0 << endl;
    } else {
        int days = 0;
        while (count < P) {
            days++;
            count = 0;
            for (int i = 0; i < N; ++i) {
                if (L[i] + days >= T) {
                    count++;
                }
            }
        }
        cout << days << endl;
    }

    return 0;
}