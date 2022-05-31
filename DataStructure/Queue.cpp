#include <iostream>
#include "Queue.h"
#include <assert.h>
using namespace std;

template <class T>
Queue<T>::Queue (int QueueSize) // constructor
{
    capacity = QueueSize;
    ArrayQueue = new T[capacity];
}


template<class T>
bool Queue<T>::IsEmpty() {
    if (elements==0) {
        Front=back=-1;
        return true;
    }
    else
        return false;
}
template <class T>
void Queue<T>::push(T NewElement)
{
    if (IsFull()){
        expand();
    }
    if (elements == 0)
    {
        Front = 0;
    }
    back = ((back+1) %capacity);
    ArrayQueue[back] = NewElement;
    elements++;
}

template <class T>
void Queue<T>::pop() {
    assert(!IsEmpty());
    if (elements == 1) {
        Front = -1;
        back = -1;
    } else {
        Front = ((Front + 1) % size());
    }
    elements--;
}
    template <class T>
    T Queue<T>::front()
    {
        assert(!IsEmpty());
        return ArrayQueue[Front];
    }
template <class T>
void Queue<T>::expand()
{
    T *NewArr = new T [capacity*2];
    for (int i = 0; i < capacity; i++)
    {
        NewArr[i] = ArrayQueue[i];
    }
    capacity *= 2;
    delete[] ArrayQueue;
    ArrayQueue = NewArr;
}

template<class T>
int Queue<T>::size() {
    return elements;
}

template<class T>
Queue<T>::Queue() {
    ArrayQueue= new T[capacity];
}

template<class T>
bool Queue<T>::IsFull() {
    if (elements==capacity)
        return true;
    else
        return false;
}
template <class T>
Queue<T>::~Queue(void)  // destructor
{
    delete[] ArrayQueue;
}

