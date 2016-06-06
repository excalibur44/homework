#include <iostream>
using namespace std;

template <class mytype>
class matrix
{
public:
	matrix(int m, int n) : mm(m), nn(n)
	{
		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++)
			{
				cin >> copy[i][j];
			}
	}
	void transport()
	{
		for(int i = 0; i < mm; i++)
			for(int j = 0; j < nn; j++)
				x[j][i] = copy[i][j];
	}
	void print()
	{
		for(int i = 0; i < nn; i++)
		{
			for(int j = 0; j < mm; j++)
			{
				cout << x[i][j];
				if(j + 1 != mm)
					cout << " ";
			}
			cout << endl;
		}
	}
private:
	mytype x[10][10];
	mytype copy[10][10];
	int mm, nn;
};



int main()
{
	int t; cin >> t; char x; int m, n;
	for(int i = 0; i < t; i++)
	{
		cin >> x >> m >> n;
		if(x == 'I')
		{
			matrix<int> obj(m, n);
			obj.transport();
			obj.print();
		}
		else if(x == 'D')
		{
			matrix<double> obj(m, n);
			obj.transport();
			obj.print();
		}
		else if(x == 'C')
		{
			matrix<char> obj(m, n);
			obj.transport();
			obj.print();
		}
	}
	return 0;
}