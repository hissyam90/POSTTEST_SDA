#include <iostream>
#include <string>

using namespace std;

struct Bis {
    string nama;
    int harga;
};

void merge(Bis* arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Bis* L = new Bis[n1];
    Bis* R = new Bis[n2];

    for (int i = 0; i < n1; i++) *(L + i) = *(arr + left + i);
    for (int j = 0; j < n2; j++) *(R + j) = *(arr + mid + 1 + j);

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if ((L + i)->harga <= (R + j)->harga) {
            *(arr + k) = *(L + i);
            i++;
        } else {
            *(arr + k) = *(R + j);
            j++;
        }
        k++;
    }

    while (i < n1) { *(arr + k) = *(L + i); i++; k++; }
    while (j < n2) { *(arr + k) = *(R + j); j++; k++; }
    
    delete[] L;
    delete[] R;
}

void mergeSort(Bis* arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void tampilkanData(Bis* arr, int n) {
    cout << "Nama Bis\tHarga" << endl;
    for (int i = 0; i < n; i++) {
        Bis* ptr = (arr + i);
        cout << ptr->nama << "\t\tRp " << ptr->harga << endl;
    }
    cout << endl;
}

int main() {
    int n = 4;
    Bis daftarBis[4] = {
        {"Go jaya", 9000},
        {"Marakana", 8500},
        {"Suksessdor", 12000},
        {"Morganda", 11000}
    };

    cout << "Data Sebelum Sorting:" << endl;
    tampilkanData(daftarBis, n);

    mergeSort(daftarBis, 0, n - 1);

    cout << "Data Setelah Sorting (Merge Sort):" << endl;
    tampilkanData(daftarBis, n);

    return 0;
}