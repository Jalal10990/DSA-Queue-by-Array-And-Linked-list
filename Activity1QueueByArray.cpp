#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;     // pointer to dynamic array (not just int)
    int qFront;   // index of front element
    int rear;     // index for next insertion
    int size;     // total capacity

public:
    // constructor
    Queue() {
        size = 10001;
        arr = new int[size];
        qFront = 0;
        rear = 0;
    }

    // destructor
    ~Queue() {
        delete[] arr;
    }

    // check if queue is empty
    bool isEmpty() {
        return qFront == rear;
    }

    // add (enqueue) element
    void enqueue(int data) {
        if (rear == size) {
            cout << "Queue is Full" << endl;
        } else {
            arr[rear] = data;
            rear++;
        }
    }

    // remove (dequeue) element
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return -1;
        } else {
            int ans = arr[qFront];
            arr[qFront] = -1;
            qFront++;
            // reset when queue becomes empty
            if (qFront == rear) {
                qFront = 0;
                rear = 0;
            }
            return ans;
        }
    }

    // view front element
    int front() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return -1;
        } else {
            return arr[qFront];
        }
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front: " << q.front() << endl; 
    cout << "Dequeued: " << q.dequeue() << endl; 
    cout << "Dequeued: " << q.dequeue() << endl; 

    cout << "Is empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    cout << "Dequeued: " << q.dequeue() << endl; 
    cout << "Dequeued: " << q.dequeue() << endl; 
    cout << "Is empty? " << (q.isEmpty() ? "Yes" : "No") << endl; 

    return 0;
}
