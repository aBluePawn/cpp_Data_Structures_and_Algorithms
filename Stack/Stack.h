// Implementation of a Stack
// Storing the data items in a linked list
#ifndef STACK_H
#define STACK_H

#include <iostream>

template <class Type>
class Stack
{
    private:
        class Node
        {
            public:
                Type Data;
                Node *Next;

                Node(): Next(nullptr){}
                Node(Type newData, Node *pNode = nullptr):
                    Data(newData), Next(pNode){}
        };

        Node* Head;
        size_t size;
    public:
        Stack();
        ~Stack();
        bool Empty() const;
        bool Full() const;
        size_t Size() const;
        bool Push(const Type&);
        bool Pop(Type&);
        bool Peek(Type&);
        void Print(std::ostream&) const;
};

// Overloading the ostream operator
template <class Type> std::ostream& operator<<(std::ostream&, const Stack<Type>&);

#endif
