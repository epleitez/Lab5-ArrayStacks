//
// Created by Emely Pleitez on 10/6/22.
//

#ifndef CTP_250_LAB_5_STACKINTERFACE_H
#define CTP_250_LAB_5_STACKINTERFACE_H

template <typename Type>
class StackInterface
{

public:

    virtual bool isEmpty() = 0;
    virtual bool push(const Type& newEntry) = 0; //
    virtual bool pop() = 0;
    virtual Type peek() = 0;
    virtual bool isFull() = 0;


};


#endif //CTP_250_LAB_5_STACKINTERFACE_H
