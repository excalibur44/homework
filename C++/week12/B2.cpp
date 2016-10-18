#include<iostream>
#include<string>
using namespace std;

class BaseAccount
{
protected:
	string name;
	string account;
	int balance;
public:
	BaseAccount(){}
	BaseAccount(string name_, string account_, int balance_)
	{
		name = name_;
		account = account_;
		balance = balance_;

	}
	virtual void deposit(int money)
	{
		balance += money;
	}
	virtual void withdraw(int money)
	{
		if(balance - money >= 0)
			balance -= money;
		else
			cout << "insufficient" << endl;
	}
	virtual void display()
	{
		cout << name << " " << account << " Balance:" << balance << endl;
	}
};

class BasePlus : public BaseAccount
{
private:
	int limit;
	int limit_sum;
public:
	BasePlus(string name_,string account_,int balance_) : BaseAccount(name_,account_,balance_)
	{
		limit = 5000;
		limit_sum = 0;
	}
	virtual void deposit(int dep)
	{
		balance += dep;
	}
	virtual void withdraw(int with)
	{
		if(with <= balance)
			balance -= with;
		else if(with > balance && with <= (balance + limit - limit_sum))
		{
			limit_sum = limit_sum + with - balance;	
			balance = 0;
		}
		else 
			cout << "insufficient" << endl;
	}
	virtual void display()
	{
		cout << name << " " << account << " Balance:" << balance << " limit:" << limit-limit_sum << endl;
	}
};

int main()
{
	string name_; string account_; int balance_; int a1,b1,a2,b2;
	BaseAccount *p = NULL;
	int t; cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> name_ >> account_ >> balance_ ;
		cin >> a1 >> b1 >> a2 >> b2;
		if(account_[1] == 'A')
		{	
			BaseAccount A(name_, account_, balance_);
			p = &A;
			p->deposit(a1);
			p->withdraw(b1);
			p->deposit(a2);
			p->withdraw(b2);
			p->display();
		}
		else if(account_[1] == 'P')
		{	

			BasePlus B(name_, account_, balance_);
			p = &B;
			p->deposit(a1);
			p->withdraw(b1);
			p->deposit(a2);
			p->withdraw(b2);
			p->display();
		}
	}
	return 0;
}
