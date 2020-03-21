#pragma once	

template <class ItemType>
class DoubleNode
{
    public:
    DoubleNode<ItemType> *next = nullptr;
    DoubleNode<ItemType> *prev = nullptr;
    ItemType item;
    public:
		DoubleNode() = default;
	DoubleNode(ItemType item, DoubleNode<ItemType>* prev = nullptr, DoubleNode<ItemType>* next = nullptr) 
		: 
		item(item), 
		prev(prev), 
		next(next) 
	{ 

	}
	ItemType getItem() const
	{
		return this->item;
	}
	void setNext(DoubleNode<ItemType>* next)
	{
		this->next = next;
	}
	void setPrev(DoubleNode<ItemType>* prev)
	{
		this->prev = prev;
	}
	void setItem(ItemType item)
	{
		this->item = item;
	}
	DoubleNode<ItemType>* getNext() const
	{
		return next;
	}
	DoubleNode<ItemType>* getPrev() const
	{
		return prev;
	}


};

template<typename ItemType>
std::ostream& operator<<(std::ostream& os, const DoubleNode<ItemType>& rhs) 
{
	os << rhs.getItem();
	return os;
}