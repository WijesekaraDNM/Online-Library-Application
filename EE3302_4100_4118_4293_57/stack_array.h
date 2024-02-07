#pragma once
#include <iostream>

using namespace std;

struct downMat
{
	string name;
	string date;
}; // structure to store material and download date

class stack_array
{
public:
	int top;
	int capacity;
	downMat* data;

public:
	stack_array()
	{
		capacity = 100;
		data = new downMat[capacity];
		top = 0;
	}

	stack_array(int k)
	{
		capacity = k;
		data = new downMat[capacity];
		top = 0;
	}

	void push(downMat value) // insert the value on top
	{
		if (top >= capacity)
		{
			cout << "stack is full" << endl;
		}
		else
		{
			data[top] = value;
			top++;
		}
	}

	downMat pop()//return the top value
	{
		if (top == 0)
		{
			downMat empty;
			empty.name = "Empty";
			empty.date = "Empty";
			cout << "stack is empty" << endl;
			return empty;
		}
		else
		{
			top--;
			return data[top];
		}
	}

	void traverse()//print all the values
	{
		for (int i = 0; i < top; i++)
		{
			cout << "\t\t\t\t\t" << i + 1 << "." << data[i].name <<"\t\t"<< data[i].date<< endl;
		}
		if (top == 0)
		{
			cout << "\t\t\t\t\tNo downloads"<<endl;
		}
	}

	int searchDownloads(downMat name)
	{
		int count = 0;
		for (int i = 0; i < top; i++)
		{
			if (name.name == data[i].name)
			{
				count++;
			}
		}
		if (count != 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}

	}

	bool existData(downMat Data)
	{
		bool isThere = false;
		if (top == 0)
		{
			cout << "stack is empty" << endl;
			isThere = false;
		}
		else
		{
			for (int i = 0; i < top; i++)
			{
				if (data[i].name == Data.name)
				{
					isThere = true;
					break;
				}
			}
			
		}
		return isThere;
	}
};

