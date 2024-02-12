#ifndef QUEUES_H
#define QUEUES_H

#include <iostream>

// Base class
class QueueContainer {
protected:
    int capacity;
    int size;
    int* queue;
public:
    QueueContainer(int cap);
    virtual ~QueueContainer();

    virtual void enqueue(int element) = 0;  // Pure virtual function
    virtual int dequeue() = 0;  // Pure virtual function

    int getCapacity() const;
    int getSize() const;
};

class LIFOQueue : public QueueContainer {
public:
    LIFOQueue(int cap);
    void enqueue(int element) override;
    int dequeue() override;
};

class FIFOQueue : public QueueContainer {
public:
    FIFOQueue(int cap);
    void enqueue(int element) override;
    int dequeue() override;
};

class SortedQueue : public QueueContainer {
public:
    SortedQueue(int cap);
    void enqueue(int element) override;
    int dequeue() override;
};

class QueueSystem {
private:
    QueueContainer* queue;
public:
    QueueSystem(QueueContainer* queue);
    ~QueueSystem();
    
    void enqueue(int element);
    int dequeue();
};

#endif  // QUEUES_H
