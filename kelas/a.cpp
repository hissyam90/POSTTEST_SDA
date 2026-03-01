#include <iostream>
using namespace std;
int main() {
int angka = 20;
int *pAngka;
// Pointer menyimpan alamat variabel angka
pAngka = &angka;
// Menampilkan nilai dan alamat
cout << "Nilai variabel angka : " << angka << endl;
cout << "Alamat variabel angka : " << &angka << endl;
cout << "Alamat yang disimpan pointer : " << pAngka << endl;
cout << "Nilai yang diakses melalui pointer : " << *pAngka << endl;

*pAngka = 50;
cout << angka << endl;
return 0;
}