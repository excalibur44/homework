//1.1.1
#include <iostream>
#include <string>
#include <cmath>
#include <math.h>
using namespace std;
int sum(int, int ,int);

int sum(int y,int m,int d)
{
	unsigned char x[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int i,s=0;
	for(i=1;i<y;i++)
		if(i%4==0 && i%100!=0 || i%400==0)
			s+=366;//闰年
		else
			s+=365;//平年
	if(y%4==0 && y%100!=0 || y%400==0)
		x[2]=29;
	for(i=1;i<m;i++)
		s+=x[i];//整月的天数
	s+=d;//日的天数
	return s;//返回总天数,相对公元1年
}

class birth
{
private:
	string name;
	int year;
	int month;
	int day;
	int distance;
public:
	birth(){}
	birth(string n, int y, int m, int d):name(n),year(y),month(m),day(d)
	{
		distance = sum(year, month, day);
	}
	int operator - (const birth &c)
	{ 
		if(distance > c.distance)
			return (distance-c.distance); 
		else 
			return (c.distance-distance); 
	}
	string getname(){ return name; }
};

class save
{
public:
	save(){}
	string name1;
	string name2;
	int distance;
	save(string n1, string n2, int dis):name1(n1),name2(n2),distance(dis){}
};

int main()
{
	int t; cin >> t;
	birth people[10];
	for(int i = 0; i < t; i++)
	{
		string name; int year, month, day;
		cin >> name >> year >> month >> day;
		people[i] = birth(name, year, month, day);
	}
	save dis[45];int j = 0;
	for(int m = 0; m < t-1; m++)
	{
		for(int n = m+1; n < t; n++)
		{
			dis[j] = save(people[m].getname(), people[n].getname(), people[m]-people[n]);
			j++;
		}
	}
	int max = 0; save maxx;
	for(int i = 0; i < j; i++)
	{
		if(dis[i].distance > max)
		{
			maxx = dis[i];
			max = dis[i].distance;
		}
	}
	cout << maxx.name1 << "和" << maxx.name2
		 << "年龄相差最大，为" << maxx.distance
		 << "天。" << endl;
	return 0;
}