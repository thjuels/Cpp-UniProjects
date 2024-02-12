#include "queues.h"

LIFOQueue::LIFOQueue(int cap) : QueueContainer(cap) {}

void LIFOQueue::enqueue(int element) {
    if (size < capacity) {
        queue[size++] = element;
    } else {
        std::cout << "Queue overflow." << std::endl;
    }
}

int LIFOQueue::dequeue() {
    if (size > 0) {
        return queue[--size];
    } else {
        std::cout << "Queue underflow." << std::endl;
        return -1;  // Sentinel value
    }
}