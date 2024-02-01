//
// Created by Emely Pleitez on 10/6/22.
//

#ifndef CTP_250_LAB_5_NODE_H
#define CTP_250_LAB_5_NODE_H

using namespace std;

/*  if you were making this an object, Duck object, would need getters and setters for all attributes
    Node* remains the same, all attributes in private.
*/

template <typename Type>
class Node
{
public:
    Node();
    virtual ~Node();
    Node(Type);
    Node* next;
    Type getValue();
    void setValue(Type);


private:
    Type value;
};

template <typename Type>
Node<Type>::Node()
{
    //value = 0;
    next = nullptr;
}

template <typename Type>
Node<Type>::Node(Type newValue){
    value = newValue;
    next = nullptr;
}

template <typename Type>
Node<Type>::~Node()
{
    //dtor
}

template <typename Type>
Type Node<Type>::getValue(){
    return value;
}

template <typename Type>
void Node<Type>::setValue(Type newValue){
    value = newValue;
}


#endif //CTP_250_LAB_5_NODE_H
