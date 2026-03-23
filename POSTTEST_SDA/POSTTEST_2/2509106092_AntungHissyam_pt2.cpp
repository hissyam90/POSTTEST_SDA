#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// struct untuk data kereta
struct Kereta {
    int nomor;
    string nama;
    string asal;
    string tujuan;
    int harga;
};

// fungsi swap pake dereferensi pointer (*a dan *b)
void tukar(Kereta* a, Kereta* b) {
    Kereta temp = *a;
    *a = *b;
    *b = temp;
}

// fungsi nampilin semua data kereta pake pointer aritmatika
void tampilkanKereta(Kereta* arr, int n) {
    if (n == 0) {
        cout << "Data kereta masih kosong!\n";
        return;
    }
    cout << "\n--- JADWAL KERETA API ---\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". No: " << (arr + i)->nomor
             << " | Nama: " << (arr + i)->nama
             << " | Rute: " << (arr + i)->asal << "-" << (arr + i)->tujuan
             << " | Harga: Rp" << (arr + i)->harga << "\n";
    }
}

// nambah data kereta, parameter n pake pass by reference (&)
void tambahKereta(Kereta* arr, int& n) {
    cout << "\n--- TAMBAH DATA KERETA ---\n";
    cout << "Nomor Kereta : ";
    cin >> (arr + n)->nomor;
    cin.ignore();
    cout << "Nama Kereta  : ";
    getline(cin, (arr + n)->nama);
    cout << "Stasiun Asal : ";
    getline(cin, (arr + n)->asal);
    cout << "Tujuan       : ";
    getline(cin, (arr + n)->tujuan);
    cout << "Harga Tiket  : ";
    cin >> (arr + n)->harga;
    n++;
    cout << "Data berhasil ditambah!\n";
}

// linear search buat cari rute kereta
void cariRuteLinear(Kereta* arr, int n, string asal, string tujuan) {
    bool ketemu = false;
    cout << "\nProses pencarian linear:\n";
    for (int i = 0; i < n; i++) {
        cout << "Cek indeks ke-" << i << " (Rute: " << (arr + i)->asal << "-" << (arr + i)->tujuan << ")\n";
        
        if ((arr + i)->asal == asal && (arr + i)->tujuan == tujuan) {
            cout << "\nKereta Ditemukan!\n";
            cout << "Nama: " << (arr + i)->nama << ", No: " << (arr + i)->nomor << ", Harga: Rp" << (arr + i)->harga << "\n";
            ketemu = true;
        }
    }
    if (!ketemu) {
        cout << "\nKereta rute " << asal << " ke " << tujuan << " tidak ditemukan.\n";
    }
}

// urutkan nomor kereta dulu sebelum jump search
void sortNomor(Kereta* arr, int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if((arr + j)->nomor > (arr + j + 1)->nomor) {
                tukar(&(arr[j]), &(arr[j+1]));
            }
        }
    }
}

// jump search cari nomor kereta
void jumpSearchNomor(Kereta* arr, int n, int cari) {
    if (n == 0) {
        cout << "Data masih kosong!\n"; return;
    }
    
    sortNomor(arr, n); 
    
    int step = sqrt(n);
    int prev = 0;

    cout << "\nProses lompatan Jump Search:\n";
    while ((arr + step - 1)->nomor < cari) {
        cout << "Lompat dari indeks " << prev << " ke " << step << "\n";
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            cout << "Nomor kereta tidak ada.\n";
            return;
        }
    }

    int batas = step;
    if (batas > n) batas = n;

    cout << "Cari linear dari indeks " << prev << " sampai " << batas - 1 << "\n";
    while (prev < batas) {
        if ((arr + prev)->nomor == cari) {
            cout << "\nKereta Ditemukan!\n";
            cout << "Nama: " << (arr + prev)->nama << " | Rute: " << (arr + prev)->asal << "-" << (arr + prev)->tujuan << "\n";
            return;
        }
        prev++;
    }
    cout << "Nomor kereta tidak ada.\n";
}

// selection sort urutkan harga dari yang termurah
void sortHarga(Kereta* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int idxMin = i;
        for (int j = i + 1; j < n; j++) {
            if ((arr + j)->harga < (arr + idxMin)->harga) {
                idxMin = j;
            }
        }
        if (idxMin != i) {
            tukar(&arr[i], &arr[idxMin]); 
        }
    }
    cout << "Berhasil diurutkan berdasarkan harga tiket termurah.\n";
}

// fungsi pembantu untuk merge sort pecah array dan gabungin hasilnya
void merge(Kereta* arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    Kereta* L = new Kereta[n1];
    Kereta* R = new Kereta[n2];

    for (int i = 0; i < n1; i++) 
        *(L + i) = *(arr + left + i);
    for (int j = 0; j < n2; j++) 
        *(R + j) = *(arr + mid + 1 + j);

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if ((L + i)->nama <= (R + j)->nama) {
            *(arr + k) = *(L + i);
            i++;
        } else {
            *(arr + k) = *(R + j);
            j++;
        }
        k++;
    }
    
    while (i < n1) { 
        *(arr + k) = *(L + i); 
        i++; k++; 
    }
    while (j < n2) { 
        *(arr + k) = *(R + j); 
        j++; k++; 
    }
    
    delete[] L;
    delete[] R;
}

// merge sort urutkan nama 
void sortNama(Kereta* arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        sortNama(arr, left, mid);
        sortNama(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    Kereta dataKereta[100]; 
    int jumlah = 0;
    int pilihan;

    do {
        cout << "\n=================================\n";
        cout << "   PROGRAM TIKET KERETA API\n";
        cout << "=================================\n";
        cout << "1. Lihat Jadwal Kereta\n";
        cout << "2. Tambah Jadwal\n";
        cout << "3. Cari Rute (Linear Search)\n";
        cout << "4. Cari Nomor Kereta (Jump Search)\n";
        cout << "5. Urutkan Nama A-Z (Merge Sort)\n";
        cout << "6. Urutkan Harga Tiket (Selection Sort)\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilkanKereta(dataKereta, jumlah);
                break;
            case 2:
                tambahKereta(dataKereta, jumlah);
                break;
            case 3: {
                if(jumlah == 0) { cout << "Data belum ada!\n"; break; }
                string as, tj;
                cout << "Stasiun Asal   : ";
                cin.ignore(); getline(cin, as);
                cout << "Stasiun Tujuan : ";
                getline(cin, tj);
                cariRuteLinear(dataKereta, jumlah, as, tj);
                break;
            }
            case 4: {
                if(jumlah == 0) { cout << "Data belum ada!\n"; break; }
                int no;
                cout << "Nomor Kereta yang dicari: ";
                cin >> no;
                jumpSearchNomor(dataKereta, jumlah, no);
                break;
            }
            case 5:
                if (jumlah > 0) {
                    sortNama(dataKereta, 0, jumlah - 1);
                    cout << "Berhasil diurutkan berdasarkan nama (A-Z).\n";
                    tampilkanKereta(dataKereta, jumlah); 
                } else {
                    cout << "Data belum ada!\n";
                }
                break;
            case 6:
                if (jumlah > 0) {
                    sortHarga(dataKereta, jumlah);
                    tampilkanKereta(dataKereta, jumlah); 
                } else {
                    cout << "Data belum ada!\n";
                }
                break;
            case 0:
                cout << "Keluar dari program...\n";
                break;
            default:
                cout << "Pilihan salah!\n";
        }
    } while (pilihan != 0);

    return 0;
}