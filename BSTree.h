#pragma once
#include "Account.h"
#include <iostream>
#include <string>

/*
Karim Oumghar
CSS 342 - Lab 5 - March 13, 2015
*/
using namespace std;
class BSTree
{
private:
	struct Node
	{
		Account *pAcct;
		Node *right;
		Node *left;
	};
public:
	BSTree(void);
	~BSTree(void);
	bool Insert(Account *acc);
	void Display() const;
	void Empty();
	bool isEmpty() const;
	bool Retrieve(const int &ref, Account * &acc);
private:
	Node *root;
	int numberOfAccounts;
	void InOrderDisplay(Node *acc) const;
	void RecursiveEmpty(Node *acc);
};

