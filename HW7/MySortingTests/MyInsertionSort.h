// Created by Justin Gallagher on 12/9/2020.
// The purpose of this program is to implement the insertion sort in C++.

#ifndef MYSORTINGTESTS_MYINSERTIONSORT_H
#define MYSORTINGTESTS_MYINSERTIONSORT_H

#include <iterator>

using namespace std;

template <typename RandomAccessIterator>
void myInsertionSort(RandomAccessIterator beginIter, RandomAccessIterator endIter) {
    if (beginIter == endIter || beginIter + 1 == endIter) {
        return;
    }
    for (RandomAccessIterator curr = beginIter; curr < endIter; curr++){
        typename iterator_traits<RandomAccessIterator>::value_type tp = *curr; //pointer to curr
        RandomAccessIterator temp = curr - 1;
        for (; temp >= beginIter && *temp > tp; temp--) {
            *(temp + 1) = *temp;
        }
        *(temp + 1) = tp;
    }
}

#endif //MYSORTINGTESTS_MYINSERTIONSORT_H
