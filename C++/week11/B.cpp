#include <iostream>
#include <string>
using namespace std;

class base
{
public:
	base(int q1, char w2, int e3, string r4)
	{
		number = q1;
		type = w2;
		status = e3;
		name = r4;
		cout << number << " constructed." << endl;
	}
	~base(){	cout << number << " destructed." << endl;	}
	int lookfor(int check);
	void print()
	{
		cout << "Phone=" << number
			 << "--Type=" << type;
		if(status == 1)
			cout << "--State=use--Owner=";
		else
			cout << "--State=unuse--Owner=";
		cout << name << endl;
	}
private:
	int number;
	char type;
	int status;
	string name;
};

int base::lookfor(int check)
{
	if(check == number)
		return 1;
	else
		return 0;
}

int main()
{
	{
		int q1; char w2; int e3; string r4;
		cin >> q1 >> w2 >> e3 >> r4;	base first(q1, w2, e3, r4);
		cin >> q1 >> w2 >> e3 >> r4;	base second(q1, w2, e3, r4);
		cin >> q1 >> w2 >> e3 >> r4;	base third(q1, w2, e3, r4);
	
		int t; cin >> t;
		for(int i = 0; i < t; i++)
		{
			int check; cin >> check;
			if(first.lookfor(check))
				first.print();
			else if(second.lookfor(check))
				second.print();
			else if(third.lookfor(check))
				third.print();
			else
				cout << "wrong number." << endl;
		}
	}
	return 0;
}
