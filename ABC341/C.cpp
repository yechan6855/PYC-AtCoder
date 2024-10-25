#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int H, W, N;
    cin >> H >> W >> N;
    string T;
    cin >> T;
    vector<string> grid(H);
    for (int i = 0; i < H; ++i) {
        cin >> grid[i];
    }
    
    vector<vector<bool>> possible(H, vector<bool>(W, false));
    for (int i = 1; i < H-1; ++i) {
        for (int j = 1; j < W-1; ++j) {
            if (grid[i][j] == '.') possible[i][j] = true;
        }
    }
    
    for (int move = N-1; move >= 0; --move) {
        vector<vector<bool>> new_possible(H, vector<bool>(W, false));
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (!possible[i][j]) continue;
                if (T[move] == 'L' && j+1 < W && grid[i][j+1] == '.') new_possible[i][j+1] = true;
                if (T[move] == 'R' && j-1 >= 0 && grid[i][j-1] == '.') new_possible[i][j-1] = true;
                if (T[move] == 'U' && i+1 < H && grid[i+1][j] == '.') new_possible[i+1][j] = true;
                if (T[move] == 'D' && i-1 >= 0 && grid[i-1][j] == '.') new_possible[i-1][j] = true;
            }
        }
        possible = new_possible;
    }
    int count = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (possible[i][j]) ++count;
        }
    }

    cout << count << endl;
    return 0;
}