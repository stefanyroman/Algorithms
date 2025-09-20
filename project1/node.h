#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;
class Node {
friend class DoublyLinkedList;
public:
Node();
Node(int v);
~Node();
private:
Node *prev;
int value;
Node *next;
};
#endif
// Node.cpp
#ifndef NODE_CPP
#define NODE_CPP
#include "Node.h"
Node::Node()
{
prev = NULL;
value = 0;
next = NULL;
}
Node::Node(int v)
{
prev = NULL;
value = v;
next = NULL;
}
Node::~Node()
{
}
#endif