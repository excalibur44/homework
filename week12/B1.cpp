#include <iostream>
#include <string>
using namespace std;

class member
{
private:
	int member_card_number;
	int journey_points;
public:
	member(int member_card_number_)
	{
		member_card_number = member_card_number_;
		journey_points = 0;
	}
	int getmember_card_number(){ return member_card_number; }
	int getjourney_points(){ return journey_points; }
	void setmember_card_number(int member_card_number_){ member_card_number = member_card_number_; }
	void setjourney_points(int journey_points_){ journey_points = journey_points_; }
};

class vip
{
private:
	int 	credit_card_number;
	string 	name;
	int 	credits;
	float 	bills;
	int 	credit_card_points;
public:
	vip(int credit_card_number_, string name_, int credits_)
	{
		credit_card_number = credit_card_number_;
		name = name_;
		credits = credits_;
		bills = 0;
		credit_card_points = 0;
	}
	int getcredit_card_number(){ return credit_card_number; }
	string getname(){ return name; }
	int getcredits(){ return credits; }
	float getbills(){ return bills; }
	int getcredit_card_points(){ return credit_card_points; }
	void setbills(float bills_){ bills = bills_; }
	void setcredit_card_points(int credit_card_points_){ credit_card_points = credit_card_points_; }
};

class card : public member, public vip
{
public:
	card(int member_card_number_, int credit_card_number_, string name_, int credits_) : member(member_card_number_), vip(credit_card_number_, name_, credits_){}
	void show()
	{
		cout << getmember_card_number() << " "
			 << getjourney_points()
			 << endl
			 << getcredit_card_number() << " "
			 << getname() << " "
			 << getbills() << " "
			 << getcredit_card_points()
			 << endl;
	}
	void order(float m)
	{
		if(m < getcredits() - getbills())
		{
			setbills(m + getbills()); //bills += m;
			setjourney_points((int)m + getjourney_points()); //journey_points += (int)m;
			setcredit_card_points((int)m + getcredit_card_points()); //credit_card_points += (int)m;
		}
	}
	void consump(float m)
	{
		if(m < getcredits() - getbills())
		{
			setbills(m + getbills()); //bills += m;
			setcredit_card_points((int)m + getcredit_card_points()); //credit_card_points += (int)m;
		}
	}
	void refund(float m)
	{
		if(getbills() > m)
		{	
			setbills(getbills() - m); //bills -= m;
			setcredit_card_points(getcredit_card_points() - (int)m); //credit_card_points -= (int)m;
		}
	}
	void exchange(float m)
	{
		if((int)m < getcredit_card_points())
		{
			setjourney_points(getjourney_points() + ((int)(m))/2); //journey_points += ((int)(m))/2;
			setcredit_card_points(getcredit_card_points() - (int)m); //credit_card_points -= (int)m;
		}
	}
};



int main()
{
	int member_card_number_; int credit_card_number_; string name_; int credits_;	cin >> member_card_number_ >> credit_card_number_ >> name_ >> credits_ ;
	card guest( member_card_number_ , credit_card_number_ , name_ , credits_ );
	
	int t; cin >> t; float m; char operate;
	for(int i = 0; i < t; i++)
	{
		cin >> operate >> m;
		if(operate == 'o')
			guest.order(m);
		else if(operate == 'c')
			guest.consump(m);
		else if(operate == 'q')
			guest.refund(m);
		else if(operate == 't')
			guest.exchange(m);
	}
	guest.show();
	return 0;
}