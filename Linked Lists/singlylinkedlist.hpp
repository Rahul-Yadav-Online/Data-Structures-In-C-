#ifndef SINGLYLINKEDLIST_HPP
#define SINGLYLINKEDLIST_HPP

#include  <cstddef> 
#include <new>
#include <iostream>


template <typename T>
class SLLNode{
    /**
     * Singly Linked List Node definition
    */
public:
    T info;
    SLLNode<T> *next;

    SLLNode(){
        /**
         * create an object of SLLNode pointing to NULL.
        */
        next = NULL;
    }

    SLLNode(const T data, SLLNode<T> *next_ptr = NULL){
        /**
         * create an object and initialize the value of next and info as provided.
         * if next is not provided set it to NULL.
        */
       info = data;
       next = next_ptr;
    }
};

template <typename T>
class SinglyLinkedList{
    /**
     * Definitioin of Singly Linked List
    */
   
private:
    SLLNode<T>* head;
    SLLNode<T>* tail;
    unsigned int cnt;

public:
    SinglyLinkedList(){
        
        head = tail = NULL;
        cnt = 0;
    }
    ~SinglyLinkedList(){
        if(head == NULL){
            return;
        }
        for(SLLNode<T> *tmp; head==NULL;){
        tmp=head->next;
        delete head;
        head = tmp;
    }
    } // SLL destructor - Destroy the SLL
    
    void addAtHead(const T& val); // Insert Node at the Head of the SLL
    void addAtTail(const T& val); // Insert Node at the tail of the SLL
    T deleteFromHead(); // Delete Node from the Head of the SLL
    T deleteFromTail(); // Delete Node from the Tail of the SLL
    void deleteNode(const T& val);  // Delete Node with the value provided as function parameter 
    void printList(); // Print the elements of the Linked List
};

template <typename T>
void SinglyLinkedList<T>::addAtHead(const T& val){
    /**
     * Create a new SLLNode and then Add the node to the Head of the Linked List.
    */
    head = new(std::nothrow) SLLNode<T>(val,head); 
    if(head == nullptr){
        /**
         * Check if SLLNode creation was successful
         * If not print the error "Node Creatiopn Failed"
        */
        std::cout << ("[!] Node Creation Failed.\n");
        return ;
    }
    if(tail==NULL){
        /**
         * If the list was empty then after node creation both head and tail
         * points to 1st Node of the Linked List.
        */
        tail = head;
        cnt+=1;
        return ;
    }
    cnt+=1;
    return;
}

template <typename T>
void SinglyLinkedList<T>::addAtTail(const T& val){
    /**
     * Create a new SLLNode and then Add the node to the Tail of the Linked List.
    */
    if(tail != NULL){
        /**
         * If Tail is pointing to some SLLNode, then the next of this Node will be
         * the new created Node and then tail will point to the new node.
        */
        tail->next = new(std::nothrow) SLLNode<T>(val,NULL);
        if(tail->next == nullptr){
            /**
             * Check if SLLNode creation was successful
             * If not print the error "Node Creatiopn Failed"
            */
            std::cout << ("[!] Node Creation Failed.\n");
            return ;
        }
        tail = tail->next;
        cnt+=1;
        return;
    }
    /**
     * If the Linked List is empty then both head an tail point to the 
     * new node.
    */
    tail = new(std::nothrow) SLLNode<T>(val,NULL);
    if(head == nullptr){
        /**
         * Check if SLLNode creation was successful
         * If not print the error "Node Creatiopn Failed"
        */
        std::cout << ("[!] Node Creation Failed.\n");
        return ;
    }
    head = tail;
    cnt+=1;
    return;
}

template <typename T>
T SinglyLinkedList<T>::deleteFromHead(){
    /**
     * Delete Node from the head of the Linked List and return the value of the Node info
    */
    if(head == NULL){
        std::cout << "[-] Unable to deleteFromHead()! List is Empty." <<std::endl;
        return 0;
    }
    T val = head->info;
    SLLNode<T> *tmp = head;

    if(head == tail){
        /**
         * If head and tail both points to the same Node then 
         * delete the node and point both head and tail to NULL
        */
        head = tail = NULL;
    }else{
        head = head->next; // make the head point the next Node
    }   
    delete tmp; // Delete the (previously)Head Node
    cnt-=1;
    return val;
}

template <typename T>
T SinglyLinkedList<T>::deleteFromTail(){
    /**
     * Delete Node from the tail of the Linked List and return the value of the Node info
    */
    if(tail == NULL){
        std::cout << "[-] Unable to deleteFromTail()! List is Empty." <<std::endl;
        return 0;
    }
    T val = tail->info;
    if(head == tail){
        /**
         * If head and tail both points to the same Node then 
         * delete the node and point both head and tail to NULL
        */
        delete tail;
        head = tail = NULL;
        cnt-=1;
        return val;
    }
    /**
     * If there are more than 1 node in the Linked list then
     * travese to the Node before the tail Node and delete the tail Node
     * and make the Node before the tail node the new tail.
    */
    SLLNode<T> *tmp = head;
    while(tmp->next != tail){
        tmp = tmp->next;
    }
    delete tail;
    tail = tmp;
    tail->next = NULL;
    cnt-=1;
    return val;
}

template <typename T>
void SinglyLinkedList<T>::deleteNode(const T& val){
    if(head==NULL){
        /**
         * Linked List is Empty
        */
        std::cout<<"[-] Unable to deleteNode("<<val<<") List is empty.\n";
        return;
    }

    if(head == tail){
        /**
         * If there is only one Node in the List then 
         * delete the node if the info is equal to the Val given else
         * print Node not found.
        */
        if(head->info == val){
            delete head;
            head = tail = NULL;
            cnt-=1;
            return;
        }
        std::cout<<"[!] Node not found in the List.\n";
        return;
    }
    SLLNode<T> *tmp = head, *ptmp = head;
    if(head->info == val){
        head = head->next;
        delete tmp;
        cnt-=1;
        return;
    }
    tmp = tmp->next;
    while(tmp->next != NULL ){
        /**
         * traverse the List until we find the Node
        */
        if(tmp->info == val){
            ptmp->next = tmp->next;
            delete tmp;
            cnt-=1;
            return;
        }
        ptmp = tmp;
        tmp = tmp->next;
    }
    if(tmp->next == NULL){
        /**
         * If we reached the end of the list
         * and Node is not present in the List then print Node not found
        */
        if(tmp->info == val){
            delete tmp;
            cnt-=1;
            return;
        }
        std::cout<<"[!] Node not found in the List.\n";
        return;
    }
    
    return;
}

template <typename T>
void SinglyLinkedList<T>::printList(){
    if(head == NULL){
        std::cout << "[-]List is Empty.\n";
        return;
    }
    SLLNode<T> *tmp=head;
    std::cout<< "-> ";
    for(; tmp->next != NULL; tmp=tmp->next){
        std::cout<< tmp->info << " ";
    }
    std::cout<<tmp->info << std::endl;
    return;
}

#endif