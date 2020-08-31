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
