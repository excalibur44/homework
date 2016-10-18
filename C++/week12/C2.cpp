#include<iostream>
#include<string>
using namespace std;

class Animal
{
protected:
	string name, nickname; int age;
public:
	Animal(string name_, string nickname_, int age_){ name = name_; nickname = nickname_; age = age_; }
	virtual void speak(){}
};

class tiger : public Animal
{
public:
	tiger(string name_, string nickname_, int age_) : Animal(name_, nickname_, age_){}
	virtual void speak(){ cout << "Hello,I am " << nickname << ",AOOO." << endl; }
};

class dog : public Animal
{
public:
	dog(string name_, string nickname_, int age_) : Animal(name_, nickname_, age_){}
	virtual void speak(){ cout << "Hello,I am " << nickname << ",WangWang." << endl;}
};

class duck : public Animal
{
public:
	duck(string name_, string nickname_, int age_) : Animal(name_, nickname_, age_){}
	virtual void speak(){ cout << "Hello,I am " << nickname << ",GAGA." << endl; }
};

class pig : public Animal
{
public:
	pig(string name_, string nickname_ , int age_) : Animal(name_, nickname_, age_){}
	virtual void speak(){ cout << "Hello,I am " << nickname << ",HENGHENG." << endl; }
};

int main()
{
	Animal *A;
	int t; cin >> t;
	for(int i = 0; i < t; i++)
	{
		string name, nickname; int age;
		cin >> name >> nickname >> age;
		if(name == "Tiger")
		{
			tiger a(name, nickname, age);
			A = &a; A->speak();
		}
		else if(name == "Dog")
		{
			dog a(name, nickname, age);
			A = &a; A->speak();
		}
		else if(name=="Duck")
		{
			duck a(name, nickname, age);
			A = &a;	A->speak();
		}
		else if(name == "Pig")
		{
			pig a(name, nickname, age);
			A = &a; A->speak();
		}
		else
			cout << "There is no " << name << " in our Zoo." << endl;
	}
	return 0;
}