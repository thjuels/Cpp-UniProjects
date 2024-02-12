#include "queues.h"

QueueSystem::QueueSystem(QueueContainer* queue) : queue(queue) {}

QueueSystem::~QueueSystem() {
    delete queue;
}

void QueueSystem::enqueue(int element) {
    queue->enqueue(element);
}

int QueueSystem::dequeue() {
    return queue->dequeue();
}
