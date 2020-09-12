#include "MultithreadedClass.h"

int MultithreadedClass::getInt() const {
    return m_int;
}

void MultithreadedClass::add(int addValue) {
    m_mutex.lock();
    for (int i = 0; i < std::abs(addValue); ++i)
        m_int += 1;
    m_mutex.unlock();
}

void MultithreadedClass::subtract(int subtractValue) {
    std::lock_guard lock(m_mutex);
    for (int i = 0; i < std::abs(subtractValue); ++i)
        m_int -= 1;
}