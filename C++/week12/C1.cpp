#include <iostream>
using namespace std;

class Cvehicle
{
private:
	int max_speed;
	int speed;
	int weight;
public:
	Cvehicle(){}
	Cvehicle(int max_speed_, int speed_, int weight_)
	{
		max_speed = max_speed_;
		speed = speed_;
		weight = weight_;
	}
	void display()
	{
		cout << "Vehicle:" << endl
			 << "max_speed:" << max_speed << endl
			 << "speed:" << speed << endl
			 << "weight:" << weight << endl
			 << endl ;
	}
	int getmax_speed(){ return max_speed; }
	int getspeed(){ return speed; }
	int getweight(){ return weight; }
};

class Cbicycle : virtual public Cvehicle
{
private:
	int height;
public:
	Cbicycle(int height_){ height = height_; }
	void display()
	{
		cout << "Bicycle:" << endl
			 << "max_speed:" << getmax_speed() << endl
			 << "speed:" << getspeed() << endl
			 << "weight:" << getweight() << endl
			 << "height:" << height << endl
			 << endl ;
	}
	int getheight(){ return height; }
};

class Cmotocar : virtual public Cvehicle
{
private:
	int seat_num;
public:
	Cmotocar(int seat_num_){ seat_num = seat_num_; }
	void display()
	{
		cout << "Motocar:" << endl
			 << "max_speed:" << getmax_speed() << endl
			 << "speed:" << getspeed() << endl
			 << "weight:" << getweight() << endl
			 << "seat_num:" << seat_num << endl
			 << endl ;
	}
	int getseat_num(){ return seat_num; }
};

class Cmotocycle : public Cbicycle, public Cmotocar
{
public:
	Cmotocycle(int max_speed_, int speed_, int weight_, int height_, int seat_num_) : Cmotocar(seat_num_), Cbicycle(height_), Cvehicle(max_speed_, speed_, weight_){}
	void display()
	{
		cout << "Motocycle:" << endl
			 << "max_speed:" << getmax_speed() << endl
			 << "speed:" << getspeed() << endl
			 << "weight:" << getweight() << endl
			 << "height:" << getheight() << endl
			 << "seat_num:" << getseat_num() << endl ;
	}
};

int main()
{
	int max_speed_, speed_, weight_, height_, seat_num_;
	cin >> max_speed_ >> speed_ >> weight_ >> height_ >> seat_num_ ;
	Cmotocycle user(max_speed_, speed_, weight_, height_, seat_num_);
	user.Cvehicle::display();
	user.Cbicycle::display();
	user.Cmotocar::display();
	user.Cmotocycle::display();
	return 0;
}