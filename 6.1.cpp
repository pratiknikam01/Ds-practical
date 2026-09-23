#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class ArrayQueue {
private:
    string queue[MAX];
    int front, rear;

public:
    ArrayQueue() {
        front = -1;
        rear = -1;
    }

    void enqueue(string request) {
        if (rear == MAX - 1) {
            cout << "Queue is full!" << endl;
            return;
        }

        if (front == -1) {
            front = 0;
        }

        rear++;
        queue[rear] = request;

        cout << "Request added: " << request << endl;
    }


    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Request processed: " << queue[front] << endl;
        front++;

        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Ticket Reservation Queue:" << endl;

        for (int i = front; i <= rear; i++) {
            cout << queue[i] << endl;
        }
    }
};

int main() {
    ArrayQueue ticketQueue;

    ticketQueue.enqueue("Reservation for Rahul - Train 101");
    ticketQueue.enqueue("Reservation for Priya - Train 102");
    ticketQueue.enqueue("Reservation for Amit - Train 103");
    ticketQueue.enqueue("Reservation for Sneha - Train 104");


    cout << "\n";
    ticketQueue.display();

    cout << "\nProcessing requests:\n";
    ticketQueue.dequeue();
    ticketQueue.dequeue();

    cout << "\nRemaining requests:\n";
    ticketQueue.display();

    return 0;
}
