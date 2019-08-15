#include <iostream>
#include "StackTemplate.h"

using namespace std;

int main()
{
    // test out the methods available
    Stack<int> myStack;
    cout << "My stack is full: " << boolalpha << myStack.Full() << endl;
    cout << "My stack is empty: " <<  myStack.Empty() << endl;
    cout << "Number of item in stack: " << myStack.Size() << endl;

    cout << "My stack:\n" << myStack << endl;
    int x, y;
    myStack.Pop(x);
    cout << "Top elements was: " << x << endl;
    myStack.Peek(y);
    cout << "Current top element is: " << y << endl;

    myStack.Push(5);
    cout << "My stack:\n" << myStack << endl;
    cout << "Number of item in stack: " << myStack.Size() << endl;

     myStack.Push(5);
    myStack.Push(15);
    cout << "Number of item in stack: " << myStack.Size() << endl;

    myStack.Pop(x);
    cout << "Top elements was: " << x << endl;
    myStack.Peek(y);
    cout << "Current top element is: " << y << endl;
    cout << "My stack:\n" << myStack << endl;

    myStack.Push(52);
    myStack.Push(35);
    myStack.Push(52);
    cout << "Number of item in stack: " << myStack.Size() << endl;
    cout << "My stack:\n" << myStack << endl;

    cout << "My stack is full: " << myStack.Full() << endl;
    cout << "My stack is empty: " << myStack.Empty() << endl;

    myStack.Pop(x);
    cout << "Top elements was: " << x << endl;
    myStack.Peek(y);
    cout << "Current top element is: " << y << endl;
    cout << "Number of item in stack: " << myStack.Size() << endl;
    cout << "My stack:\n" << myStack << endl;
    return 0;
}
