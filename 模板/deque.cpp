#include <deque>
#include <iostream>
#include<algorithm>

using namespace std;

// 打印deque
void print(deque<int> d)
{
    for (int i = 0; i < d.size(); i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;
}

// deque容器基本概念
void deque_overview()
{
    cout << "----------deque容器基本概念----------" << endl;
}

// deque构造函数
void deque_constructor()
{
    cout << "----------deque构造函数----------" << endl;
    deque<int> dq1;
    for (int i = 0; i < 5; i++)
    {
        dq1.push_back(i);
    }
    deque<int> dq2(dq1.begin(), dq1.end());
    deque<int> dq3(dq2);
    deque<int> dq4(5, 3);
    print(dq1);
    print(dq2);
    print(dq3);
    print(dq4);
}

// deque赋值操作
void deque_assign()
{
    cout << "----------deque赋值操作----------" << endl;
    deque<int> dq1;
    for (int i = 0; i < 5; i++)
    {
        dq1.push_back(i);
    }
    deque<int> dq2;
    dq2=dq1;
    deque<int> dq3;
    dq3.assign(dq1.begin(),dq1.end());
    deque<int> dq4;
    dq4.assign(2,5);
    print(dq1);
    print(dq2);
    print(dq3);
    print(dq4);
}

// deque大小操作
void deque_size()
{
    cout << "----------deque大小操作----------" << endl;
    deque<int> dq1;
    for (int i = 0; i < 5; i++)
    {
        dq1.push_back(i);
    }
    cout<<dq1.empty()<<endl;
    cout<<dq1.size()<<endl;
    dq1.resize(3);
    print(dq1);
}

// deque插入和删除
void deque_insert_erase()
{
    cout << "----------deque插入和删除----------" << endl;
    deque<int> dq1={1,2,3,4,5};
    deque<int> dq2={1,2,3,4,5};
    print(dq1);
    dq1.push_back(2);
    dq1.pop_back();
    print(dq1);
    dq1.push_front(1);
    print(dq1);
    dq1.insert(dq1.begin(),3);
    print(dq1);
    dq1.insert(dq1.begin(),3,3);
    print(dq1);
    dq1.insert(dq1.begin(),dq2.begin(),dq2.end());
    print(dq1);
    dq2.clear();
    print(dq2);
    dq1.erase(dq1.begin());
    print(dq1);
    dq1.erase(dq1.begin(),dq1.end());
    print(dq1);
}

// deque数据存取
void deque_access()
{
    cout << "----------deque数据存取----------" << endl;
    deque<int> dq1={1,2,3,4,5};
    cout<<dq1.at(2)<<endl;
    cout<<dq1[2]<<endl;
    cout<<dq1.front()<<" "<<dq1.back()<<endl;
}

// deque排序
void deque_sort()
{
    cout << "----------deque排序----------" << endl;
    deque<int> dq1={2,3,5,4,1};
    sort(dq1.begin(),dq1.end());
    print(dq1);
}

// 程序入口，依次调用各个deque练习函数
int main()
{
    deque_overview();
    deque_constructor();
    deque_assign();
    deque_size();
    deque_insert_erase();
    deque_access();
    deque_sort();
    return 0;
}
