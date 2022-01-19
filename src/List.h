#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <stdexcept>

// Implment Circular Doubly Linked List

typedef int Item;

struct Node {
    Item item;
    Node *next;
    Node *prev;

    Node(const Item &i, Node *nextnode = nullptr, Node *prevnode = nullptr){
        item = i;
        next = nextnode;
        prev = prevnode;
    }
};

class List {
    private:
        Node *head;
        int m_size;
        
    public:
        List(); 

        List(const List &lst); 

        ~List(); 

        bool empty() const; 

        size_t size() const; 

        void clear(); 

        Item &front(); 

        Item &back(); 

        void push_front(const Item &data); 

        void push_back(const Item &data); 

        void pop_front(); 

        void pop_back(); 

        void insertAt(const Item &data, int index); 

        void removeAt(int index); 

        void removeAll(const Item &data); 

        void swap(List &lst); 

        void concat(List &lst); 

        void *copy(); 

        void append(Item vec[], int n); 

        bool equals(const List &lst) const; 

        void reverse(); 

        void merge(List &lst); 

        friend std::ostream &operator<<(std::ostream &out, const List &lst); 

        Item &operator[](int index); 

        List &operator=(const List &lst);
};

List::List() {
    head = nullptr;
    m_size = 0;
}

List::List(const List &lst) {
    if(lst.empty()) {
        head = nullptr;
        m_size = 0;
    }else{
        head = new Node(lst.head->item);
        head->next = head;
        head->prev = head;
        m_size = 1;
        Node *currente = lst.head->next;
        while(currente != lst.head) {
            push_back(currente->item);
            currente = currente->next;
        }
    }
}

List::~List() {
    clear();
}

bool List::empty() const {
    return head == nullptr;
}

size_t List::size() const {
    return m_size;
}

void List::clear() {
    if(!empty()) {
        Node *current = head->next;
        Node *next;
        while(current != head) {
            next = current->next;
            delete current;
            current = next;
        }
        delete head;
        head = nullptr;
    }
}

// Funcao com decisao de projeto
Item& List::front() {
    if(empty()) {
        throw std::out_of_range("List is empty");
    }
    return head->item;
}

Item& List::back() {
    if(empty()) {
        throw std::out_of_range("List is empty");
    }
    return head->prev->item;
}

void List::push_front(const Item &data) {
    if(empty()) {
        head = new Node(data);
        head->next = head;
        head->prev = head;
    }else{
        Node *last = head->prev;

        Node *newNode = new Node(data);
        newNode->next = head;
        newNode->prev = last;

        last->next = newNode;
        head->prev = newNode;

        head = newNode;
    }
    m_size++;
}

void List::push_back(const Item &data) {
    if(empty()) {
        head = new Node(data);
        head->next = head;
        head->prev = head;
    }else{
        Node *last = head->prev;

        Node *newNode = new Node(data);
        newNode->next = head;
        newNode->prev = last;

        last->next = newNode;
        head->prev = newNode;
    }
    m_size++;
}

// 1 - Henryck
void List::pop_front() {

}

// 2 - Vitor
void List::pop_back() {
    if(empty()) {
        throw std::out_of_range("List is empty");
    }
    else if(m_size == 1) {
        head = nullptr;
        m_size = 0;
    }else{
        Node *last = head->prev;

        head->prev = last->prev;
        last->prev->next = head;

        delete last;
        m_size--;
    }
}

// 3 - Vitor
void List::insertAt(const Item &data, int index) {
    if(index < 0 || index > m_size) {
        throw std::out_of_range("Index out of range");
    }else if(index == 0) {
        push_front(data);
    }else{
        Node *newNode = new Node(data);
        Node *current = head;
        for(int i = 0; i < index-1; i++) {
            current = current->next;
        }
        current->next->prev = newNode;
        newNode->next = current->next;
        current->next = newNode;
        newNode->prev = current;
    }
}

// 4 - Henryck
void List::removeAt(int index) {

}

// 5 - Vitor
void List::removeAll(const Item &data) {

}

// 6 - Vitor
void List::swap(List &lst) {

}

// 7 - Vitor
void List::concat(List &lst) {

}

// 8 - Henryck
void *List::copy() {

}

// 9 - Vitor
void List::append(Item vec[], int n) {

}

// 10 - Henryck
bool List::equals(const List &lst) const {

}

// 11 - Vitor
void List::reverse() {

}


void List::merge(List &lst) {

}

// 12 - Henryck
std::ostream &operator<<(std::ostream &out, const List &lst) {

}

// 13 - Henryck
Item &List::operator[](int index) {

}

// 14 - Henryck
List &List::operator=(const List &lst) {

}

#endif