#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "Node.h"

enum Error_code { success, overflow, underflow };
typedef double Queue_entry;

const int maxqueue = 10; //  small value for testing

class Queue {

public:

    Queue();
    Queue(const Queue &obj);
    Queue& operator=(const Queue &obj);
    ~Queue();

    Error_code append(const Queue_entry &item);
    Error_code retrieve_first(Queue_entry &item) const;
    Error_code retrieve_last(Queue_entry &item) const;
    Error_code serve();
    Error_code empty();
    void print_que() const;
    int leng() const;

protected:
    int count;
    int front, rear;
    Node *first_node;
    Node *last_node;

};


#endif /* QUEUE_H */