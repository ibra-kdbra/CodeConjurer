#include "ds/CircularQueue.h"
#include <iostream>

bool CircularQueue::enQueue(int element) {
    if (qfull()) {
        std::cout << "Queue is full" << std::endl;
        return false;
    }

    if (front == -1) {
        front = 0;
    }

    rear = (rear + 1) % size;
    cq[rear] = element;
    return true;
}

int CircularQueue::deQueue() {
    if (qempty()) {
        std::cout << "Queue is empty" << std::endl;
        throw std::runtime_error("Queue is empty");
    }

    int element = cq[front];

    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % size;
    }

    return element;
}

bool CircularQueue::qfull() const {
    return (rear + 1) % size == front;
}

bool CircularQueue::qempty() const {
    return front == -1;
}
