#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

int main() {
    Mahasiswa mhs[5];
    int idx_max = 0; 

    cout << "=== INPUT DATA 5 MAHASISWA ===" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "\nData Mahasiswa ke-" << i + 1 << endl;
        cout << "Nama : ";
        getline(cin >> ws, mhs[i].nama); 
        cout << "NIM  : ";
        cin >> mhs[i].nim;
        cout << "IPK  : ";
        cin >> mhs[i].ipk;
        if (mhs[i].ipk > mhs[idx_max].ipk) {
            idx_max = i;
        }
    }

    cout << "\n=====================================" << endl;
    cout << "MAHASISWA DENGAN IPK TERTINGGI:" << endl;
    cout << "Nama : " << mhs[idx_max].nama << endl;
    cout << "NIM  : " << mhs[idx_max].nim << endl;
    cout << "IPK  : " << mhs[idx_max].ipk << endl;

    return 0;
}