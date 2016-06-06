#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class Shape
{
public:
	virtual void Area(){}
	Shape(double r=0, double ll=0, double xx=0, double yy=0)
	{
		R = r;
		l = ll;
		x = xx;
		y = yy;
	}
protected:
	double R;
	double l;
	double x;
	double y;
};

class Circle : public Shape
{
public:
	Circle(double r) : R(r){}
	virtual void Area()
	{
		cout << fixed << setprecision(2) << 3.14*R*R << endl;
	}
};

class Square : public Shape
{
public:
	Square(double ll) : Shape(0, ll){}
	virtual void Area()
	{
		cout << fixed << setprecision(2) << l*l << endl;
	}
};

class Rectangle : public Shape
{
public:
	Rectangle(double xx, double yy) : Shape(0, 0, xx, yy){}
	virtual void Area()
	{
		cout << fixed << setprecision(2) << x*y << endl;
	}
};

int main()
{
	double R, x, y, l;
	Shape *pt[3];

	int t; cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> R >> l >> x >> y;

		pt[0] = new Circle(R);
		pt[1] = new Square(l);
		pt[2] = new Rectangle(x, y);

		pt[0]->Area();
		pt[1]->Area();
		pt[2]->Area();
	}
	return 0;
}