#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    float persentase;
    Node* next;
};

Node* head = NULL;

void insertTail(string nama, float persentase) {
    Node* baru = new Node;
    baru->nama = nama;
    baru->persentase = persentase;
    baru->next = NULL;

    if (head == NULL) {
        head = baru;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = baru;
    }
}

void deleteHead() {
    if (head == NULL) return;
    Node* hapus = head;
    head = head->next;
    delete hapus;
}

void deleteTail() {
    if (head == NULL) return;

    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

void tampilkan() {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->persentase < 80) {
            cout << temp->nama << " - Tidak Layak Ujian" << endl;
        }
        temp = temp->next;
    }
}

int main() {
    int pilihan;

    do {
        cout << "\n=== DATA KEHADIRAN MAHASISWA ===" << endl;
        cout << "1. Tambah data di akhir (Insert Tail)" << endl;
        cout << "2. Hapus data paling depan (Delete Head)" << endl;
        cout << "3. Hapus data paling belakang (Delete Tail)" << endl;
        cout << "4. Tampilkan (kehadiran < 80%)" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                string nama;
                float persen;
                cout << "Nama: ";
                cin.ignore();
                getline(cin, nama);
                cout << "Persentase kehadiran: ";
                cin >> persen;
                insertTail(nama, persen);
                break;
            }
            case 2:
                deleteHead();
                break;
            case 3:
                deleteTail();
                break;
            case 4:
                tampilkan();
                break;
            case 0:
                break;
            default:
                break;
        }
    } while (pilihan != 0);

    while (head != NULL) {
        deleteHead();
    }

    return 0;
}