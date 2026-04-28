#include <iostream>
#include <string>
using namespace std;

// Struktur Node untuk Circular Linked List Toko Sembako
struct BarangNode {
    string namaBarang;
    int stok;
    BarangNode* next;

    // Constructor
    BarangNode(string nama, int jumlah) {
        namaBarang = nama;
        stok = jumlah;
        next = nullptr;
    }
};

// Fungsi insert di akhir Circular Linked List untuk membangun data
BarangNode* tambahBarang(BarangNode* head, string nama, int jumlah) {
    BarangNode* newNode = new BarangNode(nama, jumlah);
    if (head == nullptr) {
        newNode->next = newNode; // Menunjuk ke dirinya sendiri (Sirkuler)
        return newNode;
    }
    
    BarangNode* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    return head;
}

/**
 * @brief Fungsi untuk menampilkan semua barang dalam Circular Linked List.
 * @param head Pointer ke node pertama (head) dari circular linked list.
 */
void tampilkanStokSembako(BarangNode* head) {
    // --- LENGKAPI KODE DI SINI ---
    
    // 1. base case ngecek apakah linked list kosong
    if (head == nullptr) { 
        cout << "Gudang kosong." << endl; // menampilkan pesan jika tidak ada data
        return; 
    }

    // 2. membuat pointer sementara agar posisi head tidak berubah
    BarangNode* temp = head; 
    
    // 3. menggunakan do-while agar blok kode dieksekusi minimal satu kali 
    do {
        // cetak nama dan stok barang dari node yang sedang ditunjuk oleh temp
        cout << "- " << temp->namaBarang << ": " << temp->stok << endl; 
        
        // 4. mmajukan pointer temp ke node berikutnya
        temp = temp->next; 
        
    // 5. kondisi berenti kalau temp kembali ke head
    } while (temp != head);
    // -----------------------------
}

int main() {
    BarangNode* head = nullptr;
    
    head = tambahBarang(head, "Beras", 50);
    head = tambahBarang(head, "Minyak Goreng", 30);
    head = tambahBarang(head, "Gula Pasir", 20);
    head = tambahBarang(head, "Tepung Terigu", 15);

    cout << "Daftar Stok Sembako:" << endl;
    tampilkanStokSembako(head); 
    
    return 0;
}