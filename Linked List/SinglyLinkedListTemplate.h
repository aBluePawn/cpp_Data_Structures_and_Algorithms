#ifndef SINGLYLINKEDLISTTEMPLATE_H
#define SINGLYLINKEDLISTTEMPLATE_H

#include <iostream>
#include "SinglyLinkedList.h"

// Constructor
template <class Type>
SinglyLinkedList<Type>::SinglyLinkedList(): Head(nullptr), size() {}

// Destructor
template <class Type>
SinglyLinkedList<Type>::~SinglyLinkedList()
{
    Node *temp;
    while(Head != nullptr)
    {
        temp = Head;
        Head = Head->Next;
        delete temp;
    }
}

// Check if the list is empty
template <class Type>
bool SinglyLinkedList<Type>::Empty() const
{
    return (Head == nullptr) ? true:false;
    // Alternatively, we can use
    // return (size == 0) ? true:false;
}

template <class Type>
size_t SinglyLinkedList<Type>::Size() const
{
    return size;
}

template <class Type>
bool SinglyLinkedList<Type>::InsertAfterPosition(const Type& newData, size_t pos)
{
    // Case empty list
    if(Empty())
    {
        Head = new Node(newData);
        size++;
    }
    else
    {
        // Case where pos = 0, insert new data item in front of the existing list
        if (pos == 0)
        {
            Node *temp = Head;
            Head = new Node(newData, temp);
            size++;
        }
        // Case where the new data item is inserted somewhere in the middle of the list
        else if(pos < size)
        {
            Node *temp = Head;
            size_t count = 0;
            while(count < pos-1)
            {
                temp = temp->Next;
                count++;
            }
            Node* newNode = new Node(newData, temp->Next);
            temp->Next = newNode;
            size++;
        }
        // Case where the position passed is equal to or larger than the size of the list, add the new data item at the end
        else
        {
            Node *temp = Head;
            while(temp->Next != nullptr)
                temp = temp->Next;
            temp->Next = new Node(newData);
            size++;
        }
    }
    return true;
}

template <class Type>
bool SinglyLinkedList<Type>::Delete(const Type& itemToDelete)
{
    Node *temp = Head;
    // Item to delete is first
    if (temp != nullptr && temp->Data == itemToDelete)
    {
        Head = Head->Next;
        delete temp;
        size--;
        return true; // true == item deleted
    }
    else
    {
       while(temp->Next != nullptr && temp->Next->Data != itemToDelete)
        {   
            temp = temp->Next;
        }
        if(temp->Next != nullptr) // item found
        {
            Node *toDelete = temp->Next;
            temp->Next = temp->Next->Next;
            delete toDelete;
            size--;
            return true;
        } 
    }
    return false; // false == item not deleted
}

template <class Type>
void SinglyLinkedList<Type>::Print(std::ostream& outStream) const
{
    Node *temp;
    temp = Head;
    while (temp != nullptr)
    {
        outStream << temp->Data << " ";
        temp = temp->Next;
    }
}

template <class SType>
std::ostream& operator<<(std::ostream& outStream, const SinglyLinkedList<SType>& list)
{
    list.Print(outStream);
    return outStream;
}
#endif
