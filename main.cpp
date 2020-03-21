#include "DoublyLinkedList.h"
#include <iostream>
#include <cassert>

int main()
{
	DoublyLinkedList<int> t;
	t.insert(1);
	t.insert(2);
	t.insert(3);
	for (auto& e : t) {
		std::cout << e << std::endl;
	}
	//t.removeAtBeginning();
	// t.display(); 
	//t.displayBackwards();
	//t.display();
	// DoublyLinkedList<int> t1(t);
	// t1.display();
	// t.insert(0,1);
	// std::cout<<t.getAtPos(1)->getItem();
	// t.displayBackwards();
	return 0;
}