#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

// [from, to]
template <typename T>
bool IsInRange(const T& val, const T& from, const T& to) {
    return val >= from && val <= to;
}
template <typename T>
bool IsInRange(const T& val, const std::pair<const T&, const T&>& minmax) {
    return val >= minmax.first && val <= minmax.second;
}
// (from, to)
template <typename T>
bool IsInsideRange(const T& val, const T& from, const T& to) {
    return val > from && val < to;
}
template <typename T>
bool IsInsideRange(const T& val, const std::pair<const T&, const T&>& minmax) {
    return val > minmax.first && val < minmax.second;
}
// change the object if necessary
// and return the corresponding value of the operation success
// Modify(v, 22)
template <class T, class U = T>
bool Modify(T& obj, U&& new_value) {
    if (obj == new_value) {
        return false;
    }
    else {
        obj = std::forward<T>(new_value);
        return true;
    }
}
// RemoveAll(i, 1);
template <class Collection, class T>
void RemoveAll(Collection& c, const T& value) {
    c.erase(std::remove(c.begin(), c.end(), value), c.end());
}
// RemoveAllIf(i, [](int x){return x > 2;});
template <class Collection, class Pred>
void RemoveAllIf(Collection& c, Pred&& predicate) {
    c.erase(std::remove_if(begin(c), end(c), std::forward<Pred>(predicate)), c.end());
}
//FindIf(i, 2)
template <class Collection, class T>
auto Find(Collection& c, const T& value) {
    return std::find(begin(c), end(c), value);
}
// FindIf(i, [](int x){return x > 8;})
template <class Collection, class Pred>
auto FindIf(Collection& c, Pred&& predicate) {
    return std::find_if(begin(c), end(c), std::forward<Pred>(predicate));
}

template <class Collection, class T>
bool Contains(const Collection& c, const T& value) {
    return std::find(begin(c), end(c), value) != c.end();
}
// ContainsIf(i, [](int x){return x > 8;})
template <class Collection, class Pred>
bool ContainsIf(const Collection& c, Pred&& predicate) {
    return std::find_if(begin(c), end(c), std::forward<Pred>(predicate)) != c.end();
}
// CountIf(i, [](int x){return x > 4;})
template <class Collection, class Pred>
int CountIf(const Collection& c, Pred&& predicate) {
    return std::count_if(begin(c), end(c), std::forward<Pred>(predicate));
}

template <class T, class... Args>
const auto& Min(const T& arg, const Args&... args) {
    std::vector<T> v = {arg, args...};
    return *std::min_element(v.begin(), v.end());
}

template <class T, class... Args>
const auto& Max(const T& arg, const Args&... args) {
    std::vector<T> v = {arg, args...};
    return *std::max_element(v.begin(), v.end());
}

template <class Collection>
auto MaxElement(const Collection& c) {
    return std::max_element(c.begin(), c.end());
}

template <class Collection>
auto MinElement(const Collection& c) {
    return std::min_element(c.begin(), c.end());
}
// MaxElement(i, [](int a, int b){return a < b;})
template <class Collection, class Comp>
auto MaxElement(const Collection& c, Comp&& comparator) {
    return std::max_element(c.begin(), c.end(), comparator);
}
// MinElement(i, [](int a, int b){return a < b;})
template <class Collection, class Comp>
auto MinElement(const Collection& c, Comp&& comparator) {
    return std::min_element(c.begin(), c.end(), comparator);
}

template <class Collection>
void Sort(Collection& c) {
    std::sort(c.begin(), c.end());
}

// Sort(i, [](int x, int y){ return x > y; });
template <class Collection, class Comp>
void Sort(Collection& c, Comp&& comparator) {
    std::sort(c.begin(), c.end(), std::forward<Comp>(comparator));
}

// remove all not unique elements in collection
template <class Collection>
void Unique(Collection& c) {
    Sort(c);
    c.erase(std::unique(c.begin(), c.end()), c.end());
}

// Unique(i, [](int x, int y){ return x == y; });
template <class Collection, class Pred>
void Unique(Collection& c, Pred&& predicate) {
    Sort(c);
    c.erase(std::unique(c.begin(), c.end(), predicate),
            c.end());
}

template <class Collection, class Pred>
void ForEach(Collection& c, Pred&& predicate) {
    std::for_each(c.begin(), c.end(), std::forward<Pred>(predicate));
}

template <class Collection, class T>
int IndexOf(const Collection& c, const T& value) {
    return std::distance(begin(c),
                         std::find(begin(c), end(c), value));
}

template <class Collection, class Pred>
int IndexOfIf(const Collection& c, Pred&& predicate) {
    return std::distance(begin(c),
                         std::find_if(begin(c), end(c),
                         std::forward<Pred>(predicate)));
}
