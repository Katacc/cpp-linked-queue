#include <iostream>
#include "Queue.h"

using namespace std;


int main() {


    Queue que;

    double item;
    double last_item;

    que.append(2);
    que.append(3);
    que.append(5);
    que.append(6);
    cout << "Length of que: " << que.leng() << endl;
    que.serve();
    que.serve();
    que.serve();
    que.append(10);
    que.append(12);

    cout << "Length of que: " << que.leng() << endl;

    if (que.retrieve_first(item) == underflow) {
        cout << "Empty..." << endl;
    } else {
        cout << "First element: " << item << endl;
    }

    if (que.retrieve_last(last_item) == underflow) {
        cout << "Empty..." << endl;
    } else {
        cout << "Last element: " << last_item << endl;
    }


    que.print_que();


    cout << "Test 2: " << endl;

    que.empty();
    que.leng();


    que.print_que();


    cout << "\nTest 3:" << endl;
    que.append(10);
    que.append(12);

    que.print_que();

    double new_item;
    que.serve_and_retrieve(new_item);
    cout << "Retrieved and served node: " << new_item << endl;

    que.print_que();

    cout << "Test 4: " << endl;

    que.serve_and_retrieve(new_item);
    cout << "Retrieved and served node: " << new_item << endl;


    que.print_que();


    que.serve_and_retrieve(new_item);
    cout << "Retrieved and served node: " << new_item << endl;


    return 0;

}