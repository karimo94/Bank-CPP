#include "stdafx.h"
#include "BSTree.h"

/*
Karim Oumghar
CSS 342 - Lab 5 - March 13, 2015
*/
using namespace std;

BSTree::BSTree()
{
	root = NULL;
	numberOfAccounts = 0;
}

bool BSTree::isEmpty() const
{
	if(root == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool BSTree::Insert(Account *acc)
{
	Node *newClient = new Node();
	newClient->pAcct = acc;
	bool isInserted = false;
	if(root == NULL)
	{
		root = newClient;
		isInserted = true;
		numberOfAccounts++;
	}
	else
	{
		Node *cur = root;
		Node *parent = NULL;
		while(cur != NULL)
		{
			parent = cur;
			if(newClient->pAcct->getId() < cur->pAcct->getId())
			{
				cur = cur->left;
				if(cur == NULL)
				{
					parent->left = newClient;
					isInserted = true;
					numberOfAccounts++;
				}
			}
			else
			{
				cur = cur->right;
				if(cur == NULL)
				{
					parent->right = newClient;
					isInserted = true;
					numberOfAccounts++;
				}
			}
		}
	}
	return isInserted;
}
bool BSTree::Retrieve(const int &ref, Account *&acc)
{
	Node *current = root;
	bool isFound = false;
	while (current != NULL && isFound == false)
	{
		if(ref == current->pAcct->getId())
		{
			acc = current->pAcct;
			isFound = true;
		}
		if(ref < current->pAcct->getId())
		{
			current = current->left;
		}
		if(ref > current->pAcct->getId())
		{
			current = current->right;
		}
	}
	return isFound;
}
void BSTree::Empty() 
{
	RecursiveEmpty(root);
}
void BSTree::RecursiveEmpty(Node *current)
{
	if(current == NULL)
	{
		return;
	}
	if(current != NULL)
	{
		RecursiveEmpty(current->left);
		RecursiveEmpty(current->right);
		delete current;
	}
	numberOfAccounts = 0;
}
void BSTree::Display() const
{
	InOrderDisplay(root);
}
void BSTree::InOrderDisplay(Node *current) const
{
	if(current != NULL)
	{
		InOrderDisplay(current->left);
		InOrderDisplay(current->right);
		current->pAcct->PrintFinalBalances();
	}
}
BSTree::~BSTree(void)
{
}
