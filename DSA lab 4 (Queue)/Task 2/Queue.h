#pragma once
class DynamicQueue {
private:
    int* items;
    int frontIndex;
    int rearIndex;
    int count;
    int capacity;

public:
    DynamicQueue(int size = 100);
    ~DynamicQueue();
    void enqueue(int x);
    int dequeue();
    int front();
    int size();
    bool isEmpty();
};
