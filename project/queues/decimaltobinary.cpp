#include<iostream>
using namespace std;

void decimalToBinary(int n) {
    if (n > 0) {
        decimalToBinary(n / 2);
        cout << n % 2;
    }
}

int main() {
    int decimal;
    cout << "Enter a decimal number: ";
    cin >> decimal;
    cout << "Binary representation: ";
    decimalToBinary(decimal);
    cout << endl;
    return 0;
}
