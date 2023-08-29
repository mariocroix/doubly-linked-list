#include <iostream>
#include "linkedlist.h"

int main() {
    DoublyLinkedList list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    list.push_front(5);
    list.push_front(2);

    list.insert(2, 15);

    std::cout << "List elements: ";
    list.print_list();

    std::cout << "Reversed list elements: ";
    list.print_reverse();

    std::cout << "Element at position 3: " << list.get(3) << std::endl;

    list.remove(1);
    list.remove(3);

    std::cout << "List elements after removals: ";
    list.print_list();

    return 0;
}