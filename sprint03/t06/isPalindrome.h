#pragma once
#include <iostream>
#include <ostream>

template <class BidirectionalIterator>
bool isPalindrome(BidirectionalIterator begin, BidirectionalIterator end) {
    auto p_end = --end;
    while(begin != p_end) {
        if (*(begin++) != *(end--))
            return false;
    }
    return true;
}
