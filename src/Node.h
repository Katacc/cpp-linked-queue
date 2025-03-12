#ifndef NODE_H
#define NODE_H

#include <iostream>


typedef double Node_entry;


struct Node {

    Node_entry entry;
    Node *next;

    Node();
    Node(Node_entry item);
    Node(Node_entry item, Node *add_on);
    ~Node();

};




#endif /* NODE_H */