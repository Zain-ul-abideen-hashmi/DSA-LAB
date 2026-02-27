#include "Queue.h"
DynamicQueue::DynamicQueue(int size)
{
    capacity = size;
    items = new int[capacity];
    frontIndex = 0;
    rearIndex = -1;
    count = 0;
}

DynamicQueue::~DynamicQueue()
{
    delete[] items;
}

void DynamicQueue::enqueue(int x) // enqueue means rear i.e it will add items to the rear of the queue
{
    rearIndex = (rearIndex + 1) % capacity;
    items[rearIndex] = x;
    count++;
}

int DynamicQueue::dequeue()  // dequeue is the opposite it will remi

{
    int temp = items[frontIndex];
    frontIndex = (frontIndex + 1) % capacity;
    count--;
    return temp;
}
int DynamicQueue::front()
{
    return items[frontIndex];
}

int DynamicQueue::size()

{
    return count;
}
bool DynamicQueue::isEmpty()

{
    return (count == 0);
}
