#include <iostream>
#include <string>
using namespace std;


int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}


int combinations( int n,  int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

int main() {
    unsigned int n, k;
        cout << "Enter the value of n: ";
        cin >> n;
        cout << "Enter the value of k: ";
        cin >> k;
        cout << "C(" << n << ", " << k << ") = " << combinations(n, k) << std::endl;
    return 0;
}