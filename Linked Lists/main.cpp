/**
 * Note this main file is only for testing the functionality of Linked
 * List Data Structure Implementation
*/

#include <iostream>
#include "singlylinkedlist.hpp"

int main(){
    SinglyLinkedList<int> ll;
    ll.printList();
    ll.deleteNode(6);
    ll.printList();
    std::cout << ll.deleteFromHead() << std::endl;
    ll.printList();
    std::cout << ll.deleteFromTail() << std::endl;
    ll.printList();
    ll.addAtHead(5);
    ll.printList();
    ll.addAtHead(4);
    ll.printList();
    ll.addAtHead(3);
    ll.printList();
    ll.addAtHead(2);
    ll.printList();
    ll.addAtHead(1);
    ll.printList();
    ll.addAtTail(6);
    ll.printList();
    ll.addAtTail(5);
    ll.printList();
    ll.addAtTail(4);
    ll.printList();
    ll.addAtTail(3);
    ll.printList();
    ll.addAtTail(2);
    ll.printList();
    ll.addAtTail(1);
    ll.printList();
    std::cout << ll.deleteFromHead() << std::endl;
    ll.printList();
    std::cout << ll.deleteFromTail() << std::endl;
    ll.printList();
    ll.deleteNode(6);
    ll.printList();
    return 0;
}