#include <iostream>
using namespace std;

void reverseArray(int* arr, int n) {
    int* ptr_kiri = arr;           
    int* ptr_kanan = arr + n - 1;  
    
    while (ptr_kiri < ptr_kanan) {
        int temp = *ptr_kiri;
        *ptr_kiri = *ptr_kanan;
        *ptr_kanan = temp;
        
        ptr_kiri++;  
        ptr_kanan--; 
    }
}

int main() {
    int prima[7] = {2, 3, 5, 7, 11, 13, 17};
    int n = 7;

    cout << "=== ARRAY SEBELUM DIBALIK ===" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Elemen " << *(prima + i) << " di memori: " << (prima + i) << endl;
    }

    reverseArray(prima, n);

    cout << "\n=== ARRAY SESUDAH DIBALIK ===" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Elemen " << *(prima + i) << " di memori: " << (prima + i) << endl;
    }

    return 0;
}