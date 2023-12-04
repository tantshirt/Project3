#ifndef __LINKEDLIST_
#define __LINKEDLIST_

#include <string>
#include <iostream>

// Template class for Node, used in the LinkedList
template <typename T>
class Node {
private:
    T data;                // Data stored in the node
    Node<T>* next;         // Pointer to the next node
    Node<T>* previous;     // Pointer to the previous node

public:
    // Constructors
    Node() : next(nullptr), previous(nullptr) {} // Default constructor
    Node(T data) : data(data), next(nullptr), previous(nullptr) {} // Constructor with data
    Node(T data, Node<T>* next, Node<T>* previous) : data(data), next(next), previous(previous) {} // Constructor with data and pointers

    // Accessors and mutators for data and node pointers
    T getData() { return data; }
    void setData(T data) { this->data = data; }

    Node<T>* getNext() { return next; }
    void setNext(Node<T>* next) { this->next = next; }

    Node<T>* getPrevious() { return previous; }
    void setPrevious(Node<T>* previous) { this->previous = previous; }
};

// Template class for LinkedList
template <typename T>
class LinkedList {
private:
    Node<T>* head;         // Pointer to the first node in the list
    Node<T>* tail;         // Pointer to the last node in the list
    int length;            // Number of elements in the list

public:
    LinkedList() : head(nullptr), tail(nullptr), length(0) {} // Default constructor

    // Destructor to clean up memory
    ~LinkedList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->getNext();
            delete current;
            current = next;
        }
    }

    // Methods to add elements to the list
    void AddToFront(T data);
    void AddToEnd(T data);
    void AddAtIndex(T data, int index);
    void AddBefore(Node<T>* node, T data);
    void AddAfter(Node<T>* node, T data);

    // Methods to remove elements from the list
    T RemoveFromFront();
    T RemoveFromEnd();
    void RemoveTheFirst(T data);
    void RemoveAllOf(T data);

    // Methods to remove nodes relative to a given node
    T RemoveBefore(Node<T>* node);
    T RemoveAfter(Node<T>* node);

    // Methods to check existence and find elements
    bool ElementExists(T data);
    Node<T>* Find(T data);
    int IndexOf(T data);

    // Methods to retrieve data from nodes
    T RetrieveFront();
    T RetrieveEnd();
    T Retrieve(int index);

    // Method to print the list
    void PrintList();

    // Method to empty the list
    void Empty();

    // Method to get the length of the list
    int Length();
};
#endif 