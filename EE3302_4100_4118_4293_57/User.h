#pragma once
#include <iostream>
//#include "UserList.h"
//#include "singly_linked_list.h"
#include "stack_array.h"

using namespace std;

class User
{
public:
	string userName;
	string password;
	//int cleareance;
	string idNum;
	
	//need to add download lists
	stack_array* UserDownloads;

public:
	User()
	{
		userName = "empty";
		password = "empty";
		UserDownloads = new stack_array(100);
	}

	User(string UsNm, string pw)
	{
		userName = UsNm;
		password = pw;
		UserDownloads = new stack_array(100);
	}

	//test method assign ID
	/*void assignID(string UsNm,singly_linked_list<User> allUsers)
	{
		node<User>* current = allUsers.getHead();

		for (int i = 0; i < allUsers.getSize(); i++)
		{
			User currentUser = current->element;
			
			if (currentUser.userName == UsNm)
			{
				
			}
		}
	}*/

	void addDownloads(downMat Matname) // for add materials to download stack
	{
		UserDownloads->push(Matname);
	}
};

