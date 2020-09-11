#pragma once

#include <vector>
#include <iostream>

template <typename T>
class ClassWithInitializerList final {
 public:
    template <typename... Args>
    ClassWithInitializerList(Args&&... args);
    ClassWithInitializerList(const std::initializer_list<T> lst);
    ClassWithInitializerList(const std::vector<T>& vec);

    void outputVector() const;

 private:
    std::vector<T> m_vecOfArs;
};

template<typename T>
template<typename... Args>
ClassWithInitializerList<T>::ClassWithInitializerList(Args&&... args)
{
    m_vecOfArs = std::vector<T>({args...});
}

template<typename T>
ClassWithInitializerList<T>::ClassWithInitializerList(const std::initializer_list<T> lst)
{
   m_vecOfArs = std::vector<T>(lst.begin(), lst.end());
};

template<typename T>
ClassWithInitializerList<T>::ClassWithInitializerList(const std::vector<T>& vec)
    : m_vecOfArs(vec)
{};

template<typename T>
void ClassWithInitializerList<T>::outputVector() const {
    for (const auto& i : m_vecOfArs) {
        std::cout << i << std::endl;
    }
}