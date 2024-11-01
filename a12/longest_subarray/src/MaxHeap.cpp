#include "MaxHeap.h"

MaxHeap::MaxHeap() {
    std::deque<int> empty {};
    heap.push_back(empty);
};


MaxHeap::~MaxHeap() {};


void MaxHeap::heapify_up(unsigned int idx) {
    if (idx <= 1) return;

    if (heap[idx / 2].size() < heap[idx].size()) {
        std::swap(heap[idx / 2], heap[idx]);
        heapify_up(idx / 2);
    }
}


void MaxHeap::heapify_down(unsigned int idx) {
    if (idx >= heap.size() - 1) return;

    if (2 * idx >= heap.size() -1) return;

    if (2 * idx + 1 >= heap.size() - 1) {
        if (heap[2 * idx].size() > heap[idx].size()) {
            std::swap(heap[2 * idx], heap[idx]);
            heapify_down(2 * idx);
        }
    }

    if (heap[idx].size() >= heap[2 * idx].size() 
            && heap[idx].size() >= heap[2 * idx + 1].size())
    {
        return;
    } else if (heap[idx].size() >= heap[2 * idx].size()
            && heap[idx].size() < heap[2 * idx + 1].size())
    {
        std::swap(heap[2 * idx + 1], heap[idx]);
        heapify_down(2 * idx + 1);
    } else {
        std::swap(heap[2 * idx], heap[idx]);
        heapify_down(2 * idx);
    }
}


void MaxHeap::insert(const std::deque<int>& deq) {
    heap.push_back(deq);
    heapify_up(heap.size() - 1);
}


const std::deque<int> MaxHeap::peek() const {
    return heap[1];
}
