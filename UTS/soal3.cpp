#include <iostream>
using namespace std;

#define MAX 100
int stack[MAX];
int top = -1;

void push(char value) {
if (top == MAX - 1) {
    cout << "Stack Penuh\n";
} else {
    top++;
    stack[top] == value;
    cout << value << "ditambahkan ke stack.\n";
}
}

char pop() {
    if (top == -1) {
        cout << "stack kosong\n";
    } else {
        cout << "\n " << stack [top] << " dihapus dari stack.\n";
        top--;
    }
}

int main() {
    string kata;

    cout << "Masukkan sebuah kata";
    cin >> kata;

    for (int i = 0; i < kata.length(); i++ ){
        push(kata[i]);
    }

    while(top != -1){
        cout << pop();
    }
    cout << endl;

    return 0;

}