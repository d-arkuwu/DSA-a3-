#pragma once
#include "DList.h"
#include "Book.h"


class BookRef
{
	int ISSN;
	DList<Book>::Iterator nodeInList;

public:
	BookRef(int issn, DList<Book>::Iterator it)
	{
		ISSN = issn;
		nodeInList = it;
	}
	BookRef()
	{
		ISSN = 0;
		nodeInList = NULL;
	}
	friend bool operator== (const BookRef& b1, const BookRef& b2)
	{
		if (b1.ISSN == b2.ISSN)
			return true;
		else
			return false;
	}
	friend bool operator< (const BookRef& b1, const BookRef& b2)
	{
		if (b1.ISSN < b2.ISSN)
			return true;
		else
			return false;
	}
	friend bool operator> (const BookRef& b1, const BookRef& b2)
	{
		if (b1.ISSN > b2.ISSN)
			return true;
		else
			return false;
	}
	int getISSN()
	{
		return ISSN;
	}
	auto getNodeInList()
	{
		return nodeInList;
	}
	void updateBook()
	{

	}
};



