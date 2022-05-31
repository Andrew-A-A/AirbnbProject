#include "Stack.h"
template<class T>
Stack<T>::Stack(void)
{
    elements = 0;
    capacity = 10;
    Arr = new int[capacity];
}
template<class T>
Stack<T>::Stack(int StackSize)
{
    elements = 0;
    capacity = StackSize;
    Arr = new int[capacity];
}

template<class T>
void Stack<T>::push( T NewElement)
{
    if (capacity == elements)
    {
        expand();
    }
    Arr[elements] = NewElement;
    elements++;
}

template<class T>
void Stack<T>::pop()
{
    elements--;
}

template<class T>
void Stack<T>::expand()
{
    int *NewArr = new int [capacity*2];
    for (int i = 0; i < capacity; i++)
    {
        NewArr[i] = Arr[i];
    }
    capacity *= 2;
    delete[] Arr;
    Arr = NewArr;
}

template<class T>
T Stack<T>::top() {
    return  Arr[length()-1];
}

template<class T>
int Stack<T>::length() {
    return elements;
}

template<class T>
Stack<T>::~Stack<T>(void) {
 delete Arr;
}
