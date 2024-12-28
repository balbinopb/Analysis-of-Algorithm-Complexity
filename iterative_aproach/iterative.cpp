#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

typedef struct Elm *address;

struct Elm {
    int data;
    address next;
};

address first = NULL;

void removeDuplicatesIterative(address first) {
    address current = first;
    while (current != NULL) {
        address temp = current;
        while (temp->next != NULL) {
            if (current->data == temp->next->data) {
                address duplicate = temp->next;
                temp->next = temp->next->next;
                delete duplicate;
            } else {
                temp = temp->next;
            }
        }
        current = current->next;
    }
}

void addElm(int value) {
    address newElm = new Elm();
    newElm->data = value;
    newElm->next = first;
    first = newElm;
}

void printList(address first) {
    while (first != NULL) {
        cout << first->data << " ";
        first = first->next;
    }
    cout << endl;
}

int main(){
    // Adding elements to the list
    for (int i = 1; i <= 1500; i++) {
        addElm(i);
        if (i % 50 == 0) addElm(i); 
    }

    cout << "Original list: ";
    printList(first);
    cout << "\n\n";

   // auto start = high_resolution_clock::now();  // Start counting time

    removeDuplicatesIterative(first);

    // auto stop = high_resolution_clock::now(); // Stop counting time
    // auto duration = duration_cast<microseconds>(stop - start); // Calculate time duration
    // cout << "Time taken by function: " << duration.count() << " microseconds" << endl;

    // cout << "List without duplicates: ";
    // printList(first);

    return 0;
}