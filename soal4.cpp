#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *kiri, *kanan;
} Node;

Node* buatNode(int x) {
    Node *baru = (Node*)malloc(sizeof(Node));
    baru->data = x;
    baru->kiri = baru->kanan = NULL;
    return baru;
}

Node* insert(Node *root, int x) {
    if (root == NULL) return buatNode(x);  
    if (x < root->data)
        root->kiri = insert(root->kiri, x);
    else if (x > root->data)
        root->kanan = insert(root->kanan, x);
    return root;
}

void inOrder(Node *root) {
    if (root == NULL) return;
    inOrder(root->kiri);
    printf("%d ", root->data);
    inOrder(root->kanan);
}

int main() {
    Node *root = NULL;
    int x;

    printf("Masukan (akhiri dengan 0): ");
    while (scanf("%d", &x) == 1 && x != 0) {
        root = insert(root, x);
    }

    if (root == NULL) {
        printf("Tree kosong.\n");
        return 0;
    }

    printf("In-Order : ");
    inOrder(root);
    printf("\n");

    Node *min = root;
    while (min->kiri != NULL) min = min->kiri;

    Node *max = root;
    while (max->kanan != NULL) max = max->kanan;

    printf("Nilai terkecil : %d\n", min->data);
    printf("Nilai terbesar : %d\n", max->data);

    return 0;
}