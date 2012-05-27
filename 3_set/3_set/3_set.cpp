// 3_set.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Node.h"
#include "My_set.h"

using namespace std;

bool compare_int(int a, int b)
{
	return a == b;
}

int main(int argc, char* argv[])
{
	cout << "Hello world!" << endl;

	My_set<int> * set_int = new My_set<int>(compare_int);
	set_int->addElement(5);

	for (int i = 0; i < set_int->getSize(); i++)
	{
		cout << (*set_int)[i] << endl;
	}

	cin.ignore();

	return 0;
}