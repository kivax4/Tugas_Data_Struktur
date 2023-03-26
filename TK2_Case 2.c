#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 10

typedef struct {
    char name[30];
    int age;
} Customer;

typedef struct {
    Customer data[MAX_QUEUE_SIZE];
    int head;
    int tail;
    int size;
} Queue;

// Prosedur untuk menginisialisasi queue
void initQueue(Queue *q) {
    q->head = 0;
    q->tail = -1;
    q->size = 0;
}

// Fungsi untuk mengecek apakah queue kosong
int isQueueEmpty(Queue *q) {
    return (q->size == 0);
}

// Fungsi untuk mengecek apakah queue penuh
int isQueueFull(Queue *q) {
    return (q->size == MAX_QUEUE_SIZE);
}

// Prosedur untuk menambahkan data konsumen ke dalam queue
void enqueue(Queue *q, Customer c) {
    if (isQueueFull(q)) {
        printf("Queue sudah penuh!\n");
    } else {
        q->tail = (q->tail + 1) % MAX_QUEUE_SIZE;
        q->data[q->tail] = c;
        q->size++;
        printf("Konsumen %s telah masuk antrian.\n", c.name);
    }
}

// Fungsi untuk mengeluarkan data konsumen dari queue
Customer dequeue(Queue *q) {
    Customer c = {"", 0};
    if (isQueueEmpty(q)) {
        printf("Queue masih kosong!\n");
    } else {
        c = q->data[q->head];
        q->head = (q->head + 1) % MAX_QUEUE_SIZE;
        q->size--;
        printf("Konsumen %s telah keluar antrian.\n", c.name);
    }
    return c;
}

// Program utama
int main() {
    Queue q;
    initQueue(&q);
    int choice = 0;

    while (choice != 3) {
        printf("\nMenu:\n");
        printf("1. Masukkan konsumen ke dalam antrian\n");
        printf("2. Keluarkan konsumen dari antrian\n");
        printf("3. Keluar dari program\n");
        printf("Pilihan Anda: ");
        scanf("%d", &choice);

        if (choice == 1) {
            Customer c;
            printf("\nMasukkan nama konsumen: ");
            scanf("%s", c.name);
            printf("Masukkan usia konsumen: ");
            scanf("%d", &c.age);
            enqueue(&q, c);
        } else if (choice == 2) {
            Customer c = dequeue(&q);
        }
    }

    return 0;
}
