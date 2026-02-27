#pragma once
template<class ItemType>
class DynamicQueue {
private:
    ItemType* items;
    int front;
    int rear;
    int count;
    int capacity;
public:
    DynamicQueue(int maxSize = 100);
    DynamicQueue(const DynamicQueue& other);
    ~DynamicQueue();
    bool IsEmpty() const;
    bool IsFull() const;
    void Enqueue(ItemType newItem);
    void Dequeue(ItemType& item);
    ItemType Peek() const;
    int Size() const;
    int Capacity() const;
    void Display() const;
    void Resize(int newCapacity);
    DynamicQueue& operator=(const DynamicQueue& other);
private:
    void CopyFrom(const DynamicQueue& other);
};
