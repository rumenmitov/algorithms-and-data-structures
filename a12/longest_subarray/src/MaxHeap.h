#pragma once


#include <deque>
#include <vector>


struct MaxHeap {

        MaxHeap();
        ~MaxHeap();

        void heapify_up(unsigned int);
        void heapify_down(unsigned int);
        void insert(const std::deque<int>&);
        const std::deque<int> peek() const;

        std::vector<std::deque<int>> heap;


};

