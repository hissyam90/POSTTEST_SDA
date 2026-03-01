#include <iostream>
using namespace std;

int FindMin(int arr[], int n, int &min_idx) {
    int min_val = arr[0];
    min_idx = 0; 
    
    for (int i = 1; i < n; i++) {
        if (arr[i] < min_val) {
            min_val = arr[i];
            min_idx = i;
        }
    }
    return min_val;
}

int main() {
    int fibo[8] = {1, 1, 2, 3, 5, 8, 13, 21};
    int n = 8;
    int idx;
    
    int hasil_min = FindMin(fibo, n, idx);
    
    cout << "=== HASIL PENCARIAN NILAI MINIMUM ===" << endl;
    cout << "Nilai minimum  : " << hasil_min << endl;
    cout << "Berada di index: " << idx << endl; 
    
    return 0;
}

/*
analisis big O dari best case dan worst case

1. best Case (kondisi array udah urut naik, jadi nilai min gak pernah ke-update)
   Tmin(n) = c1 + c2(n) + c3(n-1) + c5
   Big-O = O(n), soalnya tetep aja kita harus ngecek tiap elemen array satu-satu pake loop.

2. worst Case (kondisi array urut turun, jadi tiap ngecek pasti selalu update nilai min)
   Tmax(n) = c1 + c2(n) + c3(n-1) + c4(n-1) + c5
   Big-O = O(n), karena kalau disederhanain kita cuma fokus ke pangkat n yang paling gede aja.
*/