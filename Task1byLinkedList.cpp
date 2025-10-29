
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Queue {
public:
    Node* front;
    Node* rear;

    Queue() {
      
    }

    bool isEmpty() {
        return front == NULL;
    }

    void enQue(int val) { 
         front = rear = NULL;
        Node* temp = new Node;
        temp->data = val;
        temp->next = NULL;
        if (isEmpty()) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
    }

    int deQue() {
        int tempData;
        if (!isEmpty()) {
            Node* temp = front;
            tempData = front->data;
            front = front->next;
            delete temp;
            if (front == NULL)
                rear = NULL;
        } else {
            cout << "Queue Empty\n";
            tempData = -1;
        }
        return tempData;
    }

    void display() {
        if (isEmpty())
            cout << "Queue Empty\n";
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
    Queue q;
    q.enQue(10);
    q.enQue(2);
    q.enQue(6);
    q.display();
    q.deQue();
    q.display();
}
