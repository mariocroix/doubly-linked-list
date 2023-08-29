#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <stdexcept>

class DoublyLinkedList {
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void push_front(int value);
    void push_back(int value);
    void insert(int pos, int value);
    void remove(int pos);
    int get(int pos) const;
    void print_list() const;
    void print_reverse() const;

private:
    struct Node {
        int m_value;
        Node* m_prev;
        Node* m_next;

        Node();
        explicit Node(int value);
    };

    Node* m_head;
    Node* m_tail;
    static int m_size;
};

#endif  //LINKED_LIST_H
