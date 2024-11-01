#include <iostream>
#include <vector>

#ifdef DEBUG
#include <cassert>
#endif

#include "CountSort.h"
#include "BucketSort.h"
#include "RadixSort.h"
#include "Utils.h"


using namespace std;

int main(void) {

#ifdef DEBUG

    vector<int> test_insertion_sort { 4, 4, 2, 1, 6, 7 };
    vector<int> solution_insertion_sort { 1, 2, 4, 4, 6, 7 };

    cout << "Testing insertion sort...";
    insertion_sort(test_insertion_sort);
    assert(test_insertion_sort == solution_insertion_sort);
    cout << "passed.\n";


    vector<string> test_count_sort_nth_byte
        { "100", "000", "319", "255" };

    vector<string> solution_count_sort_nth_byte 
        { "000", "100", "255", "319" };

    cout << "Testing count sort at n-th byte...";
    assert(
            count_sort_nth_byte(
                test_count_sort_nth_byte, 0, 0, test_count_sort_nth_byte.size()) 
            == solution_count_sort_nth_byte 
            );
    cout << "passed.\n";


    vector<string> test_hollerith_radix_sort 
        { "100", "000", "254", "319", "255" };

    vector<string> solution_hollerith_radix_sort 
        { "000", "100", "254", "255", "319" };

    cout << "Testing Hollerith's radix sort...";
    assert(
            hollerith_radix_sort(
                test_hollerith_radix_sort, 0, 0, test_hollerith_radix_sort.size()) 
            == solution_hollerith_radix_sort 
            );
    cout << "passed.\n";

#endif

    cout << endl;
    cout << "  /--------------/" << endl;
    cout << " /  Homework 8  /" << endl;
    cout << "/--------------/" << endl;
    cout << endl;

    vector<int> count_sort_seq { 9, 1, 6, 7, 6, 2, 1 };
    vector<float> bucket_sort_seq { 0.9, 0.1, 0.6, 0.7, 0.6, 0.3, 0.1 };

    cout << "Sorting sequence:\n" 
        << count_sort_seq 
        << endl
        << "with count-sort:\n"
        << count_sort(count_sort_seq)
        << endl
        << endl;

    cout << "Sorting sequence:\n" 
        << bucket_sort_seq 
        << endl
        << "with bucket sort:\n"
        << bucket_sort(bucket_sort_seq)
        << endl
        << endl;

    unsigned int n = 0, k = 0;

    cout << "How many words would you like to sort? Enter interger: ";
    cin >> n;

    std::vector<std::string> word_arr;
    std::string word;

    while (n > 0) {
        cout << "Enter word: ";
        cin >> word;

        if (word.size() >= k) k = word.size();

        word_arr.push_back(word);
        n--;
    }

    for (auto& word : word_arr) {
        while (word.size() < k) word = '\0' + word;
    }

    cout << "Sorting sequence:\n" 
        << word_arr
        << endl
        << "with radix sort:\n"
        << radix_sort(word_arr, k)
        << endl
        << endl;

#ifndef DEBUG
    cout << "For Hollerith's Radix Sort please run `make debug`!"
        << endl
        << endl;
#endif



    return 0;
}
