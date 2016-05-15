#include <iostream>
#include <string>
using namespace std;

class base
{
public:
	base(string one, char two, int three)
	{	
		myname = one; leixing = two; dengji = three;
		if(two == 'N')
		{
			blood = dengji*5;
			shanghai = dengji*5;
			fangyu = dengji*5;
		}
		else if(two == 'A')
		{
			blood = dengji*5;
			shanghai = dengji*10;
			fangyu = dengji*5;
		}
		else if(two == 'D')
		{
			blood = dengji*5;
			shanghai = dengji*5;
			fangyu = dengji*10;
		}
		else if(two == 'H')
		{
			blood = dengji*50;
			shanghai = dengji*5;
			fangyu = dengji*5;
		}
	}
	void bianshen(char two);
	void print()
	{
		cout << myname << "--"
			 << leixing << "--"
			 << dengji << "--"
			 << blood << "--"
			 << shanghai << "--"
			 << fangyu << endl;
	}
	char getleixing(){ return leixing; }
private:
	string myname;
	int blood;
	int shanghai;
	int fangyu;
	char leixing;
	int dengji;
};

void base::bianshen(char two)
{
	if(two == 'N')
	{
		leixing = two;
		blood = dengji*5;
		shanghai = dengji*5;
		fangyu = dengji*5;
	}
	else if(two == 'A')
	{
		leixing = two;
		blood = dengji*5;
		shanghai = dengji*10;
		fangyu = dengji*5;
	}
	else if(two == 'D')
	{
		leixing = two;
		blood = dengji*5;
		shanghai = dengji*5;
		fangyu = dengji*10;
	}
	else if(two == 'H')
	{
		leixing = two;
		blood = dengji*50;
		shanghai = dengji*5;
		fangyu = dengji*5;
	}
}

bool trans(base *p, char leixing2)
{
	if(p->getleixing() != leixing2)
	{
		p->bianshen(leixing2);
		return true;
	}
	else
		return false;
}


int main()
{
	int t; cin >> t; int n = 0;
	for(int i = 0; i < t; i++)
	{
		string myname; char leixing1, leixing2; int dengji;
		std::cin >> myname >> leixing1 >> dengji >> leixing2;
		base jiqiren(myname, leixing1, dengji);
		bool b = trans(&jiqiren, leixing2);
		if(b == true)	n++;
		jiqiren.print();
	}
	cout << "The number of robot transform is " << n << endl;
	return 0;
}
