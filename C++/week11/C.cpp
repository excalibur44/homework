#include <iostream>
using namespace std;

class base
{
public:
	base(int number_, char type_, float balance_)
	{
		balance = balance_;
		rate = 0.005;
		number = number_;
		type = type_;
	}
	base(const base& c)
	{
		balance = c.balance;
		rate = 0.015;
		number = c.number + 50000000;
		type = c.type;
	}
	void count()
	{
		balance = balance*(1 + rate);
		cout << "Account=" << number
			 << "--sum=" << balance << endl;
	}
	void find()
	{
		cout << "Account=" << number ;
		if(type == 'P')
			cout << "--Person";
		else
			cout << "--Enterprise";
		cout << "--sum=" << balance
			 << "--rate=" << rate << endl;
	}
private:
	double balance;
	double rate;
	int number;
	char type;
};

void g_fun(base c){}

int main()
{
	int t; cin >> t;
	for(int i = 0; i < t; i++)
	{
		float balance_; int number_; char type_;
		cin >> number_ >> type_ >> balance_;
		base first(number_, type_, balance_);
		base second(first);
		char x; 

		cin >> x;
		if(x == 'C')
			first.count();
		else if(x == 'P')
			first.find();

		cin >> x;
		if(x == 'C')
			second.count();
		else if(x == 'P')
			second.find();
	}
	return 0;
}
