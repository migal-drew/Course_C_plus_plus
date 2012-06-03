#pragma once

#include "Node.h"

template <class T>
class My_set
{
	public:
		My_set(bool (*func)(T, T));
		~My_set();

		int getSize() const;
		void addElement(T e);
		void removeElement(T e);
		bool contains(T e);
		My_set minus(My_set s);
		My_set plus(My_set s);
		void clear();
		T operator [] (int);

	private:
		Node<T> *pElem;
		bool (*compareFunc)(T e1, T e2);
};

template <class T>
My_set<T>::My_set(bool (*func)(T e1, T e2))
{
	compareFunc = func;
	pElem = NULL;
}

template <class T>
My_set<T>::~My_set()
{
	Node<T> * p = pElem;
	while (p != NULL)
	{
		if (p->pNext == NULL)
		{
			p->pNext = new Node(e);
			p = p->pNext;
		}
	}
}

template <class T>
bool My_set<T>::contains(T e)
{
	Node<T> * p = pElem;
	while (p != NULL)
	{
		if (compareFunc(p->value, e))
			return true;
		p = p->pNext;
	}

	return false;
}

template <class T>
void My_set<T>::addElement(T e)
{
	if (this->contains(e))
		return;

	if (pElem == NULL)
	{
		pElem = new Node<T>();
		pElem->value = e;
	}
	else
	{
		Node<T> * p = pElem;
		while (p != NULL)
		{
			if (p->pNext == NULL)
			{
				p->pNext = new Node<T>();
				p->pNext->value = e;
				p = p->pNext;

				return;
			}
			else
			{
				p = p->pNext;
			}
		}
	}
}

template <class T>
void My_set<T>::removeElement(T e)
{
	if (pElem != NULL)
	{
		if (compareFunc(pElem->value, e))
		{
			Node<T> * tmp = pElem;
			pElem = pElem->pNext;
			delete tmp;
		}
		else
		{
			Node<T> * p = pElem;
			while (p != NULL)
			{
				if (compareFunc(p->pNext->value, e))
				{
					Node<T> * tmp = p->pNext;
					p->pNext = tmp->pNext;
					delete tmp;

					return;
				}
				else
				{
					p = p->pNext;
				}
			}
		}
	}
}

template <class T>
void My_set<T>::clear()
{
	Node * p = pElem;
	while (p != NULL)
	{
		Node * tmp = p;
		p = p->pNext;
		delete tmp;
	}
}

template <class T>
int My_set<T>::getSize() const
{
	int count = 0;
	Node<T> * p = pElem;
	while (p != NULL)
	{
		p = p->pNext;
		count++;
	}

	return count;
}

template <class T>
T My_set<T>::operator [] (int index)
{
	if (index > this->getSize() - 1)
		return NULL;

	Node<T> * n = pElem;
	for (int i = 0; i < index; i++)
		n = n->pNext;

	return n->value;
}