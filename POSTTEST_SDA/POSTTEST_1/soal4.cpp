#include <iostream>
using namespace std;

void swapNilai(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 9922;
    int y = 92;

    cout << "=== SEBELUM SWAP ===" << endl;
    cout << "Nilai x: " << x << endl;
    cout << "Nilai y: " << y << endl;

    swapNilai(x, y);

    cout << "\n=== SESUDAH SWAP ===" << endl;
    cout << "Nilai x: " << x << endl;
    cout << "Nilai y: " << y << endl;

    return 0;
}