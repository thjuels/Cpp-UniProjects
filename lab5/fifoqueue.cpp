#include "queues.h"

FIFOQueue::FIFOQueue(int cap) : QueueContainer(cap) {}

void FIFOQueue::enqueue(int element) {
    if (size < capacity) {
        queue[size++] = element;
    } else {
        std::cout << "Queue overflow." << std::endl;
    }
}

int FIFOQueue::dequeue() {
    if (size > 0) {
        int front = queue[0];
        for (int i = 1; i < size; i++) {
            queue[i-1] = queue[i];
        }
        size--;
        return front;
    } else {
        std::cout << "Queue underflow." << std::endl;
        return -1;  
    }
}