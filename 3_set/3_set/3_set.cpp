// 3_set.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Node.h"
#include "My_set.h"
#include <string>
#include <sstream>

#define EVER ;;

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
void printSet(My_set<T>& s)
{
	//if (s == NULL)
		//return;

	for (int i = 0; i < s.getSize(); i++)
	{
		try
		{
			cout << s[i] << " ; ";
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
	cout << "3. Intersection" << endl;
	cout << "4. 1 contains 2" << endl;
	cout << "5. 2 contains 1" << endl;
	cout << "********************" << endl;
}

void enterSet(My_set<int> * s)
{
	int num = 0;
	int elem;
	cout << "Enter number of elements" << endl;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cout << "Enter "  << i << " element" << endl;
		cin >> elem;
		s->addElement(elem);
	}
}

int main(int argc, char* argv[])
{
	My_set<int> * set_int_1 = new My_set<int>(compare_int);
	My_set<int> * set_int_2 = new My_set<int>(compare_int);

	cout << "Enter 1st set" << endl;
	enterSet(set_int_1);
	cout << "Enter 2nd set" << endl;
	enterSet(set_int_2);

	My_set<int> ans = NULL;

	for (EVER)
	{
		cout << "First set" << endl;
		printSet(*set_int_1);
		cout << "Second set" << endl;
		printSet(*set_int_2);

		printMenu();

		int ch = 0;
		bool comp;
		bool exit = false;
		cin >> ch;
		
		switch (ch)
		{
			case 1:
				ans = ((*set_int_1) + (*set_int_2));
				break;
			case 2:
				ans = (*set_int_1) - (*set_int_2);
				break;
			case 3:
				ans = (*set_int_1) * (*set_int_2);
				break;
			case 4:
				comp = (*set_int_1) < (*set_int_2);
				cout << "Comparison test " << comp << endl;
				break;
			case 5:
				comp = (*set_int_2) < (*set_int_1);
				cout << "Comparison test " << comp << endl;
				break;
			default:
				exit = true;
				break;
		}
		if (exit)
			break;

		cout << "Result" << endl;
		printSet(ans);

		//delete ans;
	}

	cin.ignore();

	return 0;
}