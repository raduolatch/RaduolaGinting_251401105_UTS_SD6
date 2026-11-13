#include <iostream>
using namespace std;

#define MAX 100

// Struktur Queue berbasis array
struct Queue {
    char data[MAX];
    int front;
    int rear;
};


void init(Queue &q) {
    q.front = 0;
    q.rear = -1;
}

bool isEmpty(Queue q) {
    return q.rear < q.front;
}

bool isFull(Queue q) {
    return q.rear == MAX - 1;
}

void enqueue(Queue &q, char c) {
    if (isFull(q)) {
        cout << "Queue penuh!" << endl;
        return;
    }
    q.rear++;
    q.data[q.rear] = c;
}

char dequeue(Queue &q) {
    if (isEmpty(q)) {
        cout << "Queue kosong!" << endl;
        return '\0';
    }
    char c = q.data[q.front];
    q.front++;
    return c;
}

bool isVokal(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o');
}

int main() {
    Queue q;
    init(q);

    string kata;
    cout << "Masukkan sebuah kata: ";
    cin >> kata;

    for (int i = 0; i < (int)kata.length(); i++) {
        enqueue(q, kata[i]);
    }

    cout << "Huruf konsonan: ";
    while (!isEmpty(q)) {
        char c = dequeue(q);
        if (!isVokal(c)) {
            cout << c;
        }
    }
    cout << endl;

    return 0;
}