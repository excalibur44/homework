#include <iostream>
using namespace std;
 
class count
{
public:
    void increment() { value++; }
protected:
    int value;
};
 
class round : public count
{
public:
    round() {}
    round(int max, int min, int value_)
    {
        max_value = max;
        min_value = min;
        value = value_;
    }
    ~round() {}
    int increment(int max, int min, int value)
    {
        max_value = max;
        if (value < max_value - 1)
            return 1;
        else
            return 0;
    }
private:
    int min_value, max_value;
};
 
class CLOCK : public round
{
public:
    CLOCK() {}
    CLOCK(int h, int m, int s) { hour = h; minute = m; second = s; }
    ~CLOCK() {}
    void time(int newsecond);
private:
    int hour;
    int minute;
    int second;
};
 
void CLOCK::time(int newsecond)
{
    while (newsecond > 0)
    {
        if (increment(60, 0, second))
            second++;
        else
        {
            second = 0;
            if (increment(60, 0, minute))
                minute++;
            else
            {
                minute = 0;
                if (increment(24, 0, hour))
                    hour++;
                else
                    hour = 0;
            }
        }
        newsecond--;
    }
    cout << hour << ":" << minute << ":" << second << endl;
}
 
int main()
{
    int t; cin >> t; CLOCK asdf;
    for (int i = 0; i < t; i++)
    {
        int h, m, s; cin >> h >> m >> s;
        asdf = CLOCK(h, m, s);
        int newsecond; cin >> newsecond;
        asdf.time(newsecond);
    }
    return 0;
}
