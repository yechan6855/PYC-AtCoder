#include <iostream>
#include <string>

int main() {
    using namespace std;

    string S;
    cin >> S;

    size_t first_bar = S.find('|');
    size_t second_bar = S.find('|', first_bar + 1);

    S.erase(first_bar, second_bar - first_bar + 1);

    cout << S << endl;

    return 0;
}