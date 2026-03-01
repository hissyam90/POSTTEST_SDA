#include <iostream>
using namespace std;

int main() {
int data[5] = {10, 20, 30, 40, 50};
int *p = data; // Pointer menunjuk ke elemen pertama array
// Pointer bergerak selama masih berada dalam batas array

while (p < data + 5) {
cout << "Nilai: " << *p << ", Alamat: " << p << endl;
p++; // Maju ke elemen berikutnya
}

return 0;
}