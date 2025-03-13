#include <iostream>
#include "Queue.h"
#include "Node.h"

using namespace std;



Queue::Queue() {

    first_node = nullptr;
    last_node = nullptr;
    count = 0;
    front = 0;
    rear = 0;

}

Queue::Queue(const Queue &obj) {


    first_node = nullptr;
    last_node = nullptr;
    count = 0;
    front = 0;
    rear = 0;


    Node *current = obj.first_node;
    while (current != nullptr) {
        this->append(current->entry);
        current = current->next;
    }

}

Queue& Queue::operator=(const Queue &obj) {
    if (this != &obj) {

        // Clearing the Queue
        while (first_node != nullptr) {
            Node* temp = first_node;
            first_node = first_node->next;
            delete temp;
        }

        // Resetting members
        first_node = nullptr;
        last_node = nullptr;
        count = 0;
        front = 0;
        rear = 0;

        // Copy nodes
        Node *current = obj.first_node;
        while (current != nullptr) {
            this->append(current->entry);
            current = current->next;
        }
    }

    return *this;
}


Queue::~Queue() {
    while(first_node != nullptr) {
        Node* temp = first_node;
        first_node = first_node->next;
        delete temp;
    }
}

Error_code Queue::append(const Queue_entry &item) {


    Node *p0 = new Node(item);

    if (first_node == nullptr) {
        first_node = p0;
        last_node = p0;

    } else {
        last_node->next = p0;
        last_node = p0;
    }

    count++;

    return success;

}

Error_code Queue::retrieve_first(Queue_entry &item) const {

    if (first_node == nullptr) {
        return underflow;
    } else {
        item = first_node->entry;
        return success;
    }
}

Error_code Queue::retrieve_last(Queue_entry &item) const {

    if (last_node == nullptr) {
        return underflow;
    } else {
        item = last_node->entry;
        return success;
    }

}

Error_code Queue::serve() {

    Node *old_first = first_node;

    if (count == 0) {
        return underflow;

    } else {

        first_node = old_first->next;
        count--;


        return success;
    }

    delete old_first;
}

Error_code Queue::serve_and_retrieve(Queue_entry &item) {
    if (retrieve_first(item) == underflow) return underflow;
    if (serve() == underflow) return underflow;

    return success;
}

Error_code Queue::empty() {
    using namespace std;


    if (first_node == nullptr) {
        cout << "Queue empty..." << endl;
        return underflow;
    } else {
        while (count > 0) {
            serve();
        }
        return success;
    }

}

int Queue::leng() const {
    return count;
}

void Queue::print_que() const {
    using namespace std;

    if (count == 0) {
        cout << "Queue empty..." << endl;

    } else {

        cout << "Printed queue: " << endl;
        double value;

        Queue temp_que = *this;

        while (temp_que.count > 0) {
            temp_que.retrieve_first(value);
            cout << value << endl;
            if (temp_que.serve() == underflow) {
                break;
            }
        }


        cout << endl;

    }

}

