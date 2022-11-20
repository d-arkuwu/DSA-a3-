#pragma once
#include <iostream>
using namespace std;



template <class T>
class DList
{
private:
	class Node;
	Node* head;
	Node* tail;
public:
	class Iterator;
	~DList()
	{
		while (head->prev != NULL && tail->next != NULL)
		{
			Node* temp = tail->prev;
			temp->prev->next = tail;
			tail->prev = temp->prev;
			delete temp;
		}
	}
	DList()
	{
		head = new Node;
		tail = new Node;
		head->next = tail;
		tail->prev = head;
		head->prev = tail->next = 0;
	}
	void insertAtStart(T const value)
	{
		Node* temp = new Node;
		temp->data = value;
		temp->next = head->next;
		temp->prev = head;
		head->next->prev = temp;
		head->next = temp;
	}
	void insertAtEnd(T const value)
	{
		Node* temp = new Node;
		temp->data = value;
		temp->next = tail;
		temp->prev = tail->prev;
		tail->prev->next = temp;
		tail->prev = temp;
	}
	void print()
	{
		Node* ptr = head->next;
		while (ptr != tail)
		{
			cout << ptr->data << ' ';
			ptr = ptr->next;
		}
		cout << '\n';
	}
	void deleteAtStart()
	{
		Node* temp = head->next;
		head->next = temp->next;
		temp->next->prev = head;
		delete temp;
	}
	void deleteAtEnd()
	{
		if (head->next != tail) 
		{
			Node* temp = tail->prev;
			temp->prev->next = tail;
			tail->prev = temp->prev;
			delete temp;
		}
	}
	Iterator insertBefore(Iterator position, const T& value)
	{
		Node* temp = new Node;
		temp->data = value;
		Node* t = position.curr;
		temp->next = t;
		temp->prev = t->prev;
		temp->prev->next = temp;
		t->prev = temp;
		return position;
	}
	Iterator insertAfter(Iterator position, const T& value)
	{
		Node* temp = new Node;
		temp->data = value;
		Node* t = position.curr;
		temp->prev = t;
		temp->next = t->next;
		t->next->prev = temp;
		t->next = temp;
		return position;
	}
	Iterator erase(Iterator position)
	{
		Node* temp = position.curr;
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		Iterator it(temp->next);
		delete temp;
		return it;
	}
	Iterator search(T d)
	{
		for (Iterator it = begin(); it != end(); it++)
		{
			if (*it == d) 
			{
				return it;
			}
		}
		return 0;
	}
	Iterator begin()
	{
		Iterator it;
		it.curr = head->next;
		return it;
	}
	Iterator end()
	{
		Iterator it(tail);
		return tail;
	}

	void insertSorted(const T d)
	{
		auto it = end();
		it--;
		if (d > *(it))
		{
			insertAtEnd(d);
		}
		else if (d < *(begin()))
		{
			insertAtStart(d);
		}
		else
		{
			Node* curr = head->next;
			for (auto iter = begin(); iter != end(); iter++)
			{
				if ((curr->data < d) && (curr->next->data > d))
				{
					insertAfter(iter, d);
					break;
				}
				else
					curr = curr->next;
			}
		}

	}
	

};


template <class T>
class DList<T>::Node
{
public:
	Node* next;
	Node* prev;
	T data;

	Node()
	{
		prev = next = NULL;
	}
};

template <class T>
class DList<T>::Iterator
{
	friend class DList<T>;
private:
	Node* curr;
public:
	Iterator(Node* c = 0)
	{
		curr = c;
	}
	bool operator!=(const Iterator& itr)
	{
		if (this->curr != itr.curr) 
		{
			return true;
		}
		return false;
	}
	T& operator*()
	{
		return curr->data;
	}
	Iterator operator++(int)
	{
		Iterator old = *this;
		curr = curr->next;
		return old;
	}
	Iterator operator--(int)
	{
		Iterator old = *this;
		curr = curr->prev;
		return old;
	}
};