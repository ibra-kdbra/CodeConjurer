#include "ds/Heap.h"
#include <iostream>

// Comparator function for heap ordering
bool Heap::comparator(int left, int right) {
    if (heapType == MIN) {
        return left < right; // Min-heap: parent < children
    } else {
        return left > right; // Max-heap: parent > children
    }
}

Heap::Heap(bool type) : heapType(type) {}

void Heap::printHeap() const {
    std::cout << "Heap: ";
    for (int val : heap) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

// Heapify up (bubble up)
void heapifyUp(std::vector<int>& heap, int index, bool(*comp)(int, int, bool), bool heapType) {
    int parent = (index - 1) / 2;
    while (index > 0 && comp(heap[index], heap[parent], heapType)) {
        std::swap(heap[index], heap[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

// Heapify down (sink down)
void heapifyDown(std::vector<int>& heap, int index, int size, bool(*comp)(int, int, bool), bool heapType) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    // Check left child
    if (left < size && comp(heap[left], heap[smallest], heapType)) {
        smallest = left;
    }

    // Check right child
    if (right < size && comp(heap[right], heap[smallest], heapType)) {
        smallest = right;
    }

    // Swap and continue heapifying if needed
    if (smallest != index) {
        std::swap(heap[index], heap[smallest]);
        heapifyDown(heap, smallest, size, comp, heapType);
    }
}

void Heap::insert(int x) {
    heap.push_back(x);
    heapifyUp(heap, heap.size() - 1, [](int a, int b, bool type) {
        return type == MIN ? a < b : a > b;
    }, heapType);
}

int Heap::extract() {
    if (heap.empty()) {
        throw std::logic_error("extract: Heap empty");
    }

    int root = heap[0];
    heap[0] = heap.back();
    heap.pop_back();

    if (!heap.empty()) {
        heapifyDown(heap, 0, heap.size(), [](int a, int b, bool type) {
            return type == MIN ? a < b : a > b;
        }, heapType);
    }

    return root;
}
