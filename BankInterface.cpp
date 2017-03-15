#include "stdafx.h"
#include "BankInterface.h"

/*
Karim Oumghar
CSS 342 - Lab 5 - March 13, 2015
*/
using namespace std;
BankInterface::BankInterface()
{
}
BankInterface::~BankInterface(void)
{
}
void BankInterface::ProcessTransaction(string &line)
{
	string fName, lName;
	int accountID, accountID2, assetID, assetID2, amount;
	vector<string> data;
	stringstream ss(line);
	string temp;
	
	while(ss >> temp)
	{
		data.push_back(temp);
	}
	if(data[0] == "O")
	{
		lName = data[1];
		fName = data[2];
		accountID = stoi(data[3]);
		Account *acc = new Account(lName, fName, accountID);
		
		tree.Insert(acc);
	}
	if(data[0] == "D")
	{
		Account *current = NULL;
		accountID = stoi(data[1]) / 10;
		assetID = stoi(data[1]) % 10;
		amount = stoi(data[2]);
		if(tree.Retrieve(accountID, current))
		{
			if(current->Deposit(assetID, amount))
			{
				current->AddTransaction(line);
			}
			else
			{
				current->AddTransaction("Error processing transaction: " + line);
			}
		}
	}
	if(data[0] == "W")
	{
		Account *current = NULL;
		accountID = stoi(data[1]) / 10;
		assetID = stoi(data[1]) % 10;
		amount = stoi(data[2]);
		if(tree.Retrieve(accountID, current))
		{
			if(current->Withdraw(assetID, amount))
			{
				current->AddTransaction(line);
			}
			else
			{
				current->AddTransaction("Error processing transaction: " + line);
			}
		}
	}
	if(data[0] == "T")
	{
		Account *current = NULL;
		Account *current2 = NULL;
		
		accountID = stoi(data[1]) / 10;
		assetID = stoi(data[1]) % 10;
		amount = stoi(data[2]);
		
		accountID2 = stoi(data[3]) / 10;
		assetID2 = stoi(data[3]) % 10;
		if(tree.Retrieve(accountID, current) && tree.Retrieve(accountID2, current2))
		{
			if(current->TransferFunds(assetID, amount, current2, assetID2))
			{
				current->AddTransaction(line);
			}
			else
			{
				cerr<<"Transfer unsucessful, no negative amounts, or amounts greater than the balance"<<endl;
				current->AddTransaction("Error processing transaction: " + line);
			}
		}
		else
		{
			cerr<<"Transfer unsucessful, account not found!"<<endl;
			current->AddTransaction("Error processing transaction: " + line);
		}
	}
	if(data[0] == "H")
	{
		Account *current = NULL;
		
		if(data[1].length() == 4)
		{
			accountID = stoi(data[1]);
			tree.Retrieve(accountID, current);
			current->PrintTransactions();
		}
		if(data[1].length() == 5)
		{
			accountID = stoi(data[1]) / 10;
			assetID = stoi(data[1]) % 10;
			tree.Retrieve(accountID, current);
			current->PrintAssetTransactionHistory(assetID);
		}
	}
}
void BankInterface::RecordTransaction(Account &ref, string line)
{
	ref.AddTransaction(line);
}
void BankInterface::PrintAll() const
{
	cout<<endl<<endl<<"All open accounts: "<<endl;
	tree.Display();
}