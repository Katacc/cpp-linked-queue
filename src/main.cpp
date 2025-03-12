#include <iostream>
#include "Node.h"
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
    que.leng();
    que.serve();
    que.serve();
    que.serve();
    que.append(10);
    que.append(12);
    que.leng();

    if (que.retrieve_first(item) == underflow) {
        cout << "Empty..." << endl;
    }

    if (que.retrieve_last(last_item) == underflow) {
        cout << "Empty..." << endl;
    }


    que.print_que();

}