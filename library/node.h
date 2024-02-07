#pragma once

template <typename T>

class node
{
	public:
		T element;
		node* next;

	public:
		node(T elem)
		{
			element = elem;
		}

};

