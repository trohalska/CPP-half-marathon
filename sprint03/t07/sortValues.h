#pragma once
#include <iostream>
#include <ostream>

template <class RandomAccessIterator>
RandomAccessIterator sortValues(RandomAccessIterator begin, RandomAccessIterator end) {
    RandomAccessIterator new_begin = begin;
    RandomAccessIterator min;

    int len = end - begin;
    if (len < 2)
        return begin;

    for (RandomAccessIterator i = begin; i != end; ++i) {
        min = i;
        for (RandomAccessIterator j = i; j != end; ++j)
            if (*j < *min)
                min = j;
        iter_swap(min, i);
    }
    return new_begin;
}

// template <class RandomAccessIterator>
// RandomAccessIterator sortValues(RandomAccessIterator begin, RandomAccessIterator end){
//     if (end <= begin)
//         return begin;
//     RandomAccessIterator pivot = begin, middle = begin + 1;
//     for (RandomAccessIterator i = begin + 1; i < end; ++i) {
//         if (*i < *pivot) {
//             std::iter_swap(i, middle);
//             ++middle;
//         }
//     }
//     std::iter_swap(begin, middle - 1);
//     sortValues(begin, middle - 1);
//     sortValues(middle, end);
//     return begin;
// }