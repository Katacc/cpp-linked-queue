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


Queue::~Queue() {
    delete this;
}

Error_code Queue::append(const Queue_entry &item) {


    Node *p0 = new Node(item);

    if (first_node == nullptr) {
        first_node = p0;
        last_node = p0;

        first_node->next = last_node;

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
    if (first_node == nullptr) {
        return underflow;

    } else {

        first_node = first_node->next;
        count--;

        return success;
    }
}

void Queue::leng() {
    std::cout << "length of queue: " << count << std::endl;
}

void Queue::print_que() {
    using namespace std;

    if (first_node == nullptr) {
        cout << "Queue empty..." << endl;
    } else {

        cout << "Printed queue: " << endl;
        Queue_entry value;

        Queue temp_que = *this;
        while (temp_que.count > 0) {
            temp_que.retrieve_first(value);
            cout << value << endl;
            temp_que.serve();
        }

    }

}

