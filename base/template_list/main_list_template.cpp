#include <iostream>
#include <string>
#include "linked_list.h"

// int main() {
//     tNode<std::string> *p = nullptr;
//     p = list_push_front(p, std::string("hello"));
//     p = list_push_front(p, std::string("world"));
//     p = list_push_front(p, std::string("trololo"));

//     while (p) {
//         std::cout << p->data << std::endl;
//         p = p->next;
//     }

//     return 0;
// }

int main() {

    List<std::string> str_list;

    list_init(str_list);

    list_insert(str_list, std::string("hello"));
    list_insert(str_list, std::string("world"));
    list_insert(str_list, std::string("trolo"));

    list_print(str_list, std::cout);

    // list_destroy(str_list);

    return 0;
}