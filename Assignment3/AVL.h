#pragma once
#pragma once
#include <iostream>
#include "Book.h"
using namespace std;
template <class T>
class AVL
{
	class ANode
	{
	public:
		T data;
		ANode* left;
		ANode* right;
		int height;
		ANode()
		{
			left = right = 0;
		}
		ANode(T d, ANode* l, ANode* r, int h)
		{
			data = d;
			left = l;
			right = r;
			height = h;
		}
	};

	ANode* root;
public:
	AVL()
	{
		root = 0;
	}
	int getHeight(ANode* r)
	{
		if (!r)
		{
			return -1;
		}
		return r->height;
	}
	int max(int a, int b)
	{
		if (a > b)
			return a;
		return b;
	}
	int balanceFactor(ANode* r)
	{
		return getHeight(r->left) - getHeight(r->right);
	}
	void rotateLeft(ANode*& x)
	{
		ANode* y = x->right;
		x->right = y->left;
		y->left = x;
		x->height = 1 + max(getHeight(x->left), getHeight(x->right));
		y->height = 1 + max(x->height, getHeight(y->right));
		x = y;
	}
	void doubleRotateLeft(ANode*& x)
	{
		rotateRight(x->right);
		rotateLeft(x);
	}
	void rotateRight(ANode*& x)
	{
		ANode* y = x->left;
		x->left = y->right;
		y->right = x;
		x->height = 1 + max(getHeight(x->left), getHeight(x->right));
		y->height = 1 + max(x->height, getHeight(y->right));
		x = y;
	}
	void doubleRotateRight(ANode*& x)
	{
		rotateLeft(x->left);
		rotateRight(x);
	}
	bool search(T val)
	{
		return search(val, root);
	}
	auto search(T val, ANode* r)
	{
		if (r)
		{
			if (r->data == val)
				return r;
			else if (r->data > val)
				return search(val, r->left);
			else if (r->data < val)
				return search(val, r->right);
		}
		return false;
	}
	void insert(T d)
	{
		insert(root, d);
	}
	void insert(ANode*& r, T d)
	{
		if (!r)
		{
			r = new ANode(d, 0, 0, 0);
		}
		else {
			if (d < r->data)
			{
				insert(r->left, d);
				if (balanceFactor(r) == 2 || balanceFactor(r) == -2)
				{
					if (d < r->left->data)
					{
						rotateRight(r);
					}
					else {
						doubleRotateRight(r);
					}
				}
			}
			else if (d > r->data)
			{
				insert(r->right, d);
				if (balanceFactor(r) == 2 || balanceFactor(r) == -2)
				{
					if (d > r->right->data)
					{
						rotateLeft(r);
					}
					else
					{
						doubleRotateLeft(r);
					}
				}
			}
			r->height = 1 + max(getHeight(r->left), getHeight(r->right));
		}
	}
	T findMin()
	{
		return findMin(root);
	}
	T findMin(ANode* r)
	{
		static int min = r->data;
		if (r->left)
		{
			min = findMin(r->left);
		}
		return min;
	}
	void inorderPrint()
	{
		inorderPrint(root);
	}
	void inorderPrint(ANode* r)
	{
		if (r)
		{
			inorderPrint(r->left);
			cout << r->data << ' ';
			inorderPrint(r->right);
		}
	}
	auto search(int val, ANode* r)
	{
		if (r)
		{
			if (r->data.getISSN() == val)
				return r->data.getNodeInList();
			else if (r->data.getISSN() > val)
				return search(val, r->left); 
			else if (r->data.getISSN() < val)
				return search(val, r->right);
		}

	}
	auto search(int val)
	{
		return search(val, root);
	}
	Book& searchBook(int val, ANode* r)
	{
		if (r)
		{
			if (r->data.getISSN() == val)
				return *(r->data.getNodeInList());
			else if (r->data.getISSN() > val)
				return searchBook(val, r->left);
			else if (r->data.getISSN() < val)
				return searchBook(val, r->right);
		}
		
	}
	Book& searchBook(int issn)
	{
		return searchBook(issn, root);
	}
};
