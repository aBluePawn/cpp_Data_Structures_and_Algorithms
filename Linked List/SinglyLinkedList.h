// Implementation of a Singly Linked List
#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <iostream>

template <class Type>
class SinglyLinkedList
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
        SinglyLinkedList();
        ~SinglyLinkedList();
        bool Empty() const;
        size_t Size() const;
        bool InsertAfterPosition(const Type&, size_t);
        bool Delete(const Type&);
        void Print(std::ostream&) const;
        
};

// Overloading the ostream operator
// most helpful post: http://www.cplusplus.com/forum/general/33886/
template <class Type> std::ostream& operator<<(std::ostream&, const SinglyLinkedList<Type>&);

#endif
