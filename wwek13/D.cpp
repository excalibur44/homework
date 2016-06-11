#include <iostream>
using namespace std;

class stack
{
private:
	int m, n, **data;
public:
	stack(){}
	stack(int mm, int nn, int **data_):m(mm),n(nn),data(data_){}
	stack operator - (stack &c)
	{
		int **data1;
		data1 = new int*[m];  //先创建m行
		for(int i = 0; i < m; i++) 
			{ data1[i] = new int[n]; }  //再创建n列

		stack temp(m, n, data1);
		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++)
				temp.data[i][j] = data[i][j] + c.data[i][j];
		return temp;
	}
	void show()
	{
		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < n; j++)
			{
				cout << *(*(data+i)+j);
				if(j+1 < n)
					cout << " ";
			}
			cout << endl;
		}
	}
};

int main()
{
	int t; cin >> t;
	for(int x = 0; x < t; x++)
	{
		int mm, nn; int **data;
		cin >> mm >> nn;
		data = new int*[mm];  //先创建m行
		for(int i = 0; i < mm; i++) //再创建n列
		{ 
			data[i] = new int[nn]; 
		}  
		for (int i = 0; i < mm; i++)
			for (int j = 0; j < nn; j++)
				cin >> data[i][j];

		stack first(mm, nn, data);
		int **data_;
		data_ = new int*[mm];  //先创建m行
		for(int i = 0; i < mm; i++) 
			{ data_[i] = new int[nn]; }  //再创建n列
		for (int i = 0; i < mm; i++)
			for (int j = 0; j < nn; j++)
				cin >> data_[i][j];
		stack second(mm, nn, data_);

		int **data1;
		data1 = new int*[mm];  //先创建m行
		for(int i = 0; i < mm; i++) 
			{ data1[i] = new int[nn]; }  //再创建n列
		stack third(mm, nn, data1);

		third = first - second;
		third.show();
	}
	return 0;
}