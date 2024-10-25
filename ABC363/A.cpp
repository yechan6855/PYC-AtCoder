#include <iostream>
using namespace std;

int main() {
    int R;
    cin >> R;

    if (R <= 99) {
        cout << 100 - R << endl;
    } else if (R <= 199) {
        cout << 200 - R << endl;
    } else if (R <= 299) {
        cout << 300 - R << endl;
    }

    return 0;
}