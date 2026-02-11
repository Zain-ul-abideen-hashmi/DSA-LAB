#include "Stack.h"

template <class T>
DynamicStack<T>::DynamicStack()
{
    size = 10;
    arr = new T[size];
    top = -1; // for + and - when it will work so that it goes to the top of the stack
}

template <class T>
DynamicStack<T>::DynamicStack(int s)
{
    size = s;
    arr = new T[size];
    top = -1;
}

template <class T>
DynamicStack<T>::~DynamicStack()
{
    delete[] arr;
}

template <class T>
bool DynamicStack<T>::isEmpty() const
{
    return (top == -1);
}

template <class T>
bool DynamicStack<T>::isFull() const
{
    return (top == size - 1);
}

template <class T>
bool DynamicStack<T>::push(T value)
{
    if (isFull())
        return false;

    arr[++top] = value;
    return true;
}

template <class T>
bool DynamicStack<T>::pop(T& value)
{
    if (isEmpty())
        return false;

    value = arr[top--];
    return true;
}

template class DynamicStack<int>;
