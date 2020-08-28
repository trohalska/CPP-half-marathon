// Подключаемый модуль
#pragma once
#include <ostream>

template<typename DataType>
struct tNode {
    DataType data;
    tNode* next;
};

template<typename DataType>
tNode<DataType> * list_push_front(tNode<DataType> *p_head, DataType data) {
    tNode<DataType> *p = new tNode<DataType>;
    p->data = data;
    p->next = p_head;
    p_head = p;

    return p_head;
}

// шаблон linked_list

template<typename DataType>
struct List {
    tNode<DataType> *begin;
    int size;
};

template<typename DataType>
void list_init(List<DataType> &L) {  // create empty list
    L.begin = nullptr;
    L.size = 0;
}

template<typename DataType>
void list_insert(List<DataType> &L, const DataType &value) {
    L.size += 1;
    L.begin = list_push_front(L.begin, value);

}

template<typename DataType>
void list_print(const List<DataType> &L, std::ostream &out) {
    tNode<DataType> *p = L.begin;
    while (p) {
        out << p->data << '\t';
        p = p->next;
    }
}

template<typename DataType>
void list_destroy(List<DataType> &L) {
    tNode<DataType> *p = L.begin;
    tNode<DataType> *prev;
    while (p) {
        prev = p;
        p = p->next;
        delete[] prev;
    }
    L.size = 0;
    L.begin = nullptr;
}
