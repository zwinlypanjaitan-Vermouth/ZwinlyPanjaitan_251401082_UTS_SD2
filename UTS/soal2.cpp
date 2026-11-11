#include <iostream>
using namespace std;

struct Node {
    int nilai;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

void printList() {
    Node *temp = head;
    cout << "Isi Linked List: ";
    if (temp == NULL) {
        cout << "NULL\n";
        return;
    }
    while (temp != NULL) {
        cout << temp->nilai << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void insertFirst(int val) {
    Node *newNode = new Node;
    newNode->nilai = val;
    newNode->next = NULL;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    printList();
}

void insertLast(int val) {
    Node *newNode = new Node;
    newNode->nilai = val;
    newNode->next = NULL;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    printList();
}

void deleteAfter(int val, int target) {
    if (head == NULL) {
        cout << "linked list kosong";
    }
    Node *newNode = head;
    while (newNode != NULL && newNode -> value != check) {
        newNode = newNode ->next;
    }
    if (newNode != NULL && newNode -> next != NULL) {
        Node *temp = newNode -> next;
        newNode-> next = temp ->next;

        if (temp == tail) {
            tail = newNode;
        }
        delete(temp);
    }
}

void deleteByValue(int target) {
    if (head == NULL) {
        cout << "List kosong!\n";
        return;
    }

    if (head->nilai == target) {
        Node *temp = head;
        head = head->next;
        if (head == NULL) tail = NULL;
        delete temp;
        printList();
        return;
    }

    Node *p = head;
    while (p->next != NULL && p->next->nilai != target) {
        p = p->next;
    }

    if (p->next == NULL) {
        cout << "Nilai " << target << " tidak ditemukan!\n";
    } else {
        Node *temp = p->next;
        p->next = temp->next;

        if (temp == tail) {
            tail = p;
        }
        delete temp;
        printList();
    }
}

int main() {
    int pilihan, nilai, target;

    do {
        cout << "1. Tambah di awal\n";
        cout << "2. Tambah di akhir\n";
        cout << "3. Hapus data di awal\n";
        cout << "4. Tampilkan Hanya Pendaftar yang lolos (skor >= 75\n";
       
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                insertFirst(nilai);
                break;
            case 2:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                insertLast(nilai);
                break;
            case 3:
                cout << "Hapus data di awal: ";
                cin >> nilai;
                insertAfter(nilai, target);
                break;
            case 4:
                cout << "Masukkan nilai yang ingin dihapus: ";
                cin >> target;
                deleteByValue(target);
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}
