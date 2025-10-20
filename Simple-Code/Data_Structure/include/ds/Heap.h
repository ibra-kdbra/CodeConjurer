#ifndef HEAP_H
#define HEAP_H

#define MIN true
#define MAX false

#include <iostream>
#include <bits/stdc++.h>

class Heap {
 private:
  bool comparator(int left, int right);
 public:
  std::vector<int> heap;
  bool heapType;
  Heap(bool heapType = MIN);
  void printHeap() const;
  void insert(int x);
  int extract();
  bool empty() {
    return heap.size() == 0;
  }
  int size() {
    return heap.size();
  }
  int top() {
    if(heap.empty()) {
        throw std::logic_error("top : Heap empty");
    }
    return heap[0];
  }
};
#endif
