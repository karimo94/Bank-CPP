#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
/*
Karim Oumghar
CSS 342 - Lab 5 - March 13, 2015
*/
using namespace std;
class Account
{
public:
	Account();
	~Account(void);
	Account(string lName, string fName, int id);
	int getId() const;
	bool TransferFunds(int &assetID1, int amount, Account * &ref, int &assetID2);
	bool Withdraw(int &fundID, int amount);
	bool Deposit(int &findID, int amount);
	void AddTransaction(string line);
	void PrintTransactions() const;
	void PrintAssetTransactionHistory(int &asset) const;
	void PrintFinalBalances() const;
private:
	class Funds
	{
	private:
		vector<int> accountAssets;
	public:
		Funds()
		{
			for(int i = 0; i <= 9; i++)
			{
				accountAssets.push_back(0);
			}
		}
		~Funds(void)
		{}
		int getAmount(const int &ref) const
		{
			return accountAssets[ref];
		}
		void updateAmount(const int &ref, int amount)
		{
			accountAssets[ref] += amount;
		}
	};
private:
	string firstName, lastName;
	int idNumber;
	Funds *assets;
	vector<string> transactions;
	void CheckMoneyMarketBonds(int &assetRef, int amount) const;
	void CheckBondFunds(int &assetRef, int amount) const;
};

