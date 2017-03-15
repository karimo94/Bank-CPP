// Bank.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include "BankInterface.h"
/*
Karim Oumghar
CSS 342 - Lab 5 - March 13, 2015
*/
using namespace std;

int main(int argc, char* argv[])
{
	ifstream read("BankTransIn.txt");
	string line;
	BankInterface BI;
	queue<string> items;
	while(getline(read, line))
	{
		items.push(line);
	}
	while(!items.empty())
	{
		BI.ProcessTransaction(items.front());
		items.pop();
	}
	BI.PrintAll();
	system("pause");
	return 0;
}
