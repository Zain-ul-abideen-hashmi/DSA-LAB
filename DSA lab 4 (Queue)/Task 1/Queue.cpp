#include "Queue.h"
#include <iostream>
using namespace std;
template<class ItemType>
DynamicQueue<ItemType>::DynamicQueue(int maxSize) {
	capacity = maxSize;
	items = new ItemType[capacity];
	front = 0;
	rear = -1;
	count = 0;
}
template<class ItemType>
DynamicQueue<ItemType>::DynamicQueue(const DynamicQueue& other)
{
	CopyFrom(other);
}

template<class ItemType>
DynamicQueue<ItemType>::~DynamicQueue()
{
	delete[] items;
}

template<class ItemType>
void DynamicQueue<ItemType>::CopyFrom(const DynamicQueue& other)

{

	capacity = other.capacity;
	count = other.count;
	front = other.front;
	rear = other.rear;
	items = new ItemType[capacity];

	for (int i = 0; i < capacity; i++)
	{
		items[i] = other.items[i];
	}
}
template<class ItemType>
DynamicQueue<ItemType>&
DynamicQueue<ItemType>::operator=(const DynamicQueue& other)
{
	if (this != &other)
	{
		delete[] items;
		CopyFrom(other);
	}
	return *this;
}
template<class ItemType>
bool DynamicQueue<ItemType>::IsEmpty() const {
	return (count == 0);
}
template<class ItemType>
bool DynamicQueue<ItemType>::IsFull() const {
	return (count == capacity);
}
template<class ItemType>
void DynamicQueue<ItemType>::Enqueue(ItemType newItem)
{
	if (IsFull())

	{
		Resize(capacity * 2);
	}
	rear = (rear + 1) % capacity;
	items[rear] = newItem;
	count++;
}
template<class ItemType>
void DynamicQueue<ItemType>::Dequeue(ItemType& item)
{
	if (IsEmpty())
	{
		cout << "Queue Underflow!" << endl;
		return;
	}
	item = items[front];
	front = (front + 1) % capacity;
	count--;
}
template<class ItemType>
ItemType DynamicQueue<ItemType>::Peek() const
{
	if (IsEmpty())
	{
		cout << "Queue is empty!" << endl;
		return ItemType();
	}
	return items[front];
}
template<class ItemType>
int DynamicQueue<ItemType>::Size() const
{
	return count;
}
template<class ItemType>
int DynamicQueue<ItemType>::Capacity() const
{
	return capacity;
}
template<class ItemType>
void DynamicQueue<ItemType>::Display() const
{
	if (IsEmpty())
	{
		cout << "Queue is empty!" << endl;
		return;
	}
	cout << "Queue (Front to Rear): ";
	for (int i = 0; i < count; i++)
	{
		int index = (front + i) % capacity;
		cout << items[index] << " ";
	}
	cout << endl;
}

template<class ItemType>
void DynamicQueue<ItemType>::Resize(int newCapacity)
{
	if (newCapacity <= capacity)
		return;
	ItemType* newItems = new ItemType[newCapacity];
	for (int i = 0; i < count; i++) {
		int oldIndex = (front + i) % capacity;
		newItems[i] = items[oldIndex];
	}
	delete[] items;
	items = newItems;
	capacity = newCapacity;
	front = 0;
	rear = count - 1;
	cout << "Queue resized to capacity: "
		<< capacity << endl;
}
template class DynamicQueue<int>;
template class DynamicQueue<string>;
