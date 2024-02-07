#pragma once

#include <iostream>

using namespace std;

class Queue_Array
{
public:
	int size;		//marks the size of the queue
	int capacity;	//marks the size of the array
	int front;		//marks the start of the queue
	int rear;		//marks the end of the queue
	string* data;		//array

	Queue_Array(int cap)
	{
		size = 0;
		capacity = cap;
		data = new string[capacity];
		front = -1;
		rear = 0;
	}

public:

	void enQueue(string val)
	{
		if (size >= capacity)//another statement -> rear>=front
		{
			cout << "Queue is full" << endl;
		}
		else
		{
			if (front == -1)
			{
				front = 0;
			}
			data[rear] = val;
			rear = (rear + 1) % capacity;
			size++;
		}
	}

	string deQueue()
	{
		if (size == 0)
		{
			cout << "Queue is empty" << endl;
		}
		else
		{
			string temp = data[front];
			front = (front+1)%capacity;
			size--;
			return temp;
		}
		
	}

	void print()
	{
		int index = front;
		for (int i = 0; i < size; i++)
		{
			cout << data[index] << " ";
			index = (index + 1) % capacity;
		}
		cout << endl;
	}
};

