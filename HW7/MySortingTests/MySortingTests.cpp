// Program does runtime comparisons of the standard libraries sort function versus
// a custom-made Bubble sort and Insertion sort.
// Includes (1) a test on a random sequence,
// (2) a sequence where all elements are sorted except that the last two elements have been swapped,
// and (3) a sequence where all elements are sorted except that the first and last elements have been swapped.
// All of the sorting functions take a pair of iterators.
// The timing tests are done on vectors of ints and arrays of ints.
// - Jeff Ward

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <chrono>
#include <algorithm>
#include "MyBubbleSort.h"
#include "MyInsertionSort.h"

using namespace std;
using namespace std::chrono;

template <typename ITERATOR1, typename ITERATOR2>
bool checkEntriesEqual(ITERATOR1 begin1, ITERATOR1 end1, ITERATOR2 begin2, ITERATOR2 end2) {
    if (end1 - begin1 != end2 - begin2)
        return false; // lengths of the ranges don't match
    for ( ; begin1 != end1; begin1++, begin2++)
        if (*begin1 != *begin2)
            return false;
    return true;
}

int main() {
    srand(42);
    const unsigned int NUM_VALUES = 50000;
    vector<int> vec1, vec2, vec3;
    int* arr1 = new int[NUM_VALUES];
    int* arr2 = new int[NUM_VALUES];
    int* arr3 = new int[NUM_VALUES];

    cout << "Generating " << NUM_VALUES << " random values ..." << endl;
    for (unsigned int i = 0; i < NUM_VALUES; i++) {
        int value = rand();  // random int in the range 0 to RAND_MAX
        vec1.push_back(value);
        vec2.push_back(value);
        vec3.push_back(value);
        arr1[i] = arr2[i] = arr3[i] = value;
    }

    for (unsigned int i = 0; i < 3; i++) {
        cout << "Sorting each collection ..." << endl;
        auto start = high_resolution_clock::now();
        sort(vec1.begin(), vec1.end());
        auto stop = high_resolution_clock::now();
        double sortVectorDuration = duration_cast<microseconds>(stop - start).count() / 1000000.0;
        cout << "Time for sort on vec1: " << sortVectorDuration << " seconds" << endl;

        start = high_resolution_clock::now();
        sort(arr1, arr1 + NUM_VALUES);
        stop = high_resolution_clock::now();
        double sortArrayDuration = duration_cast<microseconds>(stop - start).count() / 1000000.0;
        cout << "Time for sort on arr1: " << sortArrayDuration << " seconds" << endl;
        if (!checkEntriesEqual(vec1.begin(), vec1.end(), arr1, arr1 + NUM_VALUES)) {
            cout << "ERROR:  vec1 and arr1 do not match!" << endl;
            exit(1);
        }

        start = high_resolution_clock::now();
        myBubbleSort(vec2.begin(), vec2.end());
        stop = high_resolution_clock::now();
        double bubbleSortVectorDuration = duration_cast<microseconds>(stop - start).count() / 1000000.0;
        cout << "Time for myBubbleSort on vec2: " << bubbleSortVectorDuration << " seconds" << endl;
        if (!checkEntriesEqual(vec1.begin(), vec1.end(), vec2.begin(), vec2.end())) {
            cout << "ERROR:  vec1 and vec2 do not match!" << endl;
            exit(1);
        }

        start = high_resolution_clock::now();
        myBubbleSort(arr2, arr2 + NUM_VALUES);
        stop = high_resolution_clock::now();
        double bubbleSortArrayDuration = duration_cast<microseconds>(stop - start).count() / 1000000.0;
        cout << "Time for myBubbleSort on arr2: " << bubbleSortArrayDuration << " seconds" << endl;
        if (!checkEntriesEqual(vec1.begin(), vec1.end(), arr2, arr2 + NUM_VALUES)) {
            cout << "ERROR:  vec1 and arr2 do not match!" << endl;
            exit(1);
        }

        start = high_resolution_clock::now();
        myInsertionSort(vec3.begin(), vec3.end());
        stop = high_resolution_clock::now();
        double insertionSortVectorDuration = duration_cast<microseconds>(stop - start).count() / 1000000.0;
        cout << "Time for myInsertionSort on vec3: " << insertionSortVectorDuration << " seconds" << endl;
        if (!checkEntriesEqual(vec1.begin(), vec1.end(), vec3.begin(), vec3.end())) {
            cout << "ERROR:  vec1 and vec3 do not match!" << endl;
            exit(1);
        }

        start = high_resolution_clock::now();
        myInsertionSort(arr3, arr3 + NUM_VALUES);
        stop = high_resolution_clock::now();
        double insertionSortArrayDuration = duration_cast<microseconds>(stop - start).count() / 1000000.0;
        cout << "Time for myInsertionSort on arr3: " << insertionSortArrayDuration << " seconds" << endl;
        if (!checkEntriesEqual(vec1.begin(), vec1.end(), arr3, arr3 + NUM_VALUES)) {
            cout << "ERROR:  vec1 and arr3 do not match!" << endl;
            exit(1);
        }


        if (i == 0) {  // Just now sorted random sequence of values
            if (insertionSortArrayDuration > (bubbleSortArrayDuration + 1) * 2) {
                cout << "myInsertionSort is too slow on array!" << endl;
                exit(1);
            }
            if (insertionSortVectorDuration > (bubbleSortVectorDuration + 1) * 2) {
                cout << "myInsertionSort is too slow on vector!" << endl;
                exit(1);
            }

            cout << "Swapping last two elements of each sorted collection ..." << endl;
            swap(vec1[NUM_VALUES - 2], vec1[NUM_VALUES - 1]);
            swap(vec2[NUM_VALUES - 2], vec2[NUM_VALUES - 1]);
            swap(vec3[NUM_VALUES - 2], vec3[NUM_VALUES - 1]);
            swap(arr1[NUM_VALUES - 2], arr1[NUM_VALUES - 1]);
            swap(arr2[NUM_VALUES - 2], arr2[NUM_VALUES - 1]);
            swap(arr3[NUM_VALUES - 2], arr3[NUM_VALUES - 1]);
        }
        else if (i == 1) { // Just now sorted sequences where at most the last two elements were out of order
            if (insertionSortArrayDuration > (bubbleSortArrayDuration + .01) * 2) {
                cout << "myInsertionSort is too slow on array!" << endl;
                exit(1);
            }
            if (insertionSortVectorDuration > (bubbleSortVectorDuration + .01) * 2) {
                cout << "myInsertionSort is too slow on vector!" << endl;
                exit(1);
            }

            cout << "Swapping first and last elements of each sorted collection ..." << endl;
            swap(vec1.front(), vec1.back());
            swap(vec2.front(), vec2.back());
            swap(vec3.front(), vec3.back());
            swap(arr1[0], arr1[NUM_VALUES - 1]);
            swap(arr2[0], arr2[NUM_VALUES - 1]);
            swap(arr3[0], arr3[NUM_VALUES - 1]);
        }
        else if (i == 2) {  // Just now sorted sequences where only the first and last elements were out of order:  bad for Bubble sort, good for Insertion sort.
            if (insertionSortArrayDuration > bubbleSortArrayDuration / 10.0) {
                cout << "myInsertionSort is too slow on array!" << endl;
                exit(1);
            }
            if (insertionSortVectorDuration > bubbleSortVectorDuration / 10.0) {
                cout << "myInsertionSort is too slow on vector!" << endl;
                exit(1);
            }
        }
    }

    cout << "All checks passed!" << endl;

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    return 0;
}
