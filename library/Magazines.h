#pragma once
#include <iostream>

using namespace std;

class Magazine
{
public:
	string Title;
	string Authors;
	string Date;
	string frqcyofPublication;
	string Type;
	int orderValue;

public:
	Magazine()
	{
		Title = "test1";
		Authors = "None";
		Date = "None";
		frqcyofPublication = "None";
		Type = "None";
	}

	Magazine(string Tt, string Auth, string Dt, string fropb, string type)
	{
		Title = Tt;
		Authors = Auth;
		Date = Dt;
		frqcyofPublication = fropb;
		Type = type;
		orderValue = 0;
		int sumValue = 0;

		//alphabetical order value calculation
		for (int i = 0; i < 5; i++)
		{
			int val = pow(10, 2 * (3 - i));
			if (int(Tt[i]) < 65 || int(Tt[i]) > 122)
			{
				continue;
			}
			else if (Tt[i] < 91)
			{
				int value1 = int(Tt[i]) - 64;
				sumValue = sumValue + value1 * val;
			}
			else
			{
				int value2 = int(Tt[i]) - 96;
				sumValue = sumValue + value2 * val;
			}
		}
		orderValue = sumValue;
	}

	void displayMagazines()
	{
		cout << "\n\t\t\t\t\tTile of the book\t: " << Title << endl;
		cout << "\t\t\t\t\tAuthor\t\t\t: " << Authors << endl;
		cout << "\t\t\t\t\tType  \t\t\t: " << Type << endl;
		cout << "\t\t\t\t\tFrequancy of Publication: " << frqcyofPublication << endl;
		cout << "\t\t\t\t\tPublished Date  \t: " << Date << endl;

	}
};

