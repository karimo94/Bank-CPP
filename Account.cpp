#include "stdafx.h"
#include "Account.h"
/*
Karim Oumghar
CSS 342 - Lab 5 - March 13, 2015
*/

Account::Account(void)
{
}
Account::Account(string lName, string fName, int id)
{
	lastName = lName;
	firstName = fName;
	idNumber = id;
	assets = new Funds();
}
int Account::getId() const
{
	return idNumber;
}
bool Account::Deposit(int &refID, int amount)
{
	if((refID >= 0 && refID <= 9) && (amount >= 0))
	{
		assets->updateAmount(refID, amount);
		return true;
	}
	else
	{
		cerr<<"Cannot deposit negative amount!"<<endl;
		return false;
	}
}
bool Account::Withdraw(int &fundID, int amount)
{
	if(fundID >= 0 && fundID <= 9 && amount <= assets->getAmount(fundID) && (amount >= 0))
	{
		amount = 0 - amount;
		assets->updateAmount(fundID, amount);
		return true;
	}
	else
	{
		cerr<<"Cannot withdraw negative amount, or amount greater than the account balance!"<<endl;
		return false;
	}
}
bool Account::TransferFunds(int &assetID1, int amount, Account * &ref, int &assetID2)
{   
	if(assetID1 == 0 || assetID1 == 1)
	{
		CheckMoneyMarketBonds(assetID1, amount);
	}
	if(assetID1 == 2 || assetID2 == 3)
	{
		CheckBondFunds(assetID1, amount);
	}
	if((assetID1 >= 0 && assetID1 <= 9) && (assetID2 >= 0 && assetID2 <= 9) && ((assetID1 != assetID2 && idNumber == ref->getId()) || (assetID1 == assetID2 && idNumber != ref->getId()) || (assetID1 != assetID2 && idNumber != ref->getId())) && (amount <= assets->getAmount(assetID1)) && (amount >= 0))
	{
		int removeAmountFromAsset = 0 - amount;
		assets->updateAmount(assetID1, removeAmountFromAsset);
		assets->updateAmount(assetID2, amount);
		return true;
	}
	else
	{   
		cerr<<"No negative amounts, amounts greater than account balance, and no transfer between the same account asset!"<<endl;
		return false;
	}
}
void Account::AddTransaction(string line)
{
	transactions.push_back(line);
}
void Account::PrintTransactions() const
{
	cout<<endl;
	cout<<"Transaction History for "<<firstName<<" "<<lastName<<":"<<endl;
	for(int i = transactions.size() - 1; i >= 0; i--)
	{
		cout<<transactions[i]<<endl;
	}
}
void Account::PrintAssetTransactionHistory(int &asset) const
{
	cout<<endl;
	string data, assetDesc;
	if(asset == 0)
	{
		assetDesc = "Money Market";
	}
	if(asset == 1)
	{
		assetDesc = "Prime Money Market";
	}
	if(asset == 2)
	{
		assetDesc = "Long term bond";
	}
	if(asset == 3)
	{
		assetDesc = "Short term bond";
	}
	if(asset == 4)
	{
		assetDesc = "500 Index fund";
	}
	if(asset == 5)
	{
		assetDesc = "Capital Value fund";
	}
	if(asset == 6)
	{
		assetDesc = "Growth Equity fund";
	}
	if(asset == 7)
	{
		assetDesc = "Growth Index fund";
	}
	if(asset == 8)
	{
		assetDesc = "Value fund";
	}
	if(asset == 9)
	{
		assetDesc = "Value Stock Index";
	}
	vector<string> temp;
	
	cout<<"Transaction history for "<<firstName<<" "<<lastName<<" "<<assetDesc<<":"<<endl;
	for(int i = transactions.size() - 1; i >= 0; i--)
	{
		stringstream ss(transactions[i]);
		temp.clear();
		while(ss >> data)
		{
			temp.push_back(data);
		}
		if(stoi(temp[1]) % 10 == asset)
		{
			cout<<transactions[i]<<endl;
		}
	}
	cout<<"Balance for "<<assetDesc<<": "<<assets->getAmount(asset)<<endl;
}
void Account::PrintFinalBalances() const
{
	cout<<endl;
	cout<<"Final balances for "<<firstName<<" "<<lastName<<":"<<endl;
	cout<<"Money Market: $"<<assets->getAmount(0)<<endl;
	cout<<"Prime Money Market: $"<<assets->getAmount(1)<<endl;
	cout<<"Long Term Bond: $"<<assets->getAmount(2)<<endl;
	cout<<"Short Term: $"<<assets->getAmount(3)<<endl;
	cout<<"500 Index fund: $"<<assets->getAmount(4)<<endl;
	cout<<"Capital Value Fund: $"<<assets->getAmount(5)<<endl;
	cout<<"Growth Equity fund: $"<<assets->getAmount(6)<<endl;
	cout<<"Growth Index fund: $"<<assets->getAmount(7)<<endl;
	cout<<"Value fund: $"<<assets->getAmount(8)<<endl;
	cout<<"Value Stock Index: $"<<assets->getAmount(9)<<endl;
}
void Account::CheckMoneyMarketBonds(int &ref, int amount) const
{
	if(assets->getAmount(0) > 0 && assets->getAmount(1) > 0)
	{
		return;
	}
	if(assets->getAmount(0) == 0 && assets->getAmount(1) > 0 && assets->getAmount(1) >= amount)
	{
		ref = 1;
	}
	if(assets->getAmount(1) == 0 && assets->getAmount(0) > 0 && assets->getAmount(0) >= amount)
	{
		ref = 0;
	}
}
void Account::CheckBondFunds(int &ref, int amount) const
{
	if(assets->getAmount(2) > 0 && assets->getAmount(3) > 0)
	{
		return;
	}
	if(assets->getAmount(2) == 0 && assets->getAmount(3) > 0 && assets->getAmount(3) >= amount)
	{
		ref = 3;
	}
	else if(assets->getAmount(3) == 0 && assets->getAmount(2) > 0 && assets->getAmount(2) >= amount)
	{
		ref = 2;
	}
}
Account::~Account(void)
{
}
