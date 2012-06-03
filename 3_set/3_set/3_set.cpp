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

void fillIntSet(My_set<int> * set_int)
{
	for (int i = 0; i < 15; i++)
	{
		set_int->addElement(i);
	}
	set_int->removeElement(13);
}

void fillStringSet(My_set<string> * set_string)
{
	cout << "String set" << endl;
	ostringstream oss;
	for (int i = 0; i < 5; i++)
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
		cout << (*s)[i] << " ; ";
	}
	cout << endl;
}

int main(int argc, char* argv[])
{
	cout << "Hello world!" << endl;

	My_set<int> * set_int = new My_set<int>(compare_int);
	My_set<string> * set_string = new My_set<string>(compare_string);

	fillIntSet(set_int);
	fillStringSet(set_string);

	printSet(set_int);
	printSet(set_string);

	cin.ignore();

	return 0;
}