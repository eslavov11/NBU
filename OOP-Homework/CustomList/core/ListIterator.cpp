//
// Created by Edi on 16-May-17.
//

#include "ListIterator.h"

void ListIterator::next() {
    this->setCurrentNode(this->getCurrentNode()->getNext());
}

bool ListIterator::not_equals(const ListIterator &iterator) {
    return this->getCurrentNode() != iterator.getCurrentNode();
}

Node *ListIterator::getCurrentNode() const {
    return currentNode;
}

void ListIterator::setCurrentNode(Node *currentNode) {
    ListIterator::currentNode = currentNode;
}

int ListIterator::get() {
    return this->getCurrentNode()->getData();
}

