#ifndef DOUBLYLINKEDLIST_CPP
#define DOUBLYLINKEDLIST_CPP

#include "doublylinkedlist.h"

// constructor
DoublyLinkedList::DoublyLinkedList() {
    head = NULL;
    tail = NULL;
}

// destructor
DoublyLinkedList::~DoublyLinkedList() {
    Node* temp = head;
    while (temp != NULL) {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
}

// add node to front
void DoublyLinkedList::addNewNodeToFront(Node* newNode) {
    if (head == NULL && tail == NULL) {
        head = tail = newNode;
    } else {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
}

// add node to back
void DoublyLinkedList::addNewNodeToBack(Node* newNode) {
    if (head == NULL && tail == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// remove node from front
Node* DoublyLinkedList::removeNodeFromFront() {
    if (head == NULL) return NULL;
    Node* tempNode = head;
    head = head->next;
    if (head != NULL) head->prev = NULL;
    else tail = NULL; // list became empty
    return tempNode;
}

// remove node from back
void DoublyLinkedList::removeNodeFromBack() {
    if (tail == NULL) return;
    Node* tempNode = tail;
    tail = tail->prev;
    if (tail != NULL) tail->next = NULL;
    else head = NULL; // list became empty
    delete tempNode;
}

// display values
void DoublyLinkedList::displayDoublyLinkedList() {
    Node* tempNode = head;
    while (tempNode != NULL) {
        cout << tempNode->value << " ";
        tempNode = tempNode->next;
    }
    cout << endl;
}

// draw list as diagram
void DoublyLinkedList::drawDoublyLinkedList() {
    Node* temp = head;
    cout << "NULL";
    while (temp != NULL) {
        cout << " <- [" << temp->value << "] ->";
        temp = temp->next;
    }
    cout << " NULL" << endl;
}

// check palindrome
bool DoublyLinkedList::isPalindrome() {
    if (head == NULL || head->next == NULL) return true; // empty or 1 node

    Node* left = head;
    Node* right = tail;

    while (left != NULL && right != NULL && left != right && right->next != left) {
        if (left->value != right->value) return false;
        left = left->next;
        right = right->prev;
    }
    return true;
}

// split into n partitions
void DoublyLinkedList::split(int n) {
    if (n <= 0) return;

    // count nodes
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    if (count == 0) return;

    int partSize = count / n; // assume evenly divisible for project
    temp = head;

    cout << "Splitting into " << n << " parts:" << endl;

    for (int i = 0; i < n; i++) {
        cout << "Part " << i + 1 << ": ";
        for (int j = 0; j < partSize; j++) {
            if (temp != NULL) {
                cout << temp->value << " ";
                temp = temp->next;
            }
        }
        cout << endl;
    }
}

#endif
