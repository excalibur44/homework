#include <iostream>
#include <string.h>
using namespace std;

class cPeople
{
protected:
    char id[20];
    char name[20];
public:
    cPeople(int xm_[], int id_[])
    {
        strcpy(id, id_);
        strcpy(name, xm);
    }
};

class cInternetUser : public cPeople
{
protected:
    char password[20];
public:
    void registerUser(char xm[], char id[], char mm[]) : cPeople(xm, id)
    {
        strcpy(password, mm);
    }
    void login(){}
};

class cBankCustomer : public cPeople
{
protected:
    double balance;
public:
    cBankCustomer(){}
    openAccount(char xm[], char id[]) : cPeople(xm, id){}
    deposit(){}
    withdraw(){}

};

class cInternetBankCustomer : public cInternetUser, public cBankCustomer
{
protected:
    float balance;
    float yesterdayBalance;
    float todayIncome;
    float yesterdayMillionIncome;
    float todayMillionIncome;
public:
    cInternetBankCustomer(){}
    setMillionIncome(){}
    countTodayIncome(){}//CInternetBankCustomer类对象当日存款不计算收益，第2天开始才能计算收益，当日取款部分无收益。
    bool login(char id_[], char xm[]){}
};


void main()
{
    int t, no_of_days, i;
    char i_xm[20], i_id[20], i_mm[20], b_xm[20], b_id[20], ib_id[20], ib_mm[20];
    double money, interest;
    char op_code;

    //输入测试案例数t
    cin >> t;
    while (t--)
    {
        //输入互联网用户注册时的用户名,id,登陆密码
        cin >> i_xm >> i_id >> i_mm;
        //输入银行开户用户名,id
        cin >> b_xm >> b_id;
        //输入互联网用户登陆时的id,登陆密码
        cin >> ib_id >> ib_mm;

        cInternetBankCustomer ib_user;
        ib_user.registerUser(i_xm, i_id, i_mm);
        ib_user.openAccount(b_xm, b_id);

        if (ib_user.login(ib_id, ib_mm) == 0)  //互联网用户登陆,若id与密码不符;以及银行开户姓名和id与互联网开户姓名和id不同
        {
            cout << "Password or ID incorrect" << endl;
            continue;
        }

        //输入天数
        cin >> no_of_days;
        for (i=0; i < no_of_days; i++)
        {
          //输入操作代码, 金额, 当日万元收益
            cin >> op_code >> money >> interest;
            switch (op_code)
            {
                case 'S':  //从银行向互联网金融帐户存入
                case 's':
                    if (ib_user.deposit(money) == 0)
                    {
                        cout << "Bank balance not enough" << endl;
                        continue;
                    }
                    break;
                case 'T':  //从互联网金融转入银行帐户
                case 't':
                    if (ib_user.withdraw(money) == 0)
                    {
                        cout << "Internet bank balance not enough" << endl;
                        continue;
                    }
                    break;
                case 'D':  //直接向银行帐户存款
                case 'd':
                    ib_user.CBankCustomer::deposit(money);
                    break;
                case 'W':  //直接从银行帐户取款
                case 'w':
                    if (ib_user.CBankCustomer::withdraw(money) == 0)
                    {
                        cout << "Bank balance not enough" << endl;
                        continue;
                    }
                    break;
              default:
                    cout << "Illegal input" << endl;
                    continue;
            }
            ib_user.setInterest(interest);
            ib_user.calculateProfit();
            //输出用户名,id 
            //输出银行余额
            //输出互联网金融账户余额
            ib_user.print();
        }
    }
}
