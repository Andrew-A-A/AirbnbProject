#include <iostream>
using namespace std;
template <class T>
class Queue{
    int capacity=10, elements=0, Front=-1, back=-1;
    T* ArrayQueue;
public:
    Queue();
    Queue<T>(int QueueSize);
    void push(T NewElement), pop();
    bool IsFull();
    bool IsEmpty();
    void expand();
    T front();
    int size();
    ~Queue(void);
};


