//
// Created by Emely Pleitez on 10/6/22.
//

#ifndef CTP_250_LAB_5_LINKEDSTACK_H
#define CTP_250_LAB_5_LINKEDSTACK_H


#include "StackInterface.h"
#include "Node.h"
#include <iostream>

using namespace std;


template<typename Type>
class LinkedStack : public StackInterface<Type>
{
public:
    LinkedStack();
    //~LinkedStack();
    LinkedStack(const LinkedStack<Type>& ); // copy constructor
    bool isEmpty();
    bool push(const Type& newEntry) ;
    bool pop() ;
    Type peek();
    bool isFull();
    void copyStack( const LinkedStack<Type>& theOtherStack);

private:
    Node<Type> *top;

};

template<typename Type>
LinkedStack<Type>::LinkedStack(const LinkedStack<Type>& theOtherStack){
    cout << "in the copy constructor..." << endl;
    top = nullptr;
    copyStack(theOtherStack);
} //copy constructor

template <typename Type>
LinkedStack<Type>::LinkedStack(){
    top = nullptr;
} //default constructor


template <typename Type>
bool LinkedStack<Type>::isEmpty(){
    return (top == nullptr);
}

template <typename Type>
bool LinkedStack<Type>::isFull(){
    return false; //a linked list is never full
}



template <typename Type>
bool LinkedStack<Type>::push(const Type& newEntry){

    Node<Type> *newNode;

    newNode = new Node<Type>;

    newNode->setValue(newEntry);
    newNode->next = top;
    top = newNode;

    return true;
}//end push()


template <typename Type>
Type LinkedStack<Type>::peek(){
    if(top != nullptr)
        return top->getValue();
}//end peek()


template<typename Type>
bool LinkedStack<Type>::pop(){

    Node<Type> *temp;

    if (top != nullptr){  //only remove from top of the stack
        temp = top;
        top = top->next;
        delete temp;
        return true; //bool variable is better here
    }
    else
        cout << "Cannot pop from empty list..." << endl;
    return false;
}//end pop()



template<typename Type>
void LinkedStack<Type>::copyStack( const LinkedStack<Type>& fromStack){

    cout << "in copyStack3()" << endl;

    if (fromStack.top == nullptr) {
        // fromStack is empty.
        top = nullptr;
        return; //bool is better here
    }

    Node<Type> *fromCurrent = fromStack.top; // we'll use this to walk down the list we're copying
    Node<Type> *newListHead = nullptr; // head of copy
    Node<Type> *newListTail = NULL;  // tail of copy
    while (fromCurrent != nullptr) {
        Node<Type>  * temp = new Node<Type>(fromCurrent->getValue()); // copy node
        if (newListTail == nullptr) { // first thing is list is handled separately
            newListTail= temp;
            newListHead = temp;
            top = temp;
        }
        else { // add to tail of list
            newListTail->next = temp;
            newListTail = temp;
        }
        fromCurrent = fromCurrent->next;
    }


} //end copyStack2

#endif //CTP_250_LAB_5_LINKEDSTACK_H
