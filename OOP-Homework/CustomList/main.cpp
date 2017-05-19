#include <iostream>
#include "core/List.h"

using namespace std;

int main() {
    List list;
    list.push(4);
    list.push(3);
    list.push(1);
    for (ListIterator it = list.begin(); it.not_equals(list.end()); it.next()) {
        std::cout << it.get() << " ";
    }
    std::cout << std::endl;
    ListIterator begin = list.begin();
    begin.next();

    list.insert(begin, 2);

    for (ListIterator it = list.begin(); it.not_equals(list.end()); it.next()) {
        std::cout << it.get() << " ";
    }
    std::cout << std::endl;


    begin = list.begin();
    begin.next();
    begin.next();
    list.erase(begin);

    for (ListIterator it = list.begin(); it.not_equals(list.end()); it.next()) {
        std::cout << it.get() << " ";
    }
    std::cout << std::endl;

    return 0;
}