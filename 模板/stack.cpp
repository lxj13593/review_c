#include <iostream>
#include <stack>

using namespace std;

// stack构造函数
void stack_constructor()
{
    cout << "----------stack构造函数----------" << endl;
    stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(2);
    s1.push(2);
    s1.push(2);
    stack<int> s2(s1);
    while (!s2.empty())
    {
        cout << s2.top() << " ";
        s2.pop();
    }
    cout << endl;
}

// stack赋值操作
void stack_assign()
{
    cout << "----------stack赋值操作----------" << endl;
    stack<int> s1;
    stack<int> s2;
    s2 = s1;
}

// stack数据存取
void stack_access()
{
    cout << "----------stack数据存取----------" << endl;
    stack<int> s1;
    s1.push(4);
    s1.push(5);
    s1.push(6);
    s1.pop();
    cout << s1.top() << endl;
}

// stack大小操作
void stack_size()
{
    cout << "----------stack大小操作----------" << endl;
    stack<int> s1;
    s1.push(4);
    s1.push(5);
    s1.push(6);
    cout<<s1.empty()<<endl;
    cout<<s1.size()<<endl;
}

// 程序入口，依次调用各个stack练习函数
int main()
{
    stack_constructor();
    stack_assign();
    stack_access();
    stack_size();
    return 0;
}
