#include <iostream>
#include <string>

// struct tNode {
//     std::string data;
//     tNode* next;
// };

typedef std::string DataType;
struct tNode {
    DataType data;
    tNode* next;
};

tNode * list_push_front(tNode *p_head, DataType data) {
    tNode *p = new tNode;
    p->data = data;
    p->next = p_head;
    p_head = p;

    return p_head;
}

void oneway_list() {
    tNode *p = nullptr;
    p = list_push_front(p, "hello");
    p = list_push_front(p, "world");

    while (p) {
        std::cout << p->data << std::endl;
        p = p->next;
    }
}

int main() {
    oneway_list();
    return 0;
}