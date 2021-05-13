//
// Created by wardj1 on 11/24/2020.
//

#ifndef MYSORTINGTESTS_MYBUBBLESORT_H
#define MYSORTINGTESTS_MYBUBBLESORT_H

#include <iterator>

using namespace std;

template <typename RandomAccessIterator>
void myBubbleSort(RandomAccessIterator beginIter, RandomAccessIterator endIter) {
    if (beginIter == endIter || beginIter + 1 == endIter)
        return;  // no elements in the range or only one element in the range:  no need to sort
    bool needNextPass = true;
    int length = endIter - beginIter;
    for (RandomAccessIterator endOfPass = endIter - 1; endOfPass != beginIter && needNextPass; endOfPass--) {
        needNextPass = false;
        for (RandomAccessIterator current = beginIter; current != endOfPass; current++)
            if (*current > *(current + 1)) {
                typename iterator_traits<RandomAccessIterator>::value_type temp = *current;
                *current = *(current + 1);
                *(current + 1) = temp;
                needNextPass = true;
            }
    }
}

#endif //MYSORTINGTESTS_MYBUBBLESORT_H
