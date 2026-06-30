#include <iostream>
#include <set>
#include <string>

using namespace std;

void print(const set<int> &s)
{
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void print(const multiset<int> &s)
{
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// set基本概念
void set_overview()
{
    cout << "----------set基本概念----------" << endl;
}

// set构造和赋值
void set_constructor_assign()
{
    cout << "----------set构造和赋值----------" << endl;
    set<int> s1 = {1, 2, 3, 6, 5};
    set<int> s2(s1);
    set<int> s3;
    s3 = s2;
    print(s1);
    print(s2);
    print(s3);
}

// set大小和交换
void set_size_swap()
{
    cout << "----------set大小和交换----------" << endl;
    set<int> s1 = {1, 2, 5, 6, 4};
    cout << s1.empty() << endl;
    cout << s1.size() << endl;
    set<int> s2 = {5, 6, 8, 9};
    s1.swap(s2);
    print(s1);
    print(s2);
}

// set插入和删除
void set_insert_erase()
{
    cout << "----------set插入和删除----------" << endl;
    set<int> s1;
    s1.insert(5);
    s1.insert(4);
    s1.insert(6);
    s1.insert(9);
    print(s1);
    s1.erase(s1.begin());
    s1.erase(s1.begin(), s1.end());
    s1.erase(5);
    s1.clear();
}

// set查找和统计
void set_find_count()
{
    cout << "----------set查找和统计----------" << endl;
    set<int> s1 = {1, 5, 6, 2, 4, 5};
    auto it = s1.find(5);
    if (it != s1.end())
    {
        cout << "找到了" << endl;
    }
    else
    {
        cout << "没找到" << endl;
    }
    cout << s1.count(5) << endl;
}

// set和multiset区别
void set_multiset_difference()
{
    cout << "----------set和multiset区别----------" << endl;
    multiset<int> ms1;
    ms1.insert(10);
    ms1.insert(10);
    print(ms1);
}

// pair对组创建
void pair_create()
{
    cout << "----------pair对组创建----------" << endl;
    pair<string, int> p("hello", 10);
    pair<string, int> p1 = make_pair("hello1", 101);
    cout << p.first << ' ' << p.second << endl;
    cout << p1.first << ' ' << p1.second << endl;
}

class Person
{
private:
    string name;
    int age;

public:
    Person(string name, int age) : name(name), age(age) {}
    inline string get_name() const { return name; }
    inline int get_age() const { return age; }

    void set_name(const string &name)
    {
        this->name = name;
    }
    void set_age(const int &age)
    {
        this->age = age;
    }
    bool operator<(const Person &p) const
    {
        return age < p.age;
    }
};

class MyCompare
{
public:
    bool operator()(int a, int b) const
    {
        return a > b;
    }
};

void print(const set<int, MyCompare> &s)
{
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void print(const set<Person> &s)
{
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << it->get_name() << " " << it->get_age() << endl;
    }
}

// 内置数据类型set容器排序
void set_builtin_sort()
{
    cout << "----------内置数据类型set容器排序----------" << endl;
    set<int, MyCompare> s1 = {1, 2, 6, 5, 4};
    print(s1);
}

// 自定义数据类型set容器排序
void set_custom_sort()
{
    cout << "----------自定义数据类型set容器排序----------" << endl;
    set<Person> s1;
    s1.insert(Person("A", 18));
    s1.insert(Person("B", 20));
    s1.insert(Person("C", 16));
    print(s1);
}

int main()
{
    set_overview();
    set_constructor_assign();
    set_size_swap();
    set_insert_erase();
    set_find_count();
    set_multiset_difference();
    pair_create();
    set_builtin_sort();
    set_custom_sort();
    return 0;
}
