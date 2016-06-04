#include <iostream>
#include <string>
using namespace std;

template <typename t> int myinput(int num)
{
	t *p, key;
	p = new t[num];
	//input
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
	//入桶
	t *sump = new t[num]; int same = 0;
	int *sum = new int[num]; *sump = *p;
	for(int i = 0; i < num; i++){ *(sum+i) = 0; }
	for(int i = 0; i < num; i++)
	{
		if(*(sump+same) != *(p+i) )
		{
			same++;
			*(sump+same) = *(p+i);
		}
		*(sum+same) += 1;
	}
	//find the max num
	int max = *sum; int j = 0;
	for(int i = 0; i < same+1; i++)
	{
		if(*(sum+i) > max)
		{
			max = *(sum+i);
			j = i;
		}
	}
	//output
	cout << *(sump+j) << " " << *(sum+j);
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
		//else if(c == 'D')
			//num = myinput<double>(num);
		else if(c == 'C')
			num = myinput<char>(num);
		else if(c == 'S')
			num = myinput<string>(num);
		else;
		cout << endl;
	}
	return 0;
}