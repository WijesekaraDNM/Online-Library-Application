#pragma once
#include <iostream>
#include "node.h"
#include "User.h"
#include "Books.h"
#include "Magazines.h"
#include "others.h"

using namespace std;

struct verify {
	bool isThere;
	string pass;
};

template <typename T>

class singly_linked_list
{
private:
	node<T>* head;
	node<T>* tail;
	int size;

public:
	singly_linked_list()//constructor
	{
		head = NULL;
		tail = NULL;
		size = 0;
	}

	int getSize()
	{
		return size;
	}

	void insertFirst(T element)
	{
		node<T>* temp = new node<T>(element);

		if (size == 0)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			temp->next = head;//create the link
			head = temp;//new head
		}
		size = size + 1;
	}

	void insertLast(T element)
	{
		node<T>* temp = new node<T>(element);

		if (tail == NULL)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			tail->next = temp;//create the link
			tail = temp;
		}
		size = size + 1;
	}

	void insertAt(T element, int position) // add the element to any position
	{
		if (position<0 || position > size)//outside of the list
		{
			cout << "Invaild position" << endl;
		}
		else if (position == 1)//first
		{
			insertFirst(element);
		}
		else if (position == size)//last
		{
			insertLast(element);
		}
		else
		{
			node<T>* temp = new node<T>(element);
			node<T>* current = head;

			for (int i = 0; i < position - 1; i++)
			{
				current = current->next;
			}

			temp->next = current->next;
			current->next = temp;

			size = size + 1;

		}
	}

	//userlist functions
	// use to find existance of a user
	bool searchUser(string value)
	{
		bool isUsPresent = false;

		if (size != 0)
		{
			node<T>* current = head;

			for (int i = 0; i < size; i++)
			{
				if (current->element.userName == value)
				{
					isUsPresent = true;
					//cout << "Detected" << endl;
					break;
				}
				else
				{
					current = current->next;
				}
			}
		}
		else
		{
			isUsPresent = false;
		}

		return isUsPresent;
	} 

	verify searchUser2(string value, node<T>* currentNode)
	{
		bool isUsPresent = false;
		string pass;
		verify userVerify;

		if (size != 0)
		{
			node<T>* current = head;

			for (int i = 0; i < size; i++)
			{
				if (current->element.userName == value)
				{
					isUsPresent = true;
					//cout << "Detected" << endl;
					currentNode = current;
					pass = current->element.password;
					break;
				}
				else
				{
					current = current->next;
				}
			}
		}
		else
		{
			isUsPresent = false;
		}
		userVerify.isThere = isUsPresent;
		userVerify.pass = pass;

		return userVerify;
	}
	//use to set a user as a current user
	void searchUserDetails(string UsName,node<T>* currentUser) // design to get user details and node address
	{

		if (size != 0)
		{
			node<T>* current = head;
			//T* CurrentUs = current->element;

			for (int i = 0; i < size; i++)
			{
				if (current->element.userName == UsName)
				{
					currentUser = current;
					break;
				}
				else
				{
					current = current->next;
				}
			}
		}
	}

	bool verifyPassword(string passW, node<T>* currentNode)
	{
		if (currentNode->element.password == passW)
		{
			return true;
		}
		else
			return false;
	}

	//to obtain user position
	int posUserNode(string UsName)
	{
		int pos = 0;
		node<T>* current = head;

		for (int i = 0; i<size;i++)
		{
			pos = pos + 1;
			if (UsName == current->element.userName)
			{
				break;
			}
		}
		return pos;
	}

	//Booklist fuctions
	void addBooksUser(downMat nameBook, int pos)
	{
		node<T>* current = head;

		for (int i = 0; i < pos-1; i++)
		{
			current = current->next;
		}

		current->element.addDownloads(nameBook);
	}

	void showDownloadUser(int pos)
	{
		node<T>* current = head;

		for (int i = 0; i < pos-1; i++)
		{
			current = current->next;
		}

		current->element.UserDownloads->traverse();
	}

	void searchDownloadedBooks(int pos)
	{
		node<T>* current = head;

		for (int i = 0; i < pos - 1; i++)
		{
			current = current->next;
		}

		current->element.UserDownloads->searchDownloads();
	}

	//test method for traverse to a user
	/*void traverseUserNode(string usName, T* currentUser)
	{
		if (size != 0)
		{
			node<T>* current = head;

			for (int i = 0; i < size; i++)
			{
				if (current->element.userName == usName)
				{
					//isUsPresent = true;
					cout << "Detected" << endl;
					T* temp = &current->element;
					currentUser = temp;
					break;
				}
				else
				{
					current = current->next;
				}
			}
		}	
	}*/

	//test method for return address of a user
	/*T* returnUser(string UsNam)
	{
		node<T> current = head;
		if (size != 0)
		{
			if (UsNam == current->element)
			{
				return current->element;
			}
			else
			{
				cout << "Not Found" << endl;
			}
		}
	}*/

	void viewBooks()
	{
		node<T>* current = head;
		
		moveCursorFunc(13, 15);
		cout << "Title";
		moveCursorFunc(13, 38);
		cout << "Type";
		moveCursorFunc(13, 55);
		cout << "Author";
		moveCursorFunc(13, 75);
		cout << "Pages";
		//cout << "\t\t Title \t\t Type \t\t Author \t\t Pages "<< endl;

		for (int i = 0; i < size;i++)
		{
			moveCursorFunc(14+i, 5);
			cout << i + 1;
			moveCursorFunc(14+i, 12);
			cout << current->element.Title;
			moveCursorFunc(14+i, 35);
			cout << current->element.Type;
			moveCursorFunc(14+i, 53);
			cout << current->element.Author;
			moveCursorFunc(14+i, 75);
			cout << current->element.Pages;
			//cout <<"\t"<< i+1 << " : " << current->element.Title << "\t\t" << current->element.Type << "\t\t" << current->element.Author << "\t\t" << current->element.Pages << endl;
			current = current->next;
		}
	}

	bool searchBooks(string nameBook)
	{
		node<T>* current = head;
		bool found = false;

		for (int i = 0; i < size; i++)
		{
			if (current->element.Title == nameBook)
			{
				found = true;
				current->element.displayBook();
				break;
			}
			current = current->next;
		}
		return found;
	}

	bool searchBooksAuthor(string authorName)
	{
		node<T>* current = head;
		int numBooks = 0;
		moveCursorFunc(18, 20);
		cout << "Book Title";
		moveCursorFunc(18, 40);
		cout << "Type";
		for (int i = 0; i < size; i++)
		{
			if (current->element.Author == authorName)
			{
				numBooks++;
				Book tempBook = current->element;
				string title = tempBook.Title;
				string type = tempBook.Type;
				moveCursorFunc(18+numBooks, 10);
				cout << numBooks;
				moveCursorFunc(18+numBooks, 17);
				cout << title;
				moveCursorFunc(18+numBooks, 37);
				cout << type;
				//cout << "\t" << numBooks << ".\t\t" << title << "\t\t" << type << endl;
			}
			current = current->next;
		}
		if (numBooks == 0)
		{
			cout << "\t\t\t\t      ****No available books****" << endl;
			return false;
		}
		return true;
	}

	//used to sort the last entered element in a list
	void sortingBooks()
	{
		//structure of display
		moveCursorFunc(18, 15);
		cout << "Title";
		moveCursorFunc(18, 38);
		cout << "Type";
		moveCursorFunc(18, 55);
		cout << "Author";
		moveCursorFunc(18, 75);
		cout << "Pages";

		int* tempArr = new int[size]; // to store the first letter value
		node<T>* currentMat = head;

		int i = 0; // position
		while (i < size) // in order to store orderValues in array
		{
			tempArr[i] = currentMat->element.orderValue;
			currentMat = currentMat->next;
			i++;
		}
		bubbleSort(tempArr, size); // sorting min to max

		int j = 0;
		for (int j = 0; j < size; j++)
		{
			node<T>* printNode = head;
			for (int h = 0; h < size; h++)
			{
				if (printNode->element.orderValue == tempArr[j])
				{
					moveCursorFunc(19 + j, 5);
					cout << j + 1;
					moveCursorFunc(19 + j, 12);
					cout << printNode->element.Title;
					moveCursorFunc(19 + j, 35);
					cout << printNode->element.Type;
					moveCursorFunc(19 + j, 53);
					cout << printNode->element.Author;
					moveCursorFunc(19 + j, 76);
					cout << printNode->element.Pages;
					break;
				}
				printNode = printNode->next;
			}
		}

	}

	//magazineslist functions
	void addMagazineUser(downMat nameMagazine, int pos)
	{
		node<T>* current = head;

		for (int i = 0; i < pos - 1; i++)
		{
			current = current->next;
		}

		current->element.addDownloads(nameMagazine);
	}

	void viewMagazines()
	{
		node<T>* current = head;

		moveCursorFunc(20, 15);
		cout << "Title";
		moveCursorFunc(20, 38);
		cout << "Type";
		moveCursorFunc(20, 55);
		cout << "Authors";
		moveCursorFunc(20, 75);
		cout << "Publication frequency";
		moveCursorFunc(20, 100);
		cout << "Date";
		//cout << "\t\t Title \t\t Type \t\t Author \t\t Pages "<< endl;

		for (int i = 0; i < size; i++)
		{
			moveCursorFunc(21 + i, 5);
			cout << i + 1;
			moveCursorFunc(21 + i, 12);
			cout << current->element.Title;
			moveCursorFunc(21 + i, 35);
			cout << current->element.Type;
			moveCursorFunc(21 + i, 53);
			cout << current->element.Authors;
			moveCursorFunc(21 + i, 80);
			cout << current->element.frqcyofPublication;
			moveCursorFunc(21 + i, 97);
			cout << current->element.Date;
			//cout <<"\t"<< i+1 << " : " << current->element.Title << "\t\t" << current->element.Type << "\t\t" << current->element.Author << "\t\t" << current->element.Pages << endl;
			current = current->next;
		}

		/*node<T>* current = head;

		cout << "\t\tTitle \t\t\t  Type \t\t\t\t  Authors\t\t Publication Frequancy \t\t\t\t\t\t\t Date " << endl;


		for (int i = 0; i < size; i++)
		{
			cout << "\t" << i + 1 << " : " << current->element.Title << "\t\t\t" << current->element.Type << "\t\t\t   " << current->element.Authors << "\t\t\t" << current->element.frqcyofPublication << "\t\t\t\t      " << current->element.Date << endl;
			current = current->next;
		}*/
	}

	bool searchMagazines(string nameMagazine)
	{
		node<T>* current = head;
		bool found = false;

		for (int i = 0; i < size; i++)
		{
			if (current->element.Title == nameMagazine)
			{
				found = true;
				current->element.displayMagazines();
				break;
			}
			current = current->next;
		}
		return found;
	}

	void sortingMagazines()
	{
		//structure of display
		moveCursorFunc(18, 15);
		cout << "Title";
		moveCursorFunc(18, 38);
		cout << "Type";
		moveCursorFunc(18, 55);
		cout << "Authors";
		moveCursorFunc(18, 75);
		cout << "Publication frequency";
		moveCursorFunc(18, 100);
		cout << "Date";

		int* tempArr = new int[size]; // to store the first letter value
		node<T>* currentMat = head;

		int i = 0; // position
		while (i < size) // in order to store orderValues in array
		{
			tempArr[i] = currentMat->element.orderValue;
			currentMat = currentMat->next;
			i++;
		}
		bubbleSort(tempArr, size); // sorting min to max

		int j = 0;
		for (int j = 0; j < size; j++)
		{
			node<T>* printNode = head;
			for (int h = 0; h < size; h++)
			{
				if (printNode->element.orderValue == tempArr[j])
				{
					moveCursorFunc(19 + j, 5);
					cout << j + 1;
					moveCursorFunc(19 + j, 12);
					cout << printNode->element.Title;
					moveCursorFunc(19 + j, 35);
					cout << printNode->element.Type;
					moveCursorFunc(19 + j, 53);
					cout << printNode->element.Authors;
					moveCursorFunc(19 + j, 80);
					cout << printNode->element.frqcyofPublication;
					moveCursorFunc(19 + j, 97);
					cout << printNode->element.Date;
					break;
				}
				printNode = printNode->next;
			}
		}

	}

};