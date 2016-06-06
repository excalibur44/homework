#include <iostream>
#include <string>
using namespace std;

class people
{
private:
	string name;
	char sex;
	int age;
public:
	people(){}
	people(string name_, char sex_, int age_)
	{
		name = name_;
		sex = sex_;
		age = age_;
	}
	void display()
	{
		cout << "People:" << endl
			 << "Name: " << name << endl
			 << "Sex: " << sex << endl
			 << "Age: " << age << endl
			 << endl;
	}
	string getname(){ return name; }
	char getsex(){ return sex; }
	int getage(){ return age; }
};

class student : virtual public people
{
private:
	int no;
	float score;
public:
	student(int no_, float score_)
	{
		no = no_;
		score = score_;
	}
	void display()
	{
		cout << "Student:" << endl
			 << "Name: " << getname() << endl
			 << "Sex: " << getsex() << endl
			 << "Age: " << getage() << endl
			 << "No.: " << no << endl
			 << "Score: " << score << endl
			 << endl;
	}
	int getno(){ return no; }
	float getscore(){ return score; }
};

class teacher : virtual public people
{
private:
	string position;
	string department;
public:
	teacher(string position_, string department_)
	{
		position = position_;
		department = department_;
	}
	void display()
	{
		cout << "Teacher:" << endl
			 << "Name: " << getname() << endl
			 << "Sex: " << getsex() << endl
			 << "Age: " << getage() << endl
			 << "Position: " << position << endl
			 << "Department: " << department << endl
			 << endl;
	}
	string getposition(){ return position; }
	string getdepartment(){ return department; }
};

class grad_onwork : public student, public teacher
{
private:
	string direction;
	string tutor;
public:
	grad_onwork(string name_, char sex_, int age_, int no_, float score_, string position_, string department_, string direction_, string tutor_) : people(name_, sex_, age_), student(no_, score_), teacher(position_, department_)
	{
		direction = direction_;
		tutor = tutor_;
	}
	void display()
	{
		cout << "GradOnWork:" << endl
			 << "Name: " << getname() << endl
			 << "Sex: " << getsex() << endl
			 << "Age: " << getage() << endl
			 << "No.: " << getno() << endl
			 << "Score: " << getscore() << endl
			 << "Position: " << getposition() << endl
			 << "Department: " << getdepartment() << endl
			 << "Direction: " << direction << endl
			 << "Tutor: " << tutor << endl;
	}
};

int main()
{
	string name_; char sex_; int age_; 		cin >> name_ >> sex_ >> age_;
	int no_; float score_;				cin >> no_ >> score_;
	string position_; string department_;	cin >> position_ >> department_;
	string direction_; string tutor_;		cin >> direction_ >> tutor_;
	grad_onwork humen(name_, sex_, age_, no_, score_, position_, department_, direction_, tutor_);
	humen.people::display();
	humen.student::display();
	humen.teacher::display();
	humen.grad_onwork::display();
	return 0;
}
