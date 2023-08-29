#include "linkedlist.h"

DoublyLinkedList::Node::Node()
    : m_value {0}
    , m_prev(nullptr)
    , m_next(nullptr) {
}

DoublyLinkedList::Node::Node(int value)
    : m_value {value}
    , m_prev {nullptr}
    , m_next {nullptr} {
}

DoublyLinkedList::DoublyLinkedList()
    : m_head {nullptr}
    , m_tail {nullptr} {
}

DoublyLinkedList::~DoublyLinkedList() {
    Node* tmp = m_head;
    while (tmp != nullptr) {
        Node* next = tmp->m_next;
        delete tmp;
        tmp = next;
    }
}

int DoublyLinkedList::m_size {0};

void DoublyLinkedList::push_front(int value) {
    Node* newNode = new Node{value};
    if (m_size == 0) {
        m_head = newNode;
        m_tail = newNode;
    } else {
        newNode->m_next = m_head;
        m_head->m_prev = newNode;
        m_head = newNode;
    }
    ++m_size;
}

void DoublyLinkedList::push_back(int value) {
    Node* newNode = new Node{value};
    if (m_size == 0) {
        m_head = newNode;
        m_tail = newNode;
    } else {
        newNode->m_prev = m_tail;
        m_tail->m_next = newNode;
        m_tail = newNode;
    }
    ++m_size;
}

void DoublyLinkedList::insert(int pos, int value) {
    if (pos < 0 || pos > m_size) {
        throw std::out_of_range("Invalid position for insertion");
    }

    if (pos == 0) {
        push_front(value);
    } else if (pos == m_size) {
        push_back(value);
    } else {
        Node* new_node = new Node(value);
        Node* current = m_head;
        for (int i = 0; i < pos; ++i) {
            current = current->m_next;
        }
        new_node->m_prev = current->m_prev;
        new_node->m_next = current;
        current->m_prev->m_next = new_node;
        current->m_prev = new_node;
        ++m_size;
    }
}

void DoublyLinkedList::remove(int pos) {
    if (pos < 0 || pos >= m_size) {
        throw std::out_of_range("remove() called with an invalid position.");
    }
    if (m_size == 1) {
        delete m_head;
        m_head = nullptr;
        m_tail = nullptr;
    } else if (pos == 0) {
        Node* tmp = m_head;
        m_head = m_head->m_next;
        m_head->m_prev = nullptr;
        delete tmp;
    } else if (pos == m_size - 1) {
        Node* tmp = m_tail;
        m_tail = m_tail->m_prev;
        m_tail->m_next = nullptr;
        delete tmp;
    } else {
        Node* tmp = m_head;
        for (int i = 0; i < pos; ++i) {
            tmp = tmp->m_next;
        }
        tmp->m_prev->m_next = tmp->m_next;
        tmp->m_next->m_prev = tmp->m_prev;
        delete tmp;
    }
    --m_size;
}

int DoublyLinkedList::get(int pos) const {
    if (pos < 0 || pos >= m_size) {
        throw std::out_of_range("get() called with an invalid position.");
    }

    Node* tmp = m_head;
    for (int i = 0; i < pos; ++i) {
        tmp = tmp->m_next;
    }
    return tmp->m_prev->m_value;
}

void DoublyLinkedList::print_list() const {
    Node* tmp = m_head;
    while (tmp != nullptr) {
        std::cout << tmp->m_value << " ";
        tmp = tmp->m_next;
    }
    std::cout << std::endl;
}

void DoublyLinkedList::print_reverse() const {
    Node* tmp = m_tail;
    while (tmp != nullptr) {
        std::cout << tmp->m_value << " ";
        tmp = tmp->m_prev;
    }
    std::cout << std::endl;
}



