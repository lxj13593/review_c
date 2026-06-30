#include <iostream>
#include <map>
#include<string>

using namespace std;

// map基本概念
void map_overview()
{
    cout << "----------map基本概念----------" << endl;
}

void print(const map<int,string> &m)
{
    for(auto it=m.begin();it!=m.end();it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
}

// map构造和赋值
void map_constructor_assign()
{
    cout << "----------map构造和赋值----------" << endl;
    map<int,string> m1;
    m1.insert(pair<int,string>(5,"j"));
    m1.insert(pair<int,string>(4,"g"));
    m1.insert(pair<int,string>(6,"y"));
    m1.insert(pair<int,string>(3,"s"));
    map<int,string> m2(m1);
    map<int,string> m3;
    m3=m1;
    print(m3);
}

// map大小和交换
void map_size_swap()
{
    cout << "----------map大小和交换----------" << endl;
    map<int,string> m1;
    m1.insert(pair<int,string>(5,"j"));
    m1.insert(pair<int,string>(4,"g"));
    m1.insert(pair<int,string>(6,"y"));
    m1.insert(pair<int,string>(3,"s"));
    map<int,string> m2;
    m2.insert(pair<int,string>(8,"g"));
    cout<<m1.size()<<endl;
    cout<<m2.empty()<<endl;
    m1.swap(m2);
    print(m1);
    print(m2);
}

// map插入和删除
void map_insert_erase()
{
    cout << "----------map插入和删除----------" << endl;
    map<int,string> m1;
    m1.insert(make_pair(3,"a"));
    m1.insert(make_pair(4,"b"));
    m1.insert(make_pair(6,"d"));
    m1.insert(make_pair(2,"a"));
    print(m1);
    m1.erase(m1.begin());
    print(m1);
    m1.erase(m1.begin(),m1.end());
    print(m1);
    m1.clear();
    print(m1);
    m1.erase(2);
}

// map查找和统计
void map_find_count()
{
    cout << "----------map查找和统计----------" << endl;
    map<int,int> m1;
    m1.insert({2,3});
    m1.insert({3,4});
    m1.insert({4,2});
    auto it=m1.find(4);
    if(it!=m1.end())
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
    cout<<m1.count(3)<<endl;
}

bool my_compare(int a,int b)
{
    return a>b;
}

class MyCompare
{
public:
    bool operator()(int a,int b) const
    {
        return a>b;
    }
};

void print(const map<int,int,MyCompare> &m)
{
    for(auto it=m.begin();it!=m.end();it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
}

// map容器排序
void map_sort()
{
    cout << "----------map容器排序----------" << endl;
    map<int,int,MyCompare> m1;
    m1.insert({10,10});
    m1.insert({12,10});
    m1.insert({14,10});
    m1.insert({8,10});
    print(m1);
}

int main()
{
    map_overview();
    map_constructor_assign();
    map_size_swap();
    map_insert_erase();
    map_find_count();
    map_sort();
    return 0;
}
