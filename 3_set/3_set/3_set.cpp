// 3_set.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Node.h"
#include "My_set.h"
#include <string>
#include <sstream>

using namespace std;

bool compare_int(int a, int b)
{
	return a == b;
}

bool compare_string(string s1, string s2)
{
	return (s1.compare(s2) == 0) ? true : false;
}

void fillIntSet(My_set<int> * set_int, int start, int end)
{
	for (int i = start; i < end; i++)
	{
		set_int->addElement(i);
	}
}

void fillStringSet(My_set<string> * set_string, int start, int end)
{
	ostringstream oss;
	for (int i = start; i < end; i++)
	{
		oss.str("");
		oss << "This is "  << i << " ";
		set_string->addElement(oss.str());
	}
}

template <class T>
void printSet(My_set<T> * s)
{
	for (int i = 0; i < s->getSize(); i++)
	{
		try
		{
			cout << (*s)[i] << " ; ";
		}
		catch(...)
		{
			cout << "Suppressed exception" << endl;
		}
	}
	cout << endl;
}

void printMenu()
{
	cout << "********************" << endl;
	cout << "1. Plus" << endl;
	cout << "2. Minus" << endl;
	cout << "********************" << endl;
}

int main(int argc, char* argv[])
{
	My_set<int> * set_int_1 = new My_set<int>(compare_int);
	My_set<int> * set_int_2 = new My_set<int>(compare_int);

	fillIntSet(set_int_1, 0, 8);
	fillIntSet(set_int_2, 5, 10);

	cout << "First set" << endl;
	printSet(set_int_1);
	cout << "Second set" << endl;
	printSet(set_int_2);

	printMenu();

	int ch = 0;
	cin >> ch;
	switch (ch)
	{
		case 1:
			set_int_1->add(set_int_2);
			break;
		case 2:
			set_int_1->subtract(set_int_2);
			break;
	}

	cout << "First set" << endl;
	printSet(set_int_1);
	cout << "Second set" << endl;
	printSet(set_int_2);

	cin.ignore();
	cin.ignore();

	return 0;
}