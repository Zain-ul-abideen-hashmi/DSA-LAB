#ifndef STACK_H
#define STACK_H

template <class T>
class DynamicStack {
private:
    T* arr;
    int top;
    int size;

public:
    DynamicStack();
    DynamicStack(int s);
    ~DynamicStack();

    bool isEmpty() const;
    bool isFull() const;
    bool push(T value);
    bool pop(T& value);
};

#endif
