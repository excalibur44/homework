#include <iostream>
using namespace std;

template <class mytype>
class table
{
private:
    mytype x[100];
    int length;
public:
    table(int m) : length(m)
    {
        set();
        for(int i = 0; i < m; i++)
            cin >> x[i];
    }
    void set()
    {
        for(int i = 0; i < 100; i++)
            x[i] = -1;
    }
    void insectnum(int m)
    {
        length += 1;
        for(int i = length-1; i > m; i--)
            x[i] = x[i-1];
        cin >> x[m];
    }
    void deletenum(int m)
    {
        length -= 1;
        for(int i = m; i < length; i++)
            x[i] = x[i+1];
    }
    void print()
    {
        for(int i = 0; i < length; i++)
        {
            cout << x[i];
            if(i+1 != length)
                cout << " ";
        }
        cout << endl;
    }
};

int main()
{
    int m; 
    cin >> m; table<int> z(m);
    cin >> m; z.insectnum(m); 
    cin >> m; z.deletenum(m);
    z.print();

    cin >> m; table<float> f(m);
    cin >> m; f.insectnum(m);
    cin >> m; f.deletenum(m);
    f.print();

    return 0;
}
