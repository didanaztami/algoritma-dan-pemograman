#include <iostream>
#include <string>
using namespace std;

// Struktur untuk menyimpan data kontak
struct Kontak {
    string nama;
    string nomor;
    Kontak* next;
};

// Kelas untuk mengelola daftar kontak
class DaftarKontak {
private:
    Kontak* head;

public:
    DaftarKontak() {
        head = NULL;
    }

    // Menambahkan kontak baru
    void tambahKontak(string nama, string nomor) {
        Kontak* baru = new Kontak{nama, nomor, NULL};

        if (!head) {
            head = baru;
        } else {
            Kontak* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = baru;
        }

        cout << "Kontak berhasil ditambahkan.\n";
    }

    // Menampilkan semua kontak
    void tampilkanKontak() {
        if (!head) {
            cout << "Daftar kontak kosong.\n";
            return;
        }

        Kontak* temp = head;
        cout << "\nDaftar Kontak:\n";
        while (temp) {
            cout << "Nama: " << temp->nama << ", Nomor: " << temp->nomor << endl;
            temp = temp->next;
        }
    }

    // Mencari kontak berdasarkan nama
    void cariKontak(string nama) {
        Kontak* temp = head;
        while (temp) {
            if (temp->nama == nama) {
                cout << "Kontak ditemukan: Nama: " << temp->nama << ", Nomor: " << temp->nomor << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Kontak dengan nama \"" << nama << "\" tidak ditemukan.\n";
    }

    // Menghapus kontak berdasarkan nama
    void hapusKontak(string nama) {
        Kontak* temp = head;
        Kontak* prev = NULL;

        while (temp) {
            if (temp->nama == nama) {
                if (prev) {
                    prev->next = temp->next;
                } else {
                    head = temp->next;
                }
                delete temp;
                cout << "Kontak berhasil dihapus.\n";
                return;
            }
            prev = temp;
            temp = temp->next;
        }

        cout << "Kontak dengan nama \"" << nama << "\" tidak ditemukan.\n";
    }

    // Destructor untuk membersihkan memori
    ~DaftarKontak() {
        while (head) {
            Kontak* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Fungsi utama
int main() {
    DaftarKontak kontak;
    int pilihan;
    string nama, nomor;

    do {
    	cout << "================" <<endl;
    	cout << "Nama:Rafi al ghifari" <<endl;
		cout << "Nim:231011450534" <<endl;
		cout << "================" <<endl;
        cout << "\n=== Menu Daftar Kontak ===\n";
        cout << "1. Tambah Kontak\n";
        cout << "2. Tampilkan Semua Kontak\n";
        cout << "3. Cari Kontak\n";
        cout << "4. Hapus Kontak\n";
        cout << "5. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan;
        cin.ignore(); // Menghindari masalah input getline setelah cin

        switch (pilihan) {
            case 1:
                cout << "Masukkan Nama: ";
                getline(cin, nama);
                cout << "Masukkan Nomor Telepon: ";
                getline(cin, nomor);
                kontak.tambahKontak(nama, nomor);
                break;
            case 2:
                kontak.tampilkanKontak();
                break;
            case 3:
                cout << "Masukkan Nama yang Dicari: ";
                getline(cin, nama);
                kontak.cariKontak(nama);
                break;
            case 4:
                cout << "Masukkan Nama yang Akan Dihapus: ";
                getline(cin, nama);
                kontak.hapusKontak(nama);
                break;
            case 5:
                cout << "Terima kasih telah menggunakan program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }

    } while (pilihan != 5);

    return 0;
}
