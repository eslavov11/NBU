//
// Created by Edi on 16-May-17.
//

#include "List.h"

void List::push(int data) {
    Node *newNode = new Node(data);
    if (this->getHead() == 0) {
        this->setHead(newNode);
        this->setTail(newNode);
        return;
    }

    Node *next = this->getHead();
    this->setHead(newNode);
    this->getHead()->setNext(next);
}

Node *List::getHead() const {
    return head;
}

void List::setHead(Node *head) {
    List::head = head;
}

Node *List::getTail() const {
    return tail;
}

void List::setTail(Node *tail) {
    List::tail = tail;
}

ListIterator List::begin() const {
    return ListIterator(this->getHead());
}

ListIterator List::end() const {
    return ListIterator(this->getTail()->getNext());
}

void List::insert(ListIterator pos, const int &data) {
    Node *previous = this->getHead();
    ListIterator i = begin();

    while (i.not_equals(pos)) {
        previous = i.getCurrentNode();
        i.next();
    }

    Node *newNode = new Node(data);
    newNode->setNext(pos.getCurrentNode());
    previous->setNext(newNode);
}

void List::erase(ListIterator pos) {
    Node *previous = this->getHead();
    ListIterator i = begin();

    while (i.not_equals(pos)) {
        previous = i.getCurrentNode();
        i.next();
    }

    if (i.not_equals(this->getTail())) {
        previous->setNext(i.getCurrentNode()->getNext());
        delete i.getCurrentNode();
    }
}

List::List() {
    this->setTail(0);
    this->setHead(0);
}
