//
// Created by Edi on 16-May-17.
//

#include "Node.h"

Node::Node(int data) : data(data) {}

int Node::getData() const {
    return data;
}

void Node::setData(int data) {
    Node::data = data;
}

Node *Node::getNext() const {
    return next;
}

void Node::setNext(Node *next) {
    Node::next = next;
}
