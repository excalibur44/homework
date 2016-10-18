#include <iostream>
using namespace std;

class myclock
{
private:
    int h, m, s;
public:
    myclock(int hh, int mm, int ss) : h(hh), m(mm), s(ss){}
    myclock& operator ++ ()
    {
        s++;
        if(s == 60)
        {
            s = 0;
            m++;
            if(m == 60)
            {
                m = 0;
                h++;
                if(h == 12)
                    h = 0;
            }
        }
        return *this;
    }
    myclock& operator -- (int)
    {
        s--;
        if(s == -1)
        {
            s = 59;
            m--;
            if(m == -1)
            {
                m = 59;
                h--;
                if(h == -1)
                    h = 11;
            }
        }
        return *this;
    }
    void print()
    {
        cout << h << ":"
             << m << ":"
             << s << endl;
    }
};

int main()
{
    int h, m, s; cin >> h >> m >> s;
    myclock time(h, m, s);
    int t; cin >> t;
    while(t--)
    {
        cin >> s;
        if(s > 0)
        {
            while(s--)
            {
                ++time;
            }
        }
        else
        {
            s = -s;
            while(s--)
            {
                time--;
            }
        }
        time.print();
    }
}