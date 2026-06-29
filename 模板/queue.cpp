#include <iostream>
#include <queue>

using namespace std;

// queue构造函数
void queue_constructor()
{
    cout << "----------queue构造函数----------" << endl;
    queue<int> q1;
    queue<int> q2(q1);
}

// queue赋值操作
void queue_assign()
{
    cout << "----------queue赋值操作----------" << endl;
    queue<int> q1;
    queue<int> q2;
    q2=q1;
}

// queue数据存取
void queue_access()
{
    cout << "----------queue数据存取----------" << endl;
    queue<int> q1;
    q1.push(5);
    q1.push(4);
    q1.push(3);
    q1.push(2);
    q1.pop();
    cout<<q1.front()<<" "<<q1.back()<<endl;
}

// queue大小操作
void queue_size()
{
    cout << "----------queue大小操作----------" << endl;
    queue<int> q1;
    q1.push(5);
    q1.push(4);
    q1.push(3);
    q1.push(2);
    q1.pop();
    cout<<q1.empty()<<endl;
    cout<<q1.size()<<endl;
}

// 程序入口，依次调用各个queue练习函数
int main()
{
    queue_constructor();
    queue_assign();
    queue_access();
    queue_size();
    return 0;
}
