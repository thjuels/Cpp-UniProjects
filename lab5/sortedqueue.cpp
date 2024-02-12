#include "queues.h"

SortedQueue::SortedQueue(int cap) : QueueContainer(cap) {}

void SortedQueue::enqueue(int element) {
    if (size < capacity) {
        int i;
        for (i = size - 1; i >= 0 && queue[i] < element; i--) {
            queue[i + 1] = queue[i];
        }
        queue[i + 1] = element;
        size++;
    } else {
        std::cout << "Queue overflow." << std::endl;
    }
}

int SortedQueue::dequeue() {
    if (size > 0) {
        return queue[--size];
    } else {
        std::cout << "Queue underflow." << std::endl;
        return -1; 
    }
}
