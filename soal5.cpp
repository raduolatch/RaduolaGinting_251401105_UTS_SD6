#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct LinkedList {
    Node* head = NULL;

    void insertLast(int x) {
        Node* baru = new Node{x, NULL};
        if (head == NULL) {
            head = baru;
            return;
        }
        Node* numpang = head;
        while (numpang->next != NULL) {
            numpang = numpang->next;
        }
        numpang->next = baru;
    }
};

struct Stack {
    Node* top = NULL;

    void push(int x) {
        Node* baru = new Node{x, top};
        top = baru;
    }

    bool isEmpty() { return top == NULL; }

    int pop() {
        Node* hapus = top;
        int nilai = hapus->data;
        top = top->next;
        delete hapus;
        return nilai;
    }
};

struct Queue {
    Node* front = NULL;
    Node* rear = NULL;

    void enqueue(int x) {
        Node* baru = new Node{x, NULL};
        if (rear == NULL) {
            front = rear = baru;
            return;
        }
        rear->next = baru;
        rear = baru;
    }

    bool isEmpty() { return front == NULL; }

    int dequeue() {
        Node* hapus = front;
        int nilai = hapus->data;
        front = front->next;
        if (front == NULL) rear = NULL;
        delete hapus;
        return nilai;
    }
};

int main() {
    LinkedList list;
    Stack stack;
    Queue queue;

    cout << "Masukkan 5 angka: ";
    for (int i = 0; i < 5; i++) {
        int x;
        cin >> x;
        list.insertLast(x);
    }

    Node* p = list.head;
    while (p != NULL) {
        if (p->data % 3 == 0) {
            stack.push(p->data);      
        } else {
            queue.enqueue(p->data);   
        }
        p = p->next;
    }

    cout << "Output Stack : ";
    while (!stack.isEmpty()) {
        cout << stack.pop() << " ";
    }
    cout << endl;

    cout << "Output Queue : ";
    while (!queue.isEmpty()) {
        cout << queue.dequeue() << " ";
    }
    cout << endl;

    return 0;
}