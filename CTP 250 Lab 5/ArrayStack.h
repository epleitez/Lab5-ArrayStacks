//
// Created by Emely Pleitez on 10/6/22.
//

#ifndef CTP_250_LAB_5_ARRAYSTACK_H
#define CTP_250_LAB_5_ARRAYSTACK_H

#include "StackInterface.h"
#include <iostream>

using namespace std;

const int MAX_STACK = 5;

template <typename Type> //template<class....
class ArrayStack : public StackInterface<Type>
{
public:
    ArrayStack();
    ArrayStack(const ArrayStack<Type>& theOtherStack);
    bool isEmpty();
    bool isFull();
    bool push(const Type& newEntry); //adds one only if there is room
    bool pop();
    Type peek() ;
    void copyStack(const ArrayStack<Type>& theOtherStack);



private:
    Type items[MAX_STACK];
    int top; //top of the stack
};

//Function definitions:

template<typename Type>
ArrayStack<Type>::ArrayStack(const ArrayStack<Type>& theOtherStack){
    copyStack(theOtherStack);
}//copy constructor


template<typename Type>
ArrayStack<Type>::ArrayStack(){  //option here: ArrayStack<Type>::ArrayStack(): top(-1);
    top = -1;
}//default constructor


template <typename Type>
bool ArrayStack<Type>::isEmpty()  {
    return (top <= -1);
}

template<typename Type>
bool ArrayStack<Type>::push(const Type& newEntry){
    bool result = false;
    if (!isFull()){
        //if (top < MAX_STACK - 1) { //is there room for one more?  could use if(!isFull()), too
        top++;
        items[top] = newEntry;
        result = true;
    } //end if

    return result;
}//end push ()

template<typename Type>
bool ArrayStack<Type>::pop(){

    bool result = false;
    if (!isEmpty()) {
        top--;
        result = true;

    }//end if

    return result;
} //end pop()


template<typename Type>
Type ArrayStack<Type>::peek(){
    if (!isEmpty())
        return items[top];
}

template<typename Type>
bool ArrayStack<Type>::isFull(){
    return (top == MAX_STACK - 1);
}



//deep copy: copying element by element. would be shallow if it was copying the addresses
template<typename Type>
void ArrayStack<Type>::copyStack(const ArrayStack<Type>& theOtherStack) {


    int howManyInOtherStack = theOtherStack.top;
    this->top = theOtherStack.top;  //top = theOtherStack.top;


    //cout << "the other stack max index: " << theOtherStack.top << endl;

    for (int i = 0; i <= howManyInOtherStack; i++){

        items[i] = theOtherStack.items[i];

    }//end for

}//end copyStack()











#endif //CTP_250_LAB_5_ARRAYSTACK_H
