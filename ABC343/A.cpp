#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    
    int A, B;
    cin >> A >> B;
    
    int sum = A + B;
    
    int random_number;
    do {
        random_number = rand() % 10;
    } while (random_number == sum);
    
    cout << random_number << endl;

    return 0;
}