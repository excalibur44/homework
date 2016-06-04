#include <iostream>
#include <string>
using namespace std;

template <typename t> int myinput(int num)
{
	t *p, key;
	p = new t[num];
	for(int i = 0; i < num; i++)
	{
		cin >> *(p+i);
	}
	cin >> key;
	for(int i = 0; i < num; i++)
	{
		if(*(p+i) == key)
			return i+1;
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
		cout << num << endl;
	}
	return 0;
}