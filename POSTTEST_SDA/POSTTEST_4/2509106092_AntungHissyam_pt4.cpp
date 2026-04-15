#include <iostream>
#include <string>

using namespace std;

struct TiketNode {
    string nama_penumpang;
    string rute_kereta;
    TiketNode* next; 
};

struct Queue {
    TiketNode* front;
    TiketNode* rear;
};

struct Stack {
    TiketNode* top;
};

void initQueue(Queue* q) {
    q->front = nullptr;
    q->rear = nullptr;
}

void initStack(Stack* s) {
    s->top = nullptr;
}

// swap data antar node menggunakan dereferensi pointer field 
void tukarData(TiketNode* a, TiketNode* b) {
    string tempNama = a->nama_penumpang;
    string tempRute = a->rute_kereta;

    a->nama_penumpang = b->nama_penumpang;
    a->rute_kereta = b->rute_kereta;

    b->nama_penumpang = tempNama;
    b->rute_kereta = tempRute;
}

void enqueue(Queue* q) {
    TiketNode* newNode = new TiketNode();
    
    cout << "\n--- PEMESANAN TIKET ---\n";
    cout << "Nama Penumpang : ";
    cin.ignore();
    getline(cin, newNode->nama_penumpang);
    cout << "Rute Kereta    : ";
    getline(cin, newNode->rute_kereta);
    newNode->next = nullptr;

    // kalo antrian masih kosong
    if (q->rear == nullptr) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        // sambungkan node baru ke belakang antrian
        q->rear->next = newNode;
        q->rear = newNode;
    }
    cout << "Penumpang " << newNode->nama_penumpang << " berhasil masuk ke antrian.\n";
}

void tampilAntrian(Queue* q) {
    if (q->front == nullptr) {
        cout << "\n[!] UNDERFLOW: Antrian kosong, belum ada pemesan.\n";
        return;
    }

    cout << "\n--- DAFTAR ANTRIAN TIKET (Front - Rear) ---\n";
    TiketNode* current = q->front;
    int i = 1;
    while (current != nullptr) {
        cout << i++ << ". Nama: " << current->nama_penumpang 
             << " | Rute: " << current->rute_kereta << "\n";
        current = current->next;
    }
}

// mencatat transaksi berhasil ke riwayat
void pushRiwayat(Stack* s, string nama, string rute) {
    TiketNode* newNode = new TiketNode();
    newNode->nama_penumpang = nama;
    newNode->rute_kereta = rute;
    
    // lifo
    newNode->next = s->top;
    s->top = newNode;
}

// pop untuk membatalkan riwayat transaksi terakhir
void popRiwayat(Stack* s) {
    if (s->top == nullptr) {
        cout << "\n[!] UNDERFLOW: Riwayat kosong, tidak ada transaksi yang bisa dibatalkan.\n";
        return;
    }

    TiketNode* temp = s->top;
    cout << "\n[-] Transaksi tiket untuk penumpang '" << temp->nama_penumpang << "' berhasil dibatalkan.\n";
    
    s->top = s->top->next;
    
    delete temp; 
}

void tampilRiwayat(Stack* s) {
    if (s->top == nullptr) {
        cout << "\n[!] UNDERFLOW: Riwayat transaksi masih kosong.\n";
        return;
    }

    cout << "\n--- RIWAYAT TRANSAKSI TIKET (Top - Bottom) ---\n";
    TiketNode* current = s->top;
    int i = 1;
    while (current != nullptr) {
        cout << i++ << ". Nama: " << current->nama_penumpang 
             << " | Rute: " << current->rute_kereta << "\n";
        current = current->next;
    }
}

void prosesTiket(Queue* q, Stack* s) {
    if (q->front == nullptr) {
        cout << "\n[!] UNDERFLOW: Tidak ada penumpang di antrian yang bisa diproses.\n";
        return;
    }

    TiketNode* temp = q->front;
    
    cout << "\n>>> MEMPROSES TIKET:\n";
    cout << "Nama Penumpang: " << temp->nama_penumpang << "\n";
    cout << "Rute Kereta   : " << temp->rute_kereta << "\n";

    pushRiwayat(s, temp->nama_penumpang, temp->rute_kereta);

    q->front = q->front->next;
    
    if (q->front == nullptr) {
        q->rear = nullptr; 
    }

    delete temp;
    cout << "Tiket berhasil diproses dan dicatat di riwayat.\n";
}

// peek untuk melihat data paling awal antrian dan paling akhir riwayat tanpa menghapus
void cekTerdepan(Queue* q, Stack* s) {
    cout << "\n--- CEK DATA TERDEPAN (PEEK) ---\n";
    
    if (q->front == nullptr) {
        cout << "[Antrian] Pemesan berikutnya : (Kosong - Underflow)\n";
    } else {
        cout << "[Antrian] Pemesan berikutnya : " << q->front->nama_penumpang 
             << " (Rute: " << q->front->rute_kereta << ")\n";
    }

    if (s->top == nullptr) {
        cout << "[Riwayat] Transaksi terakhir : (Kosong - Underflow)\n";
    } else {
        cout << "[Riwayat] Transaksi terakhir : " << s->top->nama_penumpang 
             << " (Rute: " << s->top->rute_kereta << ")\n";
    }
}

int main() {
    Queue antrianTiket;
    Stack riwayatTransaksi;
    
    initQueue(&antrianTiket);
    initStack(&riwayatTransaksi);
    
    int pilihan;

    do {
        cout << "\n=========================================\n";
        cout << " SISTEM ANTRIAN TIKET KERETA API (SLL)\n";
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
            case 1: enqueue(&antrianTiket); break;
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