#pragma once

#include <iostream>

using namespace std;

template <class T>
class Node
{
	public:
		Node();
		~Node();

		T value;
		Node * pNext;
};

template <class T>
Node<T>::Node()
{
	//value = NULL;
	pNext = NULL;
}

template <class T>
Node<T>::~Node()
{
	cout << "Node destructor with value...."
		<< value << endl;
}