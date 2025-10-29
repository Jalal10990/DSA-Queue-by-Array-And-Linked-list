
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
};

class Deque {
public:
    Node* front;
    Node* rear;

    Deque() {
        front = rear = NULL;
    }

    bool isEmpty() {
        return front == NULL;
    }

    void insertFront(int val) {
        Node* temp = new Node;
        temp->data = val;
        temp->next = front;
        temp->prev = NULL;
        if (isEmpty())
            rear = temp;
        else
            front->prev = temp;
        front = temp;
    }

    void insertRear(int val) {
        Node* temp = new Node;
        temp->data = val;
        temp->next = NULL;
        temp->prev = rear;
        if (isEmpty())
            front = temp;
        else
            rear->next = temp;
        rear = temp;
    }

    int deleteFront() {
        if (isEmpty()) {
            cout << "Deque Empty\n";
            return -1;
        }
        int val = front->data;
        Node* temp = front;
        front = front->next;
        if (front)
            front->prev = NULL;
        else
            rear = NULL;
        delete temp;
        return val;
    }

    int deleteRear() {
        if (isEmpty()) {
            cout << "Deque Empty\n";
            return -1;
        }
        int val = rear->data;
        Node* temp = rear;
        rear = rear->prev;
        if (rear)
            rear->next = NULL;
        else
            front = NULL;
        delete temp;
        return val;
    }

    void display() {
        if (isEmpty())
            cout << "Deque Empty\n";
        else {
            Node* temp = front;
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    Deque d;
    d.insertRear(17);
    d.insertRear(6);
    d.insertFront(5);
    d.display();
    d.deleteFront();
    d.display();
    d.deleteRear();
    d.display();
}
