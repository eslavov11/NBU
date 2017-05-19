//
// Created by Edi on 16-May-17.
//

#ifndef CUSTOMLIST_LISTITERATOR_H
#define CUSTOMLIST_LISTITERATOR_H


#include "Node.h"

class ListIterator {
public:
    ListIterator(Node *node): currentNode(node) { };

    void next();

    bool not_equals(const ListIterator & iterator);

    int get();

private:
    Node * currentNode;

    Node *getCurrentNode() const;

    void setCurrentNode(Node *currentNode);

    friend class List;
};


#endif //CUSTOMLIST_LISTITERATOR_H
