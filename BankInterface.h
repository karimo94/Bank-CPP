#pragma once
#include <queue>
#include <string>
#include <iostream>
#include <sstream>
#include "BSTree.h"

/*
Karim Oumghar
CSS 342 - Lab 5 - March 13, 2015
*/
using namespace std;
class BankInterface
{
public:
	BankInterface(void);
	~BankInterface(void);
	void ProcessTransaction(string &line);
	void RecordTransaction(Account &ref, string line);
	void PrintAll()const;
private:
	queue<string>transactionQueue;
	BSTree tree;
};

