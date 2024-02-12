#include <iostream>
#include "queues.h" // Assuming all queue classes are in this header
using namespace std;

int main() {
    QueueSystem* system = new QueueSystem(new FIFOQueue(3));

    // Test FIFO behavior
    system->enqueue(10);
    system->enqueue(20);
    system->enqueue(30);
    cout << system->dequeue() << endl;  // 10
    cout << system->dequeue() << endl;  // 20
    cout << system->dequeue() << endl;  // 30
    cout << system->dequeue() << endl;  // Queue underflow.

    // Switch to LIFO behavior
    delete system;
    system = new QueueSystem(new LIFOQueue(3));
    system->enqueue(10);
    system->enqueue(20);
    system->enqueue(30);
    system->enqueue(40); // Queue overflow.
    cout << system->dequeue() << endl;  // 30
    cout << system->dequeue() << endl;  // 20

    // Test Sorted behavior
    delete system;
    system = new QueueSystem(new SortedQueue(3));
    system->enqueue(30);
    system->enqueue(10);
    system->enqueue(20);
    cout << system->dequeue() << endl;  // 10
    cout << system->dequeue() << endl;  // 20

    return 0;
}