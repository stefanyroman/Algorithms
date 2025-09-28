#include <iostream>
#include "doublylinkedlist.h"
#include "Node.h"
using namespace std;

int main() {
    DoublyLinkedList dll;

    // add some nodes
    dll.addNewNodeToBack(new Node(1));
    dll.addNewNodeToBack(new Node(2));
    dll.addNewNodeToBack(new Node(3));
    dll.addNewNodeToBack(new Node(2));
    dll.addNewNodeToBack(new Node(1));

    cout << "List values: ";
    dll.displayDoublyLinkedList();

    cout << "List diagram: ";
    dll.drawDoublyLinkedList();

    // check palindrome
    if (dll.isPalindrome())
        cout << "The list IS a palindrome." << endl;
    else
        cout << "The list is NOT a palindrome." << endl;

    // split into 2 parts
    dll.split(2);

    // split into 5 parts
    dll.split(5);

    return 0;
}
