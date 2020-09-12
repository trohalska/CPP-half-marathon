#include "Worker.h"
#include "ClassWithAtomic.h"

void ClassWithAtomic::addToInt(int addValue) {
    for (int i = 0; i < abs(addValue); ++i)
        ++m_int;
}

void ClassWithAtomic::subtractFromInt(int subtractValue) {
    for (int i = 0; i < abs(subtractValue); ++i)
        --m_int;
}

void ClassWithAtomic::pushToVector(int value) {
    std::lock_guard lock(m_vecMutex);
    m_vector.push_back(value);
}

void ClassWithAtomic::eraseFromVector(int value) {
    std::lock_guard lock(m_vecMutex);
    auto it = std::remove_if(m_vector.begin(), m_vector.end(), [value](int& i) {
       return i == value;
    });
    m_vector.erase(it, m_vector.end());
}

int ClassWithAtomic::getInt() const {
    return m_int;
}

std::vector<int> ClassWithAtomic::getVector() const {
    return m_vector;
}
