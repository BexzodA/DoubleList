#pragma once

#include <iostream>
#include "DoubleNode.h"

template <class ItemType>
class DoublyLinkedList
{
private:
	class Iterator {
	public:
		Iterator(DoubleNode<ItemType>* node)
			:
			payload(node)
		{

		}
		Iterator& operator++() {
			payload = payload->getNext();
			return *this;
		}
		bool operator!=(const Iterator& rhs)
		{
			return !(payload == rhs.payload);
		}
		DoubleNode<ItemType>& operator*()
		{
			return *this->payload;
		}
	private:
		DoubleNode<ItemType>* payload;
	};
    int size = 0;
    DoubleNode<ItemType> *head =nullptr;
    DoubleNode<ItemType> *tail = nullptr;
	DoubleNode<ItemType>* getHeadPtr() const
	{
		return head;
	}
    public:
		DoublyLinkedList<ItemType>() = default;

	DoublyLinkedList<ItemType>(const DoublyLinkedList<ItemType>& list)
	{
		DoubleNode<ItemType>* copy = list.tail;
		while (copy != nullptr)
		{
			ItemType item = copy->getItem();
			insert(item);
			copy = copy->getPrev();
		}
	}
	//~DoublyLinkedList() {
	//	clear();
	//};
	bool insert(const ItemType& item, const int& position)
	{
		if (position > size + 1 || position <= 0)
		{
			return false;
		}
		DoubleNode<ItemType>* nodeAtPos = getAtPos(position);
		DoubleNode<ItemType>* entry;
		if (head == nullptr)
		{
			head = new DoubleNode<ItemType>(item);
			tail = head;
		}
		else if (position == 1)
		{
			entry = new DoubleNode<ItemType>(item, tail, nullptr);
			tail = entry;
			nodeAtPos->setNext(entry);
		}
		else if (position == size)
		{
			entry = new DoubleNode<ItemType>(item, nullptr, head);
			head->setPrev(entry);
			head = entry;
		}
		else
		{
			entry = new DoubleNode<ItemType>(item, nodeAtPos, nodeAtPos->getNext());
			nodeAtPos->setNext(entry);
		}
		size++;
		return true;
	}
	bool insert(const ItemType& item)
	{
		if (head == nullptr)
		{
			head = new DoubleNode<ItemType>(item);
			tail = head;
		}
		else
		{
			DoubleNode<ItemType>* entry = new DoubleNode<ItemType>(item, nullptr, head);
			if (tail == nullptr)
			{
				tail = entry;
			}
			head->setPrev(entry);
			head = entry;
		}
		size++;
		return true;
	}
	bool remove(const int& pos)
	{
		if (pos < 0 || pos > size)
		{
			return false;
		}
		DoubleNode<ItemType>* nodeBeforePos = getAtPos(pos - 1);
		DoubleNode<ItemType>* nodeNextPos = nodeBeforePos->getNext()->getNext();
		delete nodeBeforePos->getNext();
		nodeBeforePos->setNext(nodeNextPos);
		nodeNextPos->prev = nodeBeforePos;
		size--;
		return true;
	}
	int getSize() const
	{
		return size;
	}
	DoubleNode<ItemType>* getAtPos(const int& pos) const
	{
		DoubleNode<ItemType>* node = tail;
		for (int i = 0; i < pos - 1; i++)
		{
			node = node->getPrev();
		}
		return node;
	}
	bool isEmpty() const
	{
		return size == 0;
	}
	void clear()
	{
		for (int i = 0; i < size; i++)
		{
			remove(i);
		}
		head = nullptr;
		tail = nullptr;
		size = 0;
	}
	void display() const
	{
		DoubleNode<ItemType>* copy = head;
		while (copy->getNext() != nullptr)
		{
			std::cout << copy->getItem() << " ";
			copy = copy->getNext();
		}
		std::cout << copy->getItem() << std::endl;
	}
	void displayBackwards() const
	{
		DoubleNode<ItemType>* tailcopy = tail;
		while (tailcopy->getPrev() != nullptr)
		{
			std::cout << tailcopy->getItem() << " ";
			tailcopy = tailcopy->getPrev();
		}
		std::cout << tailcopy->getItem() << " ";
	}
	void add(const ItemType& item)
	{
		if (head == nullptr)
		{
			head = new DoubleNode<ItemType>(item, nullptr, nullptr);
			tail = head;
		}
		else
		{
			DoubleNode<ItemType>* copy = head;
			while (copy->getNext() != nullptr)
			{
				copy = copy->getNext();
			}
			DoubleNode<ItemType>* entry = new DoubleNode<ItemType>(item, copy, nullptr);
			copy->setNext(entry);
			tail = entry;
		}
		size++;
	}
	bool removeAtBeginning()
	{
		DoubleNode<ItemType>* newHead = head->getNext();
		delete head;
		newHead->setPrev(nullptr);
		head = newHead;
		size--;
		return true;
	}
	Iterator begin() const
	{
		return Iterator(head);
	}
	Iterator end() const
	{
		return Iterator(tail->getNext());
	}
};