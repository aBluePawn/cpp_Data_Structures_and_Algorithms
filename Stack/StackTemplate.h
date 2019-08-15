#ifndef STACKTEMPLATE_H
#define STACKTEMPLATE_H

#include <iostream>
#include "Stack.h"

// Constructor
template <class Type>
Stack<Type>::Stack() : Head(nullptr), size() {}

// Destructor
template <class Type>
Stack<Type>::~Stack()
{
    Node *temp;
    while (Head != nullptr)
    {
        temp = Head;
        Head = Head->Next;
        delete temp;
    }
}

// Check if the stack is empty
template <class Type>
bool Stack<Type>::Empty() const
{
    return (Head == nullptr) ? true : false;
    // Alternatively, we can use
    // return (size == 0) ? true:false;
}

// Check if the stack is full
// Because I am using a linked list, the stack should never be full
template <class Type>
bool Stack<Type>::Full() const
{
    return false;
}

template <class Type>
size_t Stack<Type>::Size() const
{
    return size;
}

template <class Type>
bool Stack<Type>::Push(const Type &newData)
{
    Head = new Node(newData, Head);
    size++;
    return true;
}

template <class Type>
bool Stack<Type>::Pop(Type &itemToPop)
{
    if (Head != nullptr)
    {
        itemToPop = Head->Data;
        Node *temp = Head;
        Head = Head->Next;
        delete temp;
        size--;
        return true;
    }
    else
    {
        return false;
    }
}

template <class Type>
bool Stack<Type>::Peek(Type &itemOnTop)
{
    if (Head != nullptr)
    {
        itemOnTop = Head->Data;
        return true;
    }
    else
    {
        return false;
    }
}

template <class Type>
void Stack<Type>::Print(std::ostream &outStream) const
{
    if (Head != nullptr)
    {
        Node *temp;
        temp = Head;
        while (temp != nullptr)
        {
            outStream << temp->Data << '\n';
            temp = temp->Next;
        }
    }
}

template <class Type>
std::ostream &operator<<(std::ostream &outStream, const Stack<Type> &list)
{
    list.Print(outStream);
    return outStream;
}
#endif
