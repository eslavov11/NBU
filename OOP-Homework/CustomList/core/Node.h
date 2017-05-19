//
// Created by Edi on 16-May-17.
//

#ifndef CUSTOMLIST_NODE_H
#define CUSTOMLIST_NODE_H

class Node {
public:
    Node(int data);

    int getData() const;

    void setData(int data);

    Node *getNext() const;

    void setNext(Node *next);

private:
    int data;
    Node *next;
};


#endif //CUSTOMLIST_NODE_H
