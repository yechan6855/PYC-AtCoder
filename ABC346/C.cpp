#include <bits/stdc++.h>

using namespace std;

int main() {
    long long N, K;
    cin >> N >> K;

    set<long long> uniqueNumbers;
    for (int i = 0; i < N; ++i) {
        long long number;
        cin >> number;
        if (number <= K) {
            uniqueNumbers.insert(number);
        }
    }
    
    long long totalSum = K * (K + 1) / 2;
    
    for (long long num : uniqueNumbers) {
        totalSum -= num;
    }

    cout << totalSum << endl;

    return 0;
}