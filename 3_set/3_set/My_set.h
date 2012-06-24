#pragma once

#include "Node.h"

template <class T>
class My_set
{
	public:
		My_set(bool (*func)(T, T));
		~My_set();

		//Конструктор копий
		My_set(My_set&);

		int getSize() const;
		void addElement(T e);
		void removeElement(T e);
		bool contains(T e);
		void add(My_set * s);
		void subtract(My_set * s);
		void clear();

		T operator [] (int);
		My_set& operator + (My_set*);
		My_set& operator - (My_set*);
		My_set& operator * (My_set*);
		bool operator < (My_set*);

		class exBoundary
		{
			private:
				int m_index;

			public:
				exBoundary(int i) { m_index = i; }
				~exBoundary() {};
				int getIndex() {return m_index; };
		};

		class exExists {};

		bool (*compareFunc)(T e1, T e2);

	private:
		Node<T> *pElem;
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
	this->clear();
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
			while (p->pNext != NULL)
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
	Node<T> * p = pElem;
	while (p != NULL)
	{
		Node<T> * tmp = p;
		p = p->pNext;
		delete tmp;
	}

	pElem = NULL;
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
	if ((index > this->getSize() - 1) ||
		(index < 0))
		throw exBoundary(index);

	Node<T> * n = pElem;
	for (int i = 0; i < index; i++)
		n = n->pNext;

	return n->value;
}

template <class T>
void My_set<T>::add(My_set * s)
{
	for (int i = 0; i < s->getSize(); i++)
	{
		this->addElement((*s)[i]);
	}
}

template <class T>
void My_set<T>::subtract(My_set * s)
{
	for (int i = 0; i < s->getSize(); i++)
	{
		this->removeElement((*s)[i]);
	}
}


template <class T>
My_set<T>::My_set(My_set& s)
{
	this->pElem = NULL;
	this->compareFunc = s.compareFunc;
	for (int i = 0; i < s.getSize(); i++)
	{
		this->addElement(s[i]);
	}
}

template <class T>
My_set<T>& My_set<T>::operator-(My_set* s)
{
	My_set<T> &ret = My_set<T>(*this);
	for (int i = 0; i < s.getSize(); i++)
	{
		ret.removeElement(s[i]);
	}

	return ret;
}

template <class T>
My_set<T>& My_set<T>::operator*(My_set& s)
{
	My_set<T> ret(this->compareFunc);
	for (int i = 0; i < this->getSize(); i++)
		for (int j = 0; j < s.getSize(); j++)
			if (this->compareFunc((*this)[i], (*s)[j]))
				ret.addElement((*this)[i]);

	return ret;
}

template <class T>
My_set<T>& My_set<T>::operator+(My_set* s)
{
	My_set<T> ret(*this);
	for (int i = 0; i < s.getSize(); i++)
	{
		ret.addElement((*s)[i]);
	}

	return ret;
}

template <class T>
bool My_set<T>::operator<(My_set* s)
{
	bool validSize = this->getSize() <= s.getSize();
	bool containAll = true;

	for (int i = 0; i < this->getSize(); i++)
	{
		if (!s.contains((*this)[i]))
		{
			containAll =  false;
			break;
		}
	}

	return validSize && containAll;
}