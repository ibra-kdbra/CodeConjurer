#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

#include <iostream>

class CircularQueue {
private:
    int rear;
    int front;
    int size = 10;
    int cq[10] = {0};
public:
    CircularQueue() : rear(-1), front(-1) {}

    bool enQueue(int element);
    int deQueue();
    bool qfull() const;
    bool qempty() const;
    int getSize() const { return size; }
    int* getCq() { return cq; }
    int getFront() const { return front; }
    int getRear() const { return rear; }
};

#endif // CIRCULARQUEUE_H
