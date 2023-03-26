#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

// Definisi struktur stack
typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

// Fungsi push, untuk menambahkan karakter ke dalam stack
void push(Stack *s, char c) {
    s->top++;
    s->data[s->top] = c;
}

// Fungsi pop, untuk mengeluarkan karakter dari stack
char pop(Stack *s) {
    char c = s->data[s->top];
    s->top--;
    return c;
}

// Fungsi untuk reverse string
void reverseString(char* str) {
    Stack s;
    s.top = -1;
    int i;

    // Memasukkan karakter-karakter ke dalam stack
    for (i = 0; i < strlen(str); i++) {
        push(&s, str[i]);
    }

    // Mengeluarkan karakter-karakter dari stack untuk membentuk string yang sudah terbalik
    for (i = 0; i < strlen(str); i++) {
        str[i] = pop(&s);
    }
}

// Program utama
int main() {
    char str[MAX_SIZE];
    printf("Masukkan string: ");
    fgets(str, MAX_SIZE, stdin);
    str[strcspn(str, "\n")] = '\0';

    // Memanggil fungsi untuk reverse string
    reverseString(str);

    printf("String setelah dibalik: %s", str);
    return 0;
}
