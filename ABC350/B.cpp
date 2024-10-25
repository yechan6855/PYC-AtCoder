#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<bool> teeth(N, true);

    for (int i = 0; i < Q; i++) {
        int T;
        cin >> T;
        T--;

        teeth[T] = !teeth[T];
    }

    int count = 0;
    for (bool tooth : teeth) {
        if (tooth) {
            count++;
        }
    }
    cout << count << endl;

    return 0;
}