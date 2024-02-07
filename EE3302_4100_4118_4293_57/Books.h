#pragma once
#include <iostream>
#include<math.h>

using namespace std;
class Book
{
public:
	string Title;
	string Author;
	string pubYear;
	int Pages;
	string Type;
	int orderValue;//use for sort to a alphabetical order

public:
	Book()
	{
		Title = "test1";
		Author = "None";
		pubYear = "None";
		Pages = 0;
		Type = "None";
	}

	Book(string Tt, string Auth, string year, int pages, string type)
	{
		Title = Tt;
		Author = Auth;
		pubYear = year;
		Pages = pages;
		Type = type;
		orderValue = 0;
		int sumValue = 0;

		//alphabetical order value calculation
		for (int i = 0; i < 5; i++)
		{
			int val = pow(10,2*(3-i));
			if (int(Tt[i]) < 65 || int(Tt[i]) > 122)
			{
				continue;
			}
			else if (Tt[i] < 91 )
			{
				int value1 = int(Tt[i]) - 64;
				sumValue = sumValue + value1*val;
			}
			else
			{
				int value2 = int(Tt[i]) - 96;
				sumValue = sumValue + value2*val;
			}
		}
		orderValue = sumValue;

	}

	void displayBook()
	{
		cout << "\n\t\t\t\tTile of the book: " << Title << endl;
		cout << "\t\t\t\tAuthor\t\t: " << Author << endl;
		cout << "\t\t\t\tType\t\t: " << Type << endl;
		cout << "\t\t\t\tPages\t\t: " << Pages << endl;
		cout << "\t\t\t\tPublished Year\t: " << pubYear << endl;

	}
};

