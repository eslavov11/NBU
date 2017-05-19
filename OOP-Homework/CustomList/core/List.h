//
// Created by Edi on 16-May-17.
//

#ifndef CUSTOMLIST_LIST_H
#define CUSTOMLIST_LIST_H

#include "Node.h"
#include "ListIterator.h"

class List {
public:
    List();

    void push(int data);

    Node *getHead() const;

    void setHead(Node *head);

    Node *getTail() const;

    void setTail(Node *tail);

    ListIterator begin() const;

    ListIterator end() const;

    void insert(ListIterator pos, const int & data);

    void erase(ListIterator pos);
private:
    Node *head;
    Node *tail;
};

#endif //CUSTOMLIST_LIST_H
