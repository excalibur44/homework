#include <iostream>
#include <string>
using namespace std;

template <typename t> int myinput(int num)
{
	t *p, key;
	p = new t[num];
	//inout
	for(int i = 0; i < num; i++)
	{
		cin >> *(p+i);
	}
	//sort
	for(int i = 0; i < num; i++)
	{
		int min = i;t temp;
		for(int j = i; j < num; j++)
		{	
			if(*(p+j) < *(p+min) )
				min = j;
		}
		temp = *(p+min);
		*(p+min) = *(p+i);
		*(p+i) = temp;
	}
	//output
	for(int i = 0; i < num; i++)
	{
		cout << *(p+i) << " ";
	}
	return 0;
}

int main()
{
	int t; cin >> t;
	for(int i = 0; i < t; i++)
	{
		char c; int num;
		cin >> c >> num;
		if(c == 'I')
			num = myinput<int>(num);
		else if(c == 'D')
			num = myinput<double>(num);
		else if(c == 'C')
			num = myinput<char>(num);
		else if(c == 'S')
			num = myinput<string>(num);
		else;
		cout << endl;
	}
	return 0;
}