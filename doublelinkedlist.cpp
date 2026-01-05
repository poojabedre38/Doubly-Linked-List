#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;  

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void insertEnd(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
           
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    void displayForward() {
        Node* temp = head;
        cout << "List forward: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void displayBackward() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        cout << "List backward: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;

    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);
    list.insertEnd(40);

    list.displayForward();
    list.displayBackward();

    return 0;
}
