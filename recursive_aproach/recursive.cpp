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

void removeDuplicatesRecursive(address first, int n) {
    if (n == 1 || first == nullptr) {
        return;
    }

    address temp = first;
    while (temp->next != nullptr) {
        if (first->data == temp->next->data) {
            address duplicate = temp->next;
            temp->next = temp->next->next;
            delete duplicate;
        } else {
            temp = temp->next;
        }
    }

    removeDuplicatesRecursive(first->next, n - 1);
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

int main() {
    // Adding elements to the list
    int n = 1500;
    for (int i = 1; i <= n; i++) {
        addElm(i);
        if (i % 50 == 0) addElm(i); 
    }

    // cout << "Original list: ";
    // printList(first);
    // cout << "\n\n";

   // auto start = high_resolution_clock::now();  // Start counting time

    removeDuplicatesRecursive(first, n);  


    // Print the list after duplicates removal
    // cout << "List after removing duplicates: ";
    // printList(first);

    //auto duration = duration_cast<milliseconds>(stop - start);  // Time in milliseconds

    //cout << "Execution Time: " << duration.count() << " ms" << endl;

    return 0;
}
