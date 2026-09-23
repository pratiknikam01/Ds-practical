#include <iostream>
#include <string>
using namespace std;

struct Node {
    string request;
    Node* next;

    Node(string r) {
        request = r;
        next = NULL;
    }
};

class LinkedQueue {
private:
    Node* front;
    Node* rear;

public:
    LinkedQueue() {
        front = NULL;
        rear = NULL;
    }

    void enqueue(string request) {
        Node* newNode = new Node(request);

        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Request added: " << request << endl;
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue is empty!" << endl;
            return;
        }

        Node* temp = front;

        cout << "Request processed: " << front->request << endl;

        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

        delete temp;
    }


    void display() {
        if (front == NULL) {
            cout << "Queue is empty!" << endl;
            return;
        }

        Node* temp = front;

        cout << "\nTicket Reservation Queue:\n";

        while (temp != NULL) {
            cout << temp->request << endl;
            temp = temp->next;
        }
    }

    ~LinkedQueue() {
        while (front != NULL) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
        rear = NULL;
    }
};

int main() {
    LinkedQueue ticketQueue;

    ticketQueue.enqueue("Reservation for Rahul - Train 101");
    ticketQueue.enqueue("Reservation for Priya - Train 102");
    ticketQueue.enqueue("Reservation for Amit - Train 103");
    ticketQueue.enqueue("Reservation for Sneha - Train 104");

    ticketQueue.display();

    cout << "\nProcessing requests:\n";
    ticketQueue.dequeue();
    ticketQueue.dequeue();

    ticketQueue.display();

    return 0;
}
