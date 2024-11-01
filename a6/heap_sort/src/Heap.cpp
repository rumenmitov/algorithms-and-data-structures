#include <ostream>

#include "Heap.h"


MaxHeap::MaxHeap() {
    heap.push_back(0);
    bottom = 1;
};

MaxHeap::MaxHeap(const std::vector<int>& arr) {
    heap.push_back(0);
    bottom = 1;

    for (int x : arr) insert(x);
}


MaxHeap::~MaxHeap() {}

bool MaxHeap::operator==(const MaxHeap& other) const { 
    return heap == other.heap; 
}

std::ostream& operator<<(std::ostream& f, const MaxHeap& max_heap) {
    for (int x : max_heap.heap) {
        f << x << " ";
    }

    return f;
}

const std::vector<int>& MaxHeap::get_heap() const {
    return heap;
}

void MaxHeap::insert(int val) {
    heap.push_back(val);

    int idx = bottom;

    while (idx / 2 > 0) {

        if (heap[idx] > heap[idx / 2]) {
            std::swap(heap[idx], heap[idx / 2]);
        } else break;

    }

    bottom++;
}

void MaxHeap::max_heapify(int idx) {

    // INFO: Base Case
    if (idx * 2 >= bottom) return;

    if (idx * 2 + 1 >= bottom && heap[idx] < heap[idx * 2]) {
        std::swap(heap[idx], heap[idx * 2]);
        return max_heapify(idx * 2);
    }

    if (heap[idx * 2] >= heap[idx * 2 + 1]) {
        std::swap(heap[idx], heap[idx * 2]);
        return max_heapify(idx * 2);
    } else {
        std::swap(heap[idx], heap[idx * 2 + 1]);
        return max_heapify(idx * 2 + 1);
    }
}

void MaxHeap::sort(void) {
    int original_length = bottom;
    while (bottom > 1) {
        bottom--;
        std::swap(heap[bottom], heap[1]);
        max_heapify(1);
    }

    bottom = original_length;
}

void MaxHeap::bottom_up_sort(void) {
    int original_length = bottom;
    while (bottom > 1) {
        bottom--;
        std::swap(heap[bottom], heap[1]);
        std::swap(heap[1], heap[bottom - 1]);

        if ( !isHeap(1) ) {
            std::swap(heap[bottom - 1], heap[1]);
            max_heapify(1);
        }
    }

    bottom = original_length;

}

bool MaxHeap::isHeap(int idx) {
    if (idx < 1) return false;
    if (idx >= bottom) return false;

    if (idx * 2 >= bottom) return true;
    if (idx * 2 + 1 >= bottom) return true;

    if (heap[idx] >= heap[idx * 2] && heap[idx] >= heap[idx * 2 + 1]) {
        return isHeap(idx * 2) && isHeap(idx * 2 + 1);
    }

    return false;
}
