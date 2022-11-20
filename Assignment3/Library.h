#pragma once
#include "AVL.h"
#include "Book.h"
#include "BookRef.h"
#include "DList.h";

class Library
{
	AVL<BookRef> bookRefs;
	DList<Book> allBooks;

public:
	~Library()
	{
		bookRefs.~AVL();
		allBooks.~DList();
	}
	void addBook(int issn, char* title, char** authors, int refB, int issuableB)
	{
		Book* b = new Book{ issn, title, authors, refB, issuableB };
		allBooks.insertSorted(*b);
		auto bookIt = allBooks.search(*b);
		bookRefs.insert(BookRef{issn, bookIt});
	} 
	void printBooks()
	{
		allBooks.print();
	}
	
	void update(int issn)
	{
		bookRefs.searchBook(issn).update();
	}
	void run()
	{
		bool flag = true;
		while (flag)
		{
			cout << "Library DataBase\n" << endl;
			int c;
			cout << "1. Create a book record\n";
			cout << "2. Review a book record\n";
			cout << "3. Update a book record\n";
			cout << "4. Delete a book record\n";
			cout << "\nChoose desired operation : "; cin >> c;
			switch (c)
			{
			case 1:
			{
				createBook();
				break;
			}
			case 2:
			{
				reviewBook();
				break;
			}
			case 3:
			{
				updateBook();
				break;
			}
			default:
				flag = false;
				break;
			}
		}

	}
	void createBook()
	{
		system("cls");
		cout << "Enter title of the book : ";
		char* name = new char[100];
		cin.ignore();
		cin.getline(name, 100);

		cout << "\nEnter the ISSN number of the book : ";
		int issn;
		cin >> issn;

		cout << "\nEnter number of authors of the book : ";
		int num;
		cin >> num;

		char** authors = new char* [num + 1];
		for (int i = 0; i < num; i++)
		{
			cout << "\nEnter name of author : ";
			char* temp = new char[100];
			cin.ignore();
			cin.getline(temp, 100);
			Helper::stringCopy(authors[i], temp);
		}
		authors[num] = NULL;

		cout << "\nEnter number of copies available as reference book : ";
		int n1;
		cin >> n1;

		cout << "\nEnter number of copies available as issuable book : ";
		int n2;
		cin >> n2;

		addBook(issn, name, authors, n1, n2);
	}
	void reviewBook()
	{
		system("cls");
		int c;
		cout << "Enter the ISSN number of the book you wish to view the record of : "; cin >> c;
		system("cls");
		review(c);
	}
	void review(int issn)
	{
		DList<Book>::Iterator book = bookRefs.search(issn);
		cout << *(book);

	}
	void updateBook()
	{
		system("cls");
		int c;
		cout << "Enter the ISSN of the book to modify records "; cin >> c;
		update(c);
	}
};