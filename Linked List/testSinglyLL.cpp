// Test the SinglyLinkedList

#include <iostream>
#include "SinglyLinkedListTemplate.h"

using namespace std;

int main()
{
    cout << "Hello World." << endl;
    SinglyLinkedList<int> myList;
    myList.InsertAfterPosition(5, 0);
    cout << "my List has " << myList.Size() << " elements." << endl;
    myList.InsertAfterPosition(6, myList.Size());
    myList.InsertAfterPosition(7, myList.Size());
    myList.InsertAfterPosition(8, 0);
    myList.InsertAfterPosition(9, myList.Size());
    myList.InsertAfterPosition(17, 2);
    myList.InsertAfterPosition(27, 5);
    myList.Delete(5);
    myList.Delete(8);
    myList.Delete(9);
    myList.Delete(11);
    cout << myList << endl;
    cout << "my List has " << myList.Size() << " elements." << endl;

    return 0;
}
