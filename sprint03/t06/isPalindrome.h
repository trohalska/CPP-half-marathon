#pragma once
#include <iostream>
#include <ostream>
#include <algorithm>

template <class BidirectionalIterator>
bool isPalindrome(BidirectionalIterator begin, BidirectionalIterator end) {
    auto p_end = --end;
    while(begin != p_end) {
        if (*(begin++) != *(end--))
            return false;
    }
    return true;
}

// template <class BidirectionalIterator>
// bool isPalindrome(BidirectionalIterator begin, BidirectionalIterator end) {
//     return equal(begin, std::next(begin, std::distance(begin,end)/2), std::make_reverse_iterator(end));
// }