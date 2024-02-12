#include "queues.h"

QueueContainer::QueueContainer(int cap) : capacity(cap), size(0) {
    queue = new int[capacity];
}

QueueContainer::~QueueContainer() {
    delete[] queue;
}

int QueueContainer::getCapacity() const {
    return capacity;
}

int QueueContainer::getSize() const {
    return size;
}
