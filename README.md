# C++ Linked queue

This is my own implementation of linked queues aka node based queues. I wanted to write it from scrath to learn about the linked structure more in depth.

## Usage
Yoink the Node and Queue files to your project and include `Queue.h` to your program
```C++
#include "Queue.h"
```

Compile your software with the .cpp files for example:
```bash
g++ *.cpp -o app
```


Heres an example, an also example can be found from `main.cpp`
```C++
#include "Queue.h"

Queue que;
double item;
double last_item;

que.append(2);  // Adds an node with value of 2 to the Queue.
que.leng();  // Returns the length of the Queue
que.retrieve_first(item);   // Retrieves first element to a double called item
que.retrieve_last(last_item);   // Retrieves last element to a double called last_item
que.print_que();    // Prints the Queue.
que.serve();    // Removes the first element of the Queue.
que.empty();    // Empties the Queue.
que.serve_and_retrieve();   // Retrieves and deletes the first element of the Queue.
```