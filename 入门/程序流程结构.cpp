#include <iostream>
using namespace std;


void if_case()
{
    int score;
    while(1)
    {
        cout<<"请输入高考分数：";
        cin>>score;
        if(score>600)
        {
            if(score>700)
            {
                cout<<"北大"<<endl;
            }
            else if(score>650)
            {
                cout<<"清华"<<endl;
            }
            else
            {
                cout<<"人大"<<endl;
            }
        }
        else if(score>500)
        {
            cout<<"二本"<<endl;
        }
        else if(score>400)
        {
            cout<<"三本"<<endl;
        }
        else
        {
            cout<<"专科"<<endl;
        }
    }
}

int three_operator_case()
{
    int a,b,c;
    cin>>a>>b>>c;
    return (a>b?a:b)>c?(a>b?a:b):c;
}

void switch_case()
{
    int a=3;
    switch(a)
    {
        case 1:cout<<"1";break;
        case 2:cout<<"2";break;
        case 3:cout<<"3";break;
        default:cout<<"x";break;
    }
}

void while_case()
{
    srand((unsigned int)time(NULL));
    int a=rand()%100+1;
    int number=0;
    cout<<"猜数字游戏开始,请输入数字："<<endl;
    while(1)
    {
        cin>>number;
        if(a>number)
        {
            cout<<"猜小了"<<endl;
        }
        else if(a<number)
        {
            cout<<"猜大了"<<endl;
        }
        else
        {
            cout<<"猜对了"<<endl;
            break;
        }
    }
}

void do_while_case()
{
    int num=-1;
    do
    {
        cout<<num;
        num++;
    }while(num>0&&num<10);
}

void for_case()
{
    for(int i=1;i<10;i++)
    {
        for(int j=1;j<i+1;j++)
        {
            cout<<j<<"*"<<i<<"="<<j*i<<"\t";
        }
        cout<<endl;
    }

}

int main()
{
    // while_case();
    // do_while_case();
    for_case();
    return 0;
}
