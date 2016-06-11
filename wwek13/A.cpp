#include <iostream>
using namespace std;

class fu
{
private:
	int real;
	int image;
public:
	fu(int r, int i):real(r),image(i){}
	fu operator + (const fu &c){ return fu(real + c.real, image + c.image); }
	fu operator - (const fu &c){ return fu(real - c.real, image - c.image); }
	void print()
	{
		if(real != 0 )
			cout << real;
		if(image > 0)
			cout << "+";
		if(image != 0)
			if(image == -1)
				cout << "-i";
			else
				cout << image << "i";
		cout << endl;
	}
};

int main()
{
	int t; cin >> t;
	for(int j = 0; j < t; j++)
	{
		int r,i;
		cin >> r >> i; fu first(r,i);
		cin >> r >> i; fu second(r,i);
		fu third = first+second;
		fu fourth = first-second;
		third.print(); fourth.print();
	}
	return 0;
}