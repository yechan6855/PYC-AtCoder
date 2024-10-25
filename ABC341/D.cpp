#include <bits/stdc++.h>

int main() {
    long long N, M, K;
    std::cin >> N >> M >> K;

    long long lcm = N / std::gcd(N, M) * M; // Least common multiple
    long long cycle = lcm / N + lcm / M - 2; // Total numbers divisible by N or M in one cycle
    long long fullCycles = K / cycle;
    long long remainder = K % cycle;

    long long answer = fullCycles * lcm;
    if (remainder == 0) {
        std::cout << answer - std::min(N, M) << std::endl;
        return 0;
    }

    long long nCount = 0, mCount = 0, current = 0;
    while (remainder > 0) {
        if ((nCount + 1) * N < (mCount + 1) * M) {
            current = ++nCount * N;
        } else {
            current = ++mCount * M;
        }
        remainder--;
    }

    answer += current;
    std::cout << answer << std::endl;
    return 0;
}