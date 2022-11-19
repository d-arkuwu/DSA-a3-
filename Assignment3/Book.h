#pragma once
#include <iostream>
using namespace std;
#include "Helper.h"

class Book
{
	int ISSN;
	char* title;
	char** authors;
	int refBookCount;
	int issueCount;

public:
	Book(int issn, char* t, char** authorList, int refB, int issuableB)
	{
		ISSN = issn;
		refBookCount = refB;
		issueCount = issuableB;
		Helper::stringCopy(title, t);
		int c= 0;
		while (authorList[c] != NULL)
			++c;
		authors = new char* [c+1];
		for (int i = 0; i < c; i++)
		{
			Helper::stringCopy(authors[i], authorList[i]);
		}
		authors[c] = NULL;
	}
	Book()
	{
		ISSN = 0;
		title = NULL;
		authors = NULL;
		refBookCount = 0;
		issueCount = 0;
	}
	friend std::ostream& operator<< (std::ostream& out, const Book& b)
	{
		cout << "Name of the book : " << b.title << endl << endl;
		cout << "ISSN of the book : " << b.ISSN << endl << endl;
		int i = 0;
		cout << "Authors of the book are:\n";
		while (b.authors[i] != NULL)
		{
			cout << "       " <<i+1 << ". "  << b.authors[i] << endl;
			i++;
		}
		cout << "\nNumber of copies available as reference books : " << b.refBookCount << endl<<endl;
		cout << "Number of copies available as issuable books : " << b.issueCount << endl<<endl;
		return out;
	}
	friend bool operator== (const Book& b1, const Book& b2)
	{
		if (b2.ISSN == b1.ISSN)
			return true;
		else
			return false;
	}
	friend bool operator< (const Book& b1, const Book& b2)
	{
		if (b1.ISSN < b2.ISSN)
			return true;
		else
			return false;
	}
	friend bool operator> (const Book& b1, const Book& b2)
	{
		if (b1.ISSN > b2.ISSN)
			return true;
		else
			return false;
	}
	void update()
	{
		char c;
		cout << "Do you wish to change the title of the book? (Y/N)";
		cin >> c;
		if (c == 'y' || c == 'Y')
		{
			cout << "Enter new title of the book : ";
			char* name = new char[100];
			cin.ignore();
			cin.getline(name, 100);
			Helper::stringCopy(title, name);
		}


		cout << "Do you wish to change the list of authors of the book? (Y/N)";
		cin >> c;
		if (c == 'y' || c == 'Y')
		{
			cout << "\nEnter number of new authors of the book : ";
			int num;
			cin >> num;

			authors = new char* [num + 1];
			for (int i = 0; i < num; i++)
			{
				cout << "\nEnter name of new author : ";
				char* temp = new char[100];
				cin.ignore();
				cin.getline(temp, 100);
				Helper::stringCopy(authors[i], temp);
			}
			authors[num] = NULL;
		}


		cout << "Do you wish to change the # of copies available as reference book of the book? (Y/N)";
		cin >> c;
		if (c == 'y' || c == 'Y')
		{
			cout << "\nEnter number of copies available as reference book : ";
			cin >> refBookCount;
		}


		cout << "Do you wish to change the # of copies available as issuable book of the book? (Y/N)";
		cin >> c;
		if (c == 'y' || c == 'Y')
		{
			cout << "\nEnter number of copies available as issuable book : ";
			cin >> issueCount;
		}

	}
	Book& operator= (const Book& b)
	{
		this->ISSN = b.ISSN;
		this->issueCount = b.issueCount;
		this->refBookCount = b.refBookCount;
		Helper::stringCopy(this->title, b.title);
		int c = 0;
		while (b.authors[c] != NULL)
			++c;
		this->authors = new char* [c + 1];
		for (int i = 0; i < c; i++)
		{
			Helper::stringCopy(this->authors[i], b.authors[i]);
		}
		authors[c] = NULL;

		return *this;
	}
};