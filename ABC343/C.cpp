#include <iostream>
#include <cmath>

using namespace std;

bool is_palindrome(long long num) {
    long long reversed = 0;
    long long original = num;

    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }

    return original == reversed;
}

int main() {
    long long N;
    cin >> N;

    long long max_palindrome_cube = 0;
    for (long long x = 1; x * x * x <= N; ++x) {
        long long cube = x * x * x;
        if (is_palindrome(cube) && cube > max_palindrome_cube) {
            max_palindrome_cube = cube;
        }
    }

    cout << max_palindrome_cube << endl;

    return 0;
}