#include <iostream>
template<class T>
class Stack
{
    int elements=0, capacity=10, * Arr;

public :
    Stack<T>(void);
    Stack<T>(int StackSize);
    void push( T NewElement);
    T top();
    void pop();
    void expand();
    int length();
    // m3rf4 hnst5dmo f haga wla laa --> bool empty();
    ~Stack<T>(void);
};