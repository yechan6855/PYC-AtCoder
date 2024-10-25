#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int, int>
#define mi map<int, int>
#define qi queue<int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define endl "\n"
#define elif else if
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;

void solve(vector<vector<char>>& carpet, int size, int x, int y, int level) {
    if (level == 0) {
        carpet[x][y] = '#';
        return;
    }
    int blockSize = size / 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == 1 && j == 1) {
                for (int dx = 0; dx < blockSize; ++dx) {
                    for (int dy = 0; dy < blockSize; ++dy) {
                        carpet[x + i * blockSize + dx][y + j * blockSize + dy] = '.';
                    }
                }
            } else {
                solve(carpet, blockSize, x + i * blockSize, y + j * blockSize, level - 1);
            }
        }
    }
}

int main() {
    io;
    int N;
    cin >> N;

    int size = pow(3, N);
    vector<vector<char>> carpet(size, vector<char>(size, '.'));

    solve(carpet, size, 0, 0, N);

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << carpet[i][j];
        }
        cout << endl;
    }

    return 0;
}