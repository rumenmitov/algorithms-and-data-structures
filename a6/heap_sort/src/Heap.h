#ifndef __HEAP_H
#define __HEAP_H

#include <vector>
#include <ostream>

/**
 * @brief Heap data structure that supports sorting.
*/
class MaxHeap {

    public:
        // Constructors
        MaxHeap();
        MaxHeap(const std::vector<int>&);

        // Default destructor
        ~MaxHeap();

        // Overrides equality operator
        bool operator==(const MaxHeap&) const;

        // Printing to stream.
        friend std::ostream& operator<<(std::ostream&, const MaxHeap&);

        // Read-only access to underlying heap.
        const std::vector<int>& get_heap() const;



        /**
         * @brief Inserts value into the heap.
         * 
         * @param int val
         * 
         * @return void
        */
        void insert(int);
        

        /**
         * @brief Top-down heap-sort.
         * 
         * @return void
         */
        void sort(void);


        /**
         * @brief Bottom-up heap-sort.
         * 
         * @return void
         */
        void bottom_up_sort(void);




    private:
        int bottom;
        std::vector<int> heap;


        /**
         * @brief Heapifies from index down.
         *
         * @param int idx
         * 
         * @return void
        */
        void max_heapify(int);


        /**
         * @brief Checks if sub-tree is a heap.
         *
         * @param int idx
         * 
         * @return bool
        */
        bool isHeap(int);


};


#endif
