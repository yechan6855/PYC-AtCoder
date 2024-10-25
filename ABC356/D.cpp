#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

const long long MOD = 998244353;

int popcount(long long x) {
    return __builtin_popcountll(x);
}

long long bit_contribution(int bit, long long N, long long M) {
    long long block_size = 1LL << (bit + 1);
    long long full_blocks = (N + 1) / block_size;
    long long remainder = (N + 1) % block_size;
    long long ones_in_blocks = full_blocks * (block_size / 2);

    if (remainder > (1LL << bit)) {
        ones_in_blocks += remainder - (1LL << bit);
    }

    return ones_in_blocks * (M & (1LL << bit) ? 1 : 0);
}

int main() {
    long long N, M;
    cin >> N >> M;

    long long result = 0;

    for (int bit = 0; bit < 60; ++bit) {
        result += bit_contribution(bit, N, M) % MOD;
        result %= MOD;
    }

    cout << result << endl;
    return 0;
}