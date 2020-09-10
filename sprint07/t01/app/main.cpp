#include <iostream>
#include <string>
#include <cassert>

#include "algorithmUtils.h"
#include "mylib.h"

#include "CBLString.h"
#include "CBLWString.h"

using namespace CBL;

static bool checkSimple() {
    {
        String str;
        std::basic_string<char> stdstr;
        assert(str.length() == stdstr.length());
        assert(strcmp(str.c_str(), stdstr.c_str()) == 0);
    }
    {
        String s;
        String s1("stroka");
        std::basic_string<char> ss1("stroka");

        std::basic_string<char> stdstr;
        String s2(s1);
        String s3(s1, 2);
        String s4(s1, 2, 3);
        String s5(4, 'c');
        String s6(s1.begin() + 2, s1.end());

        assert(strcmp(s1.c_str(), "stroka") == 0 && s1.length() == 6);
        assert(strcmp(s2.c_str(), "stroka") == 0 && s2.length() == 6);
        assert(strcmp(s3.c_str(), "roka") == 0 && s3.length() == 4);
        assert(strcmp(s4.c_str(), "rok") == 0 && s4.length() == 3);
        assert(strcmp(s5.c_str(), "cccc") == 0 && s5.length() == 4);
        assert(strcmp(s6.c_str(), "roka") == 0 && s6.length() == 4);

        String s7(s1, 2, 20);
        // std::basic_string<char> ss7(ss1, 2, 20);
        // std::cout << "s7: " << s7.c_str() << " length: " << s7.length() << std::endl;
        // std::cout << "ss7: " << ss7.c_str() << " length: " << ss7.length() << std::endl;
        assert(strcmp(s7.c_str(), "roka") == 0 && s7.length() == 4);

        // ------ exeption - out of range
        // String s8(s1, 20, 2);
        // std::basic_string<char> ss8(ss1, 20, 2);
        // std::cout << "s8: " << s8.c_str() << " length: " << s8.length() << std::endl;
        // std::cout << "ss8: " << ss8.c_str() << " length: " << ss8.length() << std::endl;
    }
    std::cout << "Simple string OK" << std::endl;
    return true;
}
static bool AccsessCheck() {
    {
        String v("stroka");
        assert(v[0] == 's' && v.at(1) == 't');
        v[0] = 'v'; v.at(1) = 's';
        assert(v[0] == 'v' && v.at(1) == 's');
    }
    {
        try {
            String v("stroka");
            v.at(12);
        }
        catch (std::exception& e) {
            // std::cout << e.what() << std::endl;
            std::string s = "BasicString: out of range";
            assert(e.what() == s);
        }
    }
    {
        String v("sta");
        std::basic_string<char> v1("stroka");
        assert(v.back() == v1.back());
        assert(v.front() == v1.front());
        // std::cout << v.back() << ' ' << v1.back() << '\n';
    }
    std::cout << "Accsess OK" << std::endl;
    return true;
}
static bool CheckC_strCompare() {
    {
        String s1("stroka");
        String s2("stroka");
        assert(s1.compare("stroka") == 0);
        assert(s1.compare(s2) == 0);
        assert(s1.compare(s2.c_str()) == 0);
    }
    std::cout << "c_str OK\nCompare OK" << std::endl;
    return true;
}
static bool CheckOperators() {
    {
        String s1("aaaa");
        String s3("aaa");

        s1 = s3;
        // outputAny(s1);
        // outputAny(s3);
        assert(s3.compare(s1) == 0);
        assert(s3.compare("aaa") == 0);
        s1 = 'c';
        assert(s1.compare("c") == 0);
    }
    {
        String s1("aaaa");
        String s2("bbb");
        String s3("aaa");

        s3 += s2;
        assert(s3.compare("aaabbb") == 0);
        s3 += s1;
        assert(s3.compare("aaabbbaaaa") == 0 && s3.length() == 10);
        // outputAny(s3);
        // std::cout << '\n' << s3.length() << '\n';
        s1 += '5';
        assert(s1.compare("aaaa5") == 0);
    }
    {
        String s1("aaaa");
        String s2("bbb");
        String s3("aaaa");
        assert((s1 < s2) == 1);
        assert((s1 < "a") == 0);
        assert(("a" < s1) == 1);
        assert((s1 > s2) == 0);
        assert((s1 > "a") == 0);
        assert(("a" > s1) == 0);
        assert((s1 == s3) == 1);
        assert((s1 == "aaaa") == 1);
        assert("aaaa" == s1);
        assert((s1 != s3) == 0);
        assert((s1 != "aaaa") == 0);
        assert(("s1" != s1) == 0);

    }
    {
        String s1("");
        std::basic_string<char> s2("");
        assert((s2.length() == s1.length()) == 1);
        // assert((s2.c_str() == s1.c_str()) == 1);
        // outputAny(s1);
        // outputAny(s2);
        assert((s1[0] == '\0') == 1);
        assert((s2[0] == '\0') == 1);
    }
    std::cout << "Operators OK" << std::endl;
    return true;
}
static bool CheckAppend() {
    {
        String s1("aaaa");
        String s2("bbb");
        String s3("aaa");

        s3.append(s2);
        assert(s3.compare("aaabbb") == 0);
        s3.append("c");
        assert(s3.compare("aaabbbc") == 0 && s3.length() == 7);
        s2.append(3, 'c');
        assert(s2.compare("bbbccc") == 0);
        s1.append("zzzzz", 2);
        // outputAny(s1);
        assert(s1.compare("aaaazz") == 0 && s1.length() == 6);
        s1.append(s3.begin() + 6, 1);
        assert(s1.compare("aaaazzc") == 0 && s1.length() == 7);

        s1.append(s3.begin() + 6, 2);
        assert(s1.compare("aaaazzcc") == 0 && s1.length() == 8);
        // outputAny(s1);
        // std::cout << s1.length() << '\n';
        // std::basic_string<char> v1("stroka");
        // v1.append(s3.begin() + 6, 2);
        // std::cout << s1.length() << '\n';
    }
    std::cout << "Append OK" << std::endl;
    return true;
}
static bool CheckSwap() {
    {
        String s1("aaa");
        String s2("bb");
        s1.swap(s2);
        assert(s1.compare("bb") == 0);
        assert(s2.compare("aaa") == 0);
        assert(s1.length() == 2 && s2.length() == 3);
        // std::cout << s1.c_str() << " " << s2.c_str() << std::endl;
        // std::cout << s1.length() << " " << s2.length() << std::endl;
    }
    std::cout << "Swap OK" << std::endl;
    return true;
}
static bool CheckOperatorsPlus() {
    {
        String s1("aa");
        String s3("bb");

        s1 += s3;
        // outputAny(s1);
        // outputAny(s3);
        assert(s1.compare("aabb") == 0);

    }
    std::cout << "Operators Plus OK" << std::endl;
    return true;
}
void StringFind() {
    String s("This is a string");

    String v("Th");
    String v1("t");
    assert(s.find(v, 4) == std::string::npos);
    assert(s.find(v, 0) == 0);
    assert(s.find('i', 4) == 5);
    assert(s.find(v1, 2) == 11);

    // assert(s.rfind(v1, 4) == std::string::npos);
    std::cout << s.rfind(v1, 4) << '\n';
    assert(s.rfind(v, 13) == 0);
    assert(s.rfind('i', 14) == 13);
    assert(s.rfind(v1, 11) == 11);

    std::cout << "Find OK\nRfind OK" << std::endl;
}

static bool WcheckSimple() {
    {
        WString str;
        std::basic_string<wchar_t> stdstr;
        assert(str.length() == stdstr.length());
        assert(wcscmp(str.c_str(), stdstr.c_str()) == 0);
    }
    {
        WString s;
        WString s1(L"stroka");
        std::basic_string<wchar_t> ss1(L"stroka");

        std::basic_string<wchar_t> stdstr;
        WString s2(s1);
        WString s3(s1, 2);
        WString s4(s1, 2, 3);
        WString s5(4, 'c');
        WString s6(s1.begin() + 2, s1.end());

        assert(wcscmp(s1.c_str(), L"stroka") == 0 && s1.length() == 6);
        assert(wcscmp(s2.c_str(), L"stroka") == 0 && s2.length() == 6);
        assert(wcscmp(s3.c_str(), L"roka") == 0 && s3.length() == 4);
        assert(wcscmp(s4.c_str(), L"rok") == 0 && s4.length() == 3);
        assert(wcscmp(s5.c_str(), L"cccc") == 0 && s5.length() == 4);
        assert(wcscmp(s6.c_str(), L"roka") == 0 && s6.length() == 4);

        WString s7(s1, 2, 20);
        // std::basic_string<char> ss7(ss1, 2, 20);
        // std::cout << "s7: " << s7.c_str() << " length: " << s7.length() << std::endl;
        // std::cout << "ss7: " << ss7.c_str() << " length: " << ss7.length() << std::endl;
        assert(wcscmp(s7.c_str(), L"roka") == 0 && s7.length() == 4);

        // ------ exeption - out of range
        // String s8(s1, 20, 2);
        // std::basic_string<char> ss8(ss1, 20, 2);
        // std::cout << "s8: " << s8.c_str() << " length: " << s8.length() << std::endl;
        // std::cout << "ss8: " << ss8.c_str() << " length: " << ss8.length() << std::endl;
    }
    std::cout << "Simple WString OK" << std::endl;
    return true;
}
static bool WAccsessCheck() {
    {
        WString v(L"stroka");
        assert(v[0] == 's' && v.at(1) == 't');
        v[0] = 'v'; v.at(1) = 's';
        assert(v[0] == 'v' && v.at(1) == 's');
    }
    {
        try {
            WString v(L"stroka");
            v.at(12);
        }
        catch (std::exception& e) {
            // std::cout << e.what() << std::endl;
            std::string s = "BasicString: out of range";
            assert(e.what() == s);
        }
    }
    {
        String v("sta");
        std::basic_string<char> v1("stroka");
        assert(v.back() == v1.back());
        assert(v.front() == v1.front());
        // std::cout << v.back() << ' ' << v1.back() << '\n';
    }
    std::cout << "WAccsess OK" << std::endl;
    return true;
}
static bool WCheckC_strCompare() {
    {
        WString s1(L"stroka");
        WString s2(L"stroka");
        assert(s1.compare(L"stroka") == 0);
        assert(s1.compare(s2) == 0);
        assert(s1.compare(s2.c_str()) == 0);
    }
    std::cout << "WC_str OK\nWCompare OK" << std::endl;
    return true;
}
static bool WCheckOperators() {
    {
        WString s1(L"aaaa");
        WString s3(L"aaa");

        s1 = s3;
        // outputAny(s1);
        // outputAny(s3);
        assert(s3.compare(s1) == 0);
        assert(s3.compare(L"aaa") == 0);
        s1 = 'c';
        assert(s1.compare(L"c") == 0);
    }
    {
        WString s1(L"aaaa");
        WString s2(L"bbb");
        WString s3(L"aaa");

        s3 += s2;
        assert(s3.compare(L"aaabbb") == 0);
        s3 += s1;
        assert(s3.compare(L"aaabbbaaaa") == 0 && s3.length() == 10);
        // outputAny(s3);
        // std::cout << '\n' << s3.length() << '\n';
        s1 += '5';
        assert(s1.compare(L"aaaa5") == 0);
    }
    {
        WString s1(L"aaaa");
        WString s2(L"bbb");
        WString s3(L"aaaa");
        assert((s1 < s2) == 1);
        assert((s1 < L"a") == 0);
        assert((L"a" < s1) == 1);
        assert((s1 > s2) == 0);
        assert((s1 > L"a") == 0);
        assert((L"a" > s1) == 0);
        assert((s1 == s3) == 1);
        assert((s1 == L"aaaa") == 1);
        assert(L"aaaa" == s1);
        assert((s1 != s3) == 0);
        assert((s1 != L"aaaa") == 0);
        assert((L"s1" != s1) == 0);
    }
    {
        WString s1(L"");
        std::basic_string<wchar_t> s2(L"");
        assert((s2.length() == s1.length()) == 1);
        // assert((s2.c_str() == s1.c_str()) == 1);
        // outputAny(s1);
        // outputAny(s2);
        assert((s1[0] == '\0') == 1);
        assert((s2[0] == '\0') == 1);
    }
    std::cout << "WOperators OK" << std::endl;
    return true;
}
static bool WCheckAppend() {
    {
        WString s1(L"aaaa");
        WString s2(L"bbb");
        WString s3(L"aaa");

        s3.append(s2);
        assert(s3.compare(L"aaabbb") == 0);
        s3.append(L"c");
        assert(s3.compare(L"aaabbbc") == 0 && s3.length() == 7);
        s2.append(3, 'c');
        assert(s2.compare(L"bbbccc") == 0);
        s1.append(L"zzzzz", 2);
        // outputAny(s1);
        assert(s1.compare(L"aaaazz") == 0 && s1.length() == 6);
        s1.append(s3.begin() + 6, 1);
        assert(s1.compare(L"aaaazzc") == 0 && s1.length() == 7);

        s1.append(s3.begin() + 6, 2);
        assert(s1.compare(L"aaaazzcc") == 0 && s1.length() == 8);
        // outputAny(s1);
        // std::cout << s1.length() << '\n';
        // std::basic_string<char> v1("stroka");
        // v1.append(s3.begin() + 6, 2);
        // std::cout << s1.length() << '\n';
    }
    std::cout << "WAppend OK" << std::endl;
    return true;
}
static bool WCheckSwap() {
    {
        WString s1(L"aaa");
        WString s2(L"bb");
        s1.swap(s2);
        assert(s1.compare(L"bb") == 0);
        assert(s2.compare(L"aaa") == 0);
        assert(s1.length() == 2 && s2.length() == 3);
        // std::cout << s1.c_str() << " " << s2.c_str() << std::endl;
        // std::cout << s1.length() << " " << s2.length() << std::endl;
    }
    std::cout << "WSwap OK" << std::endl;
    return true;
}
static bool WCheckOperatorsPlus() {
    {
        WString s1(L"aa");
        WString s3(L"bb");

        s1 += s3;
        // outputAny(s1);
        // outputAny(s3);
        assert(s1.compare(L"aabb") == 0);

    }
    std::cout << "WOperators Plus OK" << std::endl;
    return true;
}
void WStringFind() {
    WString s(L"This is a string");

    WString v(L"Th");
    WString v1(L"t");
    assert(s.find(v, 4) == std::string::npos);
    assert(s.find(v, 0) == 0);
    assert(s.find('i', 4) == 5);
    assert(s.find(v1, 2) == 11);

    // assert(s.rfind(v1, 4) == std::string::npos);
    std::cout << s.rfind(v1, 4) << '\n';
    assert(s.rfind(v, 13) == 0);
    assert(s.rfind('i', 14) == 13);
    assert(s.rfind(v1, 11) == 11);

    std::cout << "WFind OK\nWRfind OK" << std::endl;
}

int main() {
    checkSimple();
    AccsessCheck();
    CheckC_strCompare();
    CheckOperators();
    CheckAppend();
    CheckSwap();
    CheckOperatorsPlus();
    StringFind();

    std::cout << "----------\n";

    WcheckSimple();
    WAccsessCheck();
    WCheckC_strCompare();
    WCheckOperators();
    WCheckAppend();
    WCheckSwap();
    WCheckOperatorsPlus();
    WStringFind();

    std::cout << "\nAssessment complete!\n\n";
    system("leaks -q basicString");
    return 0;
}
