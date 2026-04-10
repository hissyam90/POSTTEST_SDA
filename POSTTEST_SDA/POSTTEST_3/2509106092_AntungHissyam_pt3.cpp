#include <iostream>
#include <string>

using namespace std;

// kapasitas maksimum antrian dan riwayat
const int MAX = 5;

// struct untuk data pemesanan
struct Tiket {
    string nama_penumpang;
    string rute_kereta;
};

// struct untuk queue 
struct Queue {
    Tiket data[MAX];
    int rear = 0; 
};

// struct untuk stack (riwayat transaksi)
struct Stack {
    Tiket data[MAX];
    int top = -1;
};

// enqueue buat nambah penumpang ke antrian
void tambahAntrian(Queue* q) {
    // penanganan overflow
    if (q->rear == MAX) {
        cout << "\n[!] OVERFLOW: Antrian sudah penuh! Maksimal " << MAX << " orang.\n";
        return;
    }

    Tiket t;
    cout << "\n--- PEMESANAN TIKET ---\n";
    cout << "Nama Penumpang : ";
    cin.ignore();
    getline(cin, t.nama_penumpang);
    cout << "Rute Kereta    : ";
    getline(cin, t.rute_kereta);

    // memasukkan data pakai pointer aritmatika
    *(q->data + q->rear) = t;
    q->rear++;
    
    cout << "Penumpang " << t.nama_penumpang << " berhasil masuk ke antrian.\n";
}

// tampil antrian dari front ke rear pakai pointer aritmatika
void tampilAntrian(Queue* q) {
    // penanganan underflow
    if (q->rear == 0) {
        cout << "\n[!] UNDERFLOW: Antrian kosong, belum ada pemesan.\n";
        return;
    }

    cout << "\n--- DAFTAR ANTRIAN TIKET ---\n";
    for (int i = 0; i < q->rear; i++) {
        cout << i + 1 << ". Nama: " << (q->data + i)->nama_penumpang 
             << " | Rute: " << (q->data + i)->rute_kereta << "\n";
    }
}

// push buat catat transaksi ke riwayat
void pushRiwayat(Stack* s, Tiket t) {
    if (s->top == MAX - 1) {
        cout << "\n[!] OVERFLOW: Buku riwayat transaksi penuh!\n";
        return;
    }
    s->top++;
    // masukin data ke stack pakai pointer aritmatika
    *(s->data + s->top) = t;
}

// pop buat batalkan transaksi terakhir
void popRiwayat(Stack* s) {
    // penanganan underflow
    if (s->top == -1) {
        cout << "\n[!] UNDERFLOW: Riwayat kosong, tidak ada transaksi yang bisa dibatalkan.\n";
        return;
    }
    cout << "\n[-] Transaksi tiket untuk penumpang '" << (s->data + s->top)->nama_penumpang << "' berhasil dibatalkan.\n";
    s->top--; 
}

// tampil riwayat dari top ke bottom pakai pointer aritmatika
void tampilRiwayat(Stack* s) {
    if (s->top == -1) {
        cout << "\n[!] UNDERFLOW: Riwayat transaksi masih kosong.\n";
        return;
    }

    cout << "\n--- RIWAYAT TRANSAKSI TIKET ---\n";
    for (int i = s->top; i >= 0; i--) {
        cout << s->top - i + 1 << ". Nama: " << (s->data + i)->nama_penumpang 
             << " | Rute: " << (s->data + i)->rute_kereta << "\n";
    }
}


// dequeue buat proses tiket antrian terdepan dan masukin ke stack
void prosesTiket(Queue* q, Stack* s) {
    if (q->rear == 0) {
        cout << "\n[!] UNDERFLOW: Tidak ada penumpang di antrian yang bisa diproses.\n";
        return;
    }

    // ambil data paling depan (front = 0)
    Tiket penumpang_terdepan = *(q->data + 0);
    
    cout << "\n>>> MEMPROSES TIKET:\n";
    cout << "Nama Penumpang: " << penumpang_terdepan.nama_penumpang << "\n";
    cout << "Rute Kereta   : " << penumpang_terdepan.rute_kereta << "\n";

    // pergeseran elemen pakai dereferensi pointer (*a = *b)
    for (int i = 0; i < q->rear - 1; i++) {
        *(q->data + i) = *(q->data + i + 1);
    }
    q->rear--; 

    // masukkan ke riwayat transaksi
    pushRiwayat(s, penumpang_terdepan);
    cout << "Tiket berhasil diproses dan dicatat di riwayat.\n";
}

// peek buat liat data terdepan dan teratas
void cekTerdepan(Queue* q, Stack* s) {
    cout << "\n--- CEK DATA TERDEPAN (PEEK) ---\n";
    
    if (q->rear == 0) {
        cout << "[Antrian] Pemesan berikutnya : (Kosong)\n";
    } else {
        cout << "[Antrian] Pemesan berikutnya : " << (q->data + 0)->nama_penumpang 
             << " (Rute: " << (q->data + 0)->rute_kereta << ")\n";
    }

    if (s->top == -1) {
        cout << "[Riwayat] Transaksi terakhir : (Kosong)\n";
    } else {
        cout << "[Riwayat] Transaksi terakhir : " << (s->data + s->top)->nama_penumpang 
             << " (Rute: " << (s->data + s->top)->rute_kereta << ")\n";
    }
}

// program utama
int main() {
    Queue antrianTiket;
    Stack riwayatTransaksi;
    int pilihan;

    do {
        cout << "\n=========================================\n";
        cout << " SISTEM ANTRIAN TIKET KERETA API\n";
        cout << "=========================================\n";
        cout << "1. Masuk Antrian Tiket (Enqueue)\n";
        cout << "2. Proses Tiket (Dequeue & Push)\n";
        cout << "3. Tampil Antrian\n";
        cout << "4. Tampil Riwayat Transaksi\n";
        cout << "5. Cek Pemesan & Riwayat Teratas (Peek)\n";
        cout << "6. Batalkan Transaksi Terakhir (Pop)\n";
        cout << "0. Keluar Program\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch(pilihan) {
            case 1: tambahAntrian(&antrianTiket); break;
            case 2: prosesTiket(&antrianTiket, &riwayatTransaksi); break;
            case 3: tampilAntrian(&antrianTiket); break;
            case 4: tampilRiwayat(&riwayatTransaksi); break;
            case 5: cekTerdepan(&antrianTiket, &riwayatTransaksi); break;
            case 6: popRiwayat(&riwayatTransaksi); break;
            case 0: cout << "Keluar dari program...\n"; break;
            default: cout << "Pilihan tidak tersedia!\n";
        }
    } while (pilihan != 0);

    return 0;
}