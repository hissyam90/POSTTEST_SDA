#include <iostream>

using namespace std;

int main() {
    int nilai[5] = {85, 90, 78, 92, 88}; 
    int *ptrNilai = nilai; 

    int total = 0;
    float rataRata;

    cout << "=== Program Rekap Nilai Mahasiswa ===" << endl;
    cout << "-------------------------------------" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Nilai Mahasiswa ke-" << i + 1 << " : " << *(ptrNilai + i) << endl;
        total += *(ptrNilai + i); 
    }

    rataRata = (float)total / 5;

    cout << "-------------------------------------" << endl;
    cout << "Total Nilai Keseluruhan : " << total << endl;
    cout << "Rata-rata Nilai Kelas   : " << rataRata << endl;

    return 0;
}