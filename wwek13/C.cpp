#include <iostream>
using namespace std;

class stack
{
private:
	int *sp, *top, max;
	void inflate(int lenth);
public:
	stack(){}
	stack(int size):max(size)
	{
		sp = new int[max];
		top = &sp[max-1];
	}
	void pop(){ top -= 1; }
	void push(int value)
	{
		*sp = value;
		sp++;
	}
	void operator = (stack & rightvalue)
	{
		stack temp;

		temp.sp = sp;
		temp.top = top;
		temp.max = max;

		sp = rightvalue.sp;
		top = rightvalue.top;
		max = rightvalue.max;

		rightvalue.sp = temp.sp;
		rightvalue.top = temp.top;
		rightvalue.max = temp.max;

	}
	void show(int x)
	{
		sp = sp - (max);
		for(int i = 0; i < x; i++)
			cout << sp[i] << "";
		cout << endl;
	}
};

int main()
{
	int x, y; cin >> x >> y;
	stack first(x), second(y);
	for(int i = 0; i < x; i++)
	{
		int j; cin >> j;
		first.push(j);
	}
	for(int i = 0; i < y; i++)
	{
		int j; cin >> j;
		second.push(j);
	}
	second.pop();
	first = second;
	first.show(x);
	second.show(x);
	return 0;
}