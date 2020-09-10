#pragma once
#include <iostream>
#include <algorithm>
#include <type_traits>
// #include <string>

namespace CBL {

template <class T>
class BasicString {
public:
    using iterator = T*;
    static const size_t npos = -1ul;

    BasicString();
    BasicString(const BasicString<T>& str);
    BasicString(const BasicString<T>& str, size_t pos, size_t len = npos);
    explicit BasicString(const T* str);
    BasicString(const T* str, size_t n);
    BasicString(size_t n, T c);
    BasicString(iterator first, iterator last);
    virtual ~BasicString();

    // iterators
    iterator begin() const;
    iterator end() const;

    // capacity
    size_t length() const;

    // element access
    T& operator[](size_t index) const;
    T& at(size_t index) const;
    T& back() const;
    T& front() const;

    // modifiers
    BasicString<T>& operator=(const BasicString<T>& str);
    BasicString<T>& operator=(const T* str);
    BasicString<T>& operator=(const T c);

    BasicString<T>& operator+=(const BasicString<T>& str);
    BasicString<T>& operator+=(const T* str);
    BasicString<T>& operator+=(const T c);

    void append(const BasicString<T>& str);
    void append(const T* str);
    void append(const T* str, size_t n);
    void append(size_t n, T c);
    void append(iterator first, iterator last);

    void swap(BasicString<T>& str);

    // string operations
    const T* c_str() const;

    virtual int compare(const BasicString<T>& str) const;
    virtual int compare(const T* str) const;

protected:
    size_t m_size{0};
    T* m_buffer{nullptr};
};

}; // end namespace CBL

#include "CBLBasicString_templates.h"

template <class T>
CBL::BasicString<T> operator+(const CBL::BasicString<T>& lhs,
                              const CBL::BasicString<T>& rhs) {
    CBL::BasicString<T> str(lhs);
    str.append(rhs);
    return str;
}

template <class T>
CBL::BasicString<T> operator+(const T* lhs, const CBL::BasicString<T>& rhs) {
    CBL::BasicString<T> str(lhs);
    str.append(rhs);
    return str;
}

template <class T>
CBL::BasicString<T> operator+(const CBL::BasicString<T>& lhs, const T* rhs) {
    CBL::BasicString<T> str(lhs);
    str.append(rhs);
    return str;
}

template <class T>
CBL::BasicString<T> operator+(const T lhs, const CBL::BasicString<T>& rhs) {
    CBL::BasicString<T> str(lhs);
    str.append(rhs);
    return str;
}

template <class T>
CBL::BasicString<T> operator+(const CBL::BasicString<T>& lhs, const T rhs) {
    CBL::BasicString<T> str(lhs);
    str.append(rhs);
    return str;
}

template <class T>
bool operator==(const CBL::BasicString<T>& lhs, const CBL::BasicString<T>& rhs) {
    return !lhs.compare(rhs);
}
template <class T>
bool operator==(const T* lhs, const CBL::BasicString<T>& rhs) {
    return !rhs.compare(lhs);
}
template <class T>
bool operator==(const CBL::BasicString<T>& lhs, const T* rhs) {
    return !lhs.compare(rhs);
}

template <class T>
bool operator!=(const CBL::BasicString<T>& lhs, const CBL::BasicString<T>& rhs) {
    return !(lhs == rhs);
}
template <class T>
bool operator!=(const T* lhs, const CBL::BasicString<T>& rhs) {
    return !(lhs == rhs);
}
template <class T>
bool operator!=(const CBL::BasicString<T>& lhs, const T* rhs) {
    return !(lhs == rhs);
}

template <class T>
bool operator<(const CBL::BasicString<T>& lhs, const CBL::BasicString<T>& rhs) {
    return std::lexicographical_compare(lhs.begin(), lhs.end(),
                                        rhs.begin(), rhs.end());
}
template <class T>
bool operator<(const T* lhs, const CBL::BasicString<T>& rhs) {
    return std::lexicographical_compare(lhs, lhs + td::char_traits<T>::length(lhs),
                                        rhs.begin(), rhs.end());
}
template <class T>
bool operator<(const CBL::BasicString<T>& lhs, const T* rhs) {
    return std::lexicographical_compare(lhs.begin(), lhs.end(),
                                        rhs, rhs + td::char_traits<T>::length(rhs));
}

template <class T>
bool operator<=(const CBL::BasicString<T>& lhs, const CBL::BasicString<T>& rhs) {
    return lhs < rhs || lhs == rhs;
}
template <class T>
bool operator<=(const T* lhs, const CBL::BasicString<T>& rhs) {
    return lhs < rhs || lhs == rhs;
}
template <class T>
bool operator<=(const CBL::BasicString<T>& lhs, const T* rhs) {
    return lhs < rhs || lhs == rhs;
}

template <class T>
bool operator>(const CBL::BasicString<T>& lhs, const CBL::BasicString<T>& rhs) {
    return !(lhs < rhs) && !(lhs == rhs);
}
template <class T>
bool operator>(const T* lhs, const CBL::BasicString<T>& rhs) {
    return !(lhs < rhs) && !(lhs == rhs);
}
template <class T>
bool operator>(const CBL::BasicString<T>& lhs, const T* rhs) {
    return !(lhs < rhs) && !(lhs == rhs);
}

template <class T>
bool operator>=(const CBL::BasicString<T>& lhs, const CBL::BasicString<T>& rhs) {
    return !(lhs < rhs);
}

template <class T>
bool operator>=(const T* lhs, const CBL::BasicString<T>& rhs) {
    return !(lhs < rhs);
}

template <class T>
bool operator>=(const CBL::BasicString<T>& lhs, const T* rhs) {
    return !(lhs < rhs);
}

/* Derived class additional member functions */
// size_t find(const <string class>& str, size_t pos = 0) const;
// size_t find(const <char type>* str, size_t pos = 0) const;
// size_t find(<char type> c, size_t pos= 0) const;

// size_t rfind(const <string class>& str, size_t pos = npos) const;
// size_t rfind(const <char type>* str, size_t pos = npos) const;
// size_t rfind(<char type> c, size_t pos = npos) const;
