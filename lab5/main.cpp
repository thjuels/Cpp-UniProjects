#include <iostream>
#include "queues.h"

void testQueueSystem(QueueSystem* system) {
    std::cout << "Enqueueing elements: 10, 30, 20, 40, 50\n";
    system->enqueue(10);
    system->enqueue(30);
    system->enqueue(20);
    system->enqueue(40);
    system->enqueue(50);

    std::cout << "Dequeuing five elements:\n";
    std::cout << system->dequeue() << std::endl;
    std::cout << system->dequeue() << std::endl;
    std::cout << system->dequeue() << std::endl;
    std::cout << system->dequeue() << std::endl;
    std::cout << system->dequeue() << std::endl;

    std::cout << "Attempt to dequeue from an empty queue:\n";
    std::cout << system->dequeue() << std::endl;  // Underflow test

    std::cout << "Enqueueing elements: 100, 110, 120, 130, 140, 150\n";
    system->enqueue(100);  
    system->enqueue(110);
    system->enqueue(120);
    system->enqueue(130);
    system->enqueue(140);
    system->enqueue(150);  // Overflow test

    std::cout << "Dequeuing five elements:\n";
    std::cout << system->dequeue() << std::endl;
    std::cout << system->dequeue() << std::endl;
    std::cout << system->dequeue() << std::endl;
    std::cout << system->dequeue() << std::endl;
    std::cout << system->dequeue() << std::endl;

    std::cout << "Attempt to dequeue from an empty queue:\n";
    std::cout << system->dequeue() << std::endl;  // Underflow test

    std::cout << "Enqueueing mixed elements: 5, 15, 5, 25, 35, 45\n";
    system->enqueue(5);  
    system->enqueue(15);
    system->enqueue(5);  // Duplicate value test
    system->enqueue(25);  
    system->enqueue(35);  
    system->enqueue(45);  // Overflow test

    std::cout << "Dequeuing five elements:\n";
    std::cout << system->dequeue() << std::endl;
    std::cout << system->dequeue() << std::endl;
    std::cout << system->dequeue() << std::endl;
    std::cout << system->dequeue() << std::endl;
    std::cout << system->dequeue() << std::endl;

    std::cout << "Attempt to dequeue from an empty queue:\n";
    std::cout << system->dequeue() << std::endl;  // Underflow test
}

int main() {
    std::cout << "Testing FIFO behavior:\n";
    QueueSystem* system = new QueueSystem(new FIFOQueue(5));
    testQueueSystem(system);

    std::cout << "\nTesting LIFO behavior:\n";
    delete system;
    system = new QueueSystem(new LIFOQueue(5));
    testQueueSystem(system);

    std::cout << "\nTesting Sorted behavior:\n";
    delete system;
    system = new QueueSystem(new SortedQueue(5));
    testQueueSystem(system);

    delete system;
    return 0;
}
