#include "AVL.h"
#include "DList.h"
#include "Library.h";


int main()
{
	Library lib;
	lib.run();
	/*bool flag = true;
	while (flag)
	{
		cout << "Enter name of the book\n";
		char* name = new char[100];
		cin.ignore();
		cin.getline(name, 100);

		cout << "Enter the ISSN number of the book";
		int issn;
		cin >> issn;

		cout << "Enter number of authors of the book";
		int num;
		cin >> num;

		char** authors = new char* [num+1];
		for (int i = 0; i < num; i++)
		{
			cout << "Enter name of author";
			char* temp = new char[100];
			cin.ignore();
			cin.getline(temp, 100);
			Helper::stringCopy(authors[i], temp);
		}
		authors[num] = NULL;

		cout << "Enter number of copies available as reference book";
		int n1;
		cin >> n1;

		cout << "Enter number of copies available as issuable book";
		int n2;
		cin >> n2;

		lib.addBook(issn, name, authors, n1, n2);
		

		cout << "enter 1 to exit 0 to continue\n";
		int f;
		cin >> f;
		if (f == 1)
			flag = false;

	}
	lib.printBooks();
	cout << endl << endl;
	lib.review(20);
	lib.update(20);
	lib.printBooks();*/

}