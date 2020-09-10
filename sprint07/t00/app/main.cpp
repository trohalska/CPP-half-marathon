#include <iostream>
#include <string>
#include <cassert>
#include <vector>

#include "CBLVector.h"
#include "algorithmUtils.h"
#include "mylib.h"


using namespace CBL;

static bool checkSimple() {
    {
        Vector<int> v = {1, 2, 3};
        Vector<int> v1({1, 2, 3});
    }
    {
        Vector<int> v(4);
        assert(v.size() == 4);
        assert(v.capacity() >= 4);
        assert(!v.isEmpty());
    }
    {
        Vector<int> v(10, 2);
        assert(v.size() == 10);
        assert(v.capacity() >= 10);
        assert(!v.isEmpty());
        assert(*v.begin() == 2);
        assert(*(v.end() - 1) == 2);
    }
    {
        Vector<int> v = {1, 2, 3};
        Vector<int> v1(v);
        Vector<int> v2(v.begin(), v.end());
    }
    {
        Vector<int> v{2, 3, 4, 5};

        auto i = 2;
        for (auto& item : v) {
            assert(i++ == item);
        }
        assert(*v.begin() == 2);
        assert(*(v.end() - 1) == 5);

        assert(v.size() == 4);
        assert(v.capacity() >= 4);
        assert(!v.isEmpty());
    }

    std::cout << "Simple vector OK" << std::endl;
    return true;
}

static bool CheckOperators() {
    {
        Vector<std::string> v(2, "aaaa");
        Vector<std::string> v1(1, "bcvb");
        Vector<std::string> v2(1, "aaa");
        // std::cout << (v > v1) << '\n';

        assert((v < v1) == 1);
        assert((v > v1) == 0);
        assert((v == v2) == 0);
        assert((v != v2) == 1);
    }
    std::cout << "Operators OK" << std::endl;
    return true;
}

static bool AccsessCheck() {
    {
        Vector<int> v({1, 2, 3});
        assert(v[0] == 1 && v.at(1) == 2);
        v[0] = 11; v.at(1) = 12;
        assert(v[0] == 11 && v.at(1) == 12);
    }
    {
        try {
            Vector<int> v({1, 2, 3});
            v.at(12);
        }
        catch (std::exception& e) {
            // std::cout << e.what() << std::endl;
            std::string s = "Vector: out of range";
            assert(e.what() == s);
        }
    }
    {
        Vector<int> v({12, 2, 3});
        std::vector<int> v1({12, 2, 3});
        assert(*v.data() == *v1.data());
        // std::cout << *v.data() << ' ' << *v1.data() << '\n';
    }
    std::cout << "Accsess OK" << std::endl;
    return true;
}

static bool EmptyCheck() {
    {
        Vector<int> v;
        std::vector<int> s;
        assert(v.isEmpty() == s.empty());
        assert(v.size() == s.size());
    }
    std::cout << "isEmpty OK" << std::endl;
    return true;
}

bool ReserveResizeCheck() {
    {
        Vector<int> v;
        std::vector<int> s;
        v.reserve(10);
        s.reserve(10);
        assert(v.capacity() == s.capacity());
        assert(v.size() == s.size());

        // std::cout << v.capacity() << " " << v.size() << std::endl;
        // std::cout << s.capacity() << " " << s.size() << std::endl;

        v.resize(20);
        s.resize(20);
        assert(v.capacity() == s.capacity());
        assert(v.size() == s.size());

        // std::cout << v.capacity() << " " << v.size() << std::endl;
        // std::cout << s.capacity() << " " << s.size() << std::endl;

    }
    std::cout << "Reserve OK\nResize OK" << std::endl;
    return true;
}

static bool InsertPushPopCheck() {
    {
        Vector<int> v({1, 2, 3});
        Vector<int> s({1, 2, 3});
        std::vector<int> s1({1, 2, 3});
        v.insert(v.begin(), 11);
        v.insert(v.begin() + 3, 5);
        s.insert(s.begin(), 11);
        s.insert(s.begin() + 3, 5);
        s1.insert(s1.begin(), 11);
        s1.insert(s1.begin() + 3, 5);
        assert((v == s) == 1);
        assert(s.size() == s1.size());
        assert(s.capacity() == s1.capacity());
        // outputAny(v);
        // outputAny(s);
        // outputAny(s1);
    }
    std::cout << "Insert OK\n";
    {
        Vector<int> v({1, 2, 3});
        Vector<int> s({1, 2, 3});
        Vector<int> s1({1, 2, 3});
        v.push_back(1);
        v.push_back(3);
        s.push_back(1);
        s.push_back(3);
        s1.push_back(1);
        s1.push_back(3);
        assert((v == s) == 1);
        assert(v.size() == s1.size());
        assert(v.capacity() == s1.capacity());
        // outputAny(v);
        // outputAny(s);
        // outputAny(s1);
    }
    {
        Vector<int> v({1, 2, 3});
        Vector<int> s({1, 2, 3});
        std::vector<int> s1({1, 2, 3});
        v.pop_back();
        v.pop_back();
        s.pop_back();
        s.pop_back();
        s1.pop_back();
        s1.pop_back();
        assert((v == s) == 1);
        assert(v.size() == s1.size());
        assert(v.capacity() == s1.capacity());
        // outputAny(s);
        // outputAny(v);
    }
    std::cout << "Push OK\nPop OK\n";
    return true;
}

static bool EraseClearCheck() {
    {
        Vector<int> v({1, 2, 3});
        std::vector<int> s({1, 2, 3});
        assert(*v.erase(v.begin(), v.end() - 1) ==
               *s.erase(s.begin(), s.end() - 1));
        // std::cout << *v.erase(v.begin(), v.end() - 1) << std::endl;
        // std::cout << *s.erase(s.begin(), s.end() - 1) << std::endl;
    }
    {
        Vector<int> v({1, 2, 3});
        std::vector<int> s({1, 2, 3});
        v.clear();
        s.clear();
        assert(v.capacity() == s.capacity());
        assert(v.size() == s.size());
        // std::cout << v.size() << " " << v.capacity() << std::endl;
        // std::cout << s.size() << " " << s.capacity() << std::endl;
    }
    std::cout << "Erase OK\nClear OK\n";
    return true;
}

int main() {
    checkSimple();
    CheckOperators();
    AccsessCheck();
    EmptyCheck();
    ReserveResizeCheck();
    InsertPushPopCheck();
    EraseClearCheck();

    std::cout << "\nAssessment complete!\n\n";
    system("leaks -q vector");
    return 0;
}