#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

// 打印list
void print(list<int> l)
{
    for (auto it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// list基本概念
void list_overview()
{
    cout << "----------list基本概念----------" << endl;
}

// list构造函数
void list_constructor()
{
    cout << "----------list构造函数----------" << endl;
    list<int> l1 = {1, 2, 3, 4};
    list<int> l2(l1);
    list<int> l3;
    list<int> l4(l1.begin(), l1.end());
    list<int> l5(2, 5);
}

// list赋值和交换
void list_assign_swap()
{
    cout << "----------list赋值和交换----------" << endl;
    list<int> l1 = {1, 2, 3, 4};
    list<int> l2;
    l2 = l1;
    list<int> l3;
    list<int> l4;
    l3.assign(l1.begin(), l1.end());
    l4.assign(5, 5);
    l3.swap(l4);
    print(l1);
    print(l2);
    print(l3);
    print(l4);
}

// list大小操作
void list_size()
{
    cout << "----------list大小操作----------" << endl;
    list<int> l1;
    cout << l1.empty() << endl;
    l1.assign({1, 2, 3, 4});
    cout << l1.size() << endl;
    l1.resize(3);
    print(l1);
}

// list插入和删除
void list_insert_erase()
{
    cout << "----------list插入和删除----------" << endl;
    list<int> l1;
    l1.push_back(5);
    l1.push_back(5);
    l1.push_back(5);
    l1.insert(l1.begin(), 5);
    l1.insert(l1.begin(), 2, 5);
    l1.insert(l1.begin(), l1.begin(), l1.end());
    l1.erase(l1.begin(), l1.end());
    l1.remove(5);
}

// list数据存取
void list_access()
{
    cout << "----------list数据存取----------" << endl;
    list<int> l1 = {1, 2, 3, 4};
    cout << l1.front() << " " << l1.back() << endl;
}

// list反转和排序
void list_reverse_sort()
{
    cout << "----------list反转和排序----------" << endl;
    list<int> l1 = {2, 3, 4, 1};
    l1.reverse();
    print(l1);
    l1.sort();
    print(l1);
}

class Person
{
private:
    string name;
    int age;
    int height;

public:
    inline string get_name() const { return name; }
    inline int get_age() const { return age; }
    inline int get_height() const { return height; }

    void set_name(const string &name)
    {
        this->name = name;
    }
    void set_age(const int &age)
    {
        this->age = age;
    }
    void set_height(const int &height)
    {
        this->height = height;
    }
    Person(string name,int age,int height):name(name),age(age),height(height)
    {

    }
};

ostream &operator<<(ostream &out, const Person &p)
{
    out << p.get_name() << " " << p.get_age() << " " << p.get_height();
    return out;
}

void print_person(list<Person> l)
{
    for (auto it = l.begin(); it != l.end(); it++)
    {
        cout << *it << endl;
    }
}

bool compare_person(const Person &p1,const Person &p2)
{
    if(p1.get_age()==p2.get_age())
    {
        return p1.get_height()>p2.get_height();
    }
    else
    {
        return p1.get_age()<p2.get_age();
    }
}

// 排序案例
void list_sort_case()
{
    cout << "----------排序案例----------" << endl;
    list<Person> p;
    Person p1("A", 35, 175);
    Person p2("B", 45, 180);
    Person p3("C", 40, 170);
    Person p4("D", 25, 190);
    Person p5("E", 35, 160);

    p.push_back(p1);
    p.push_back(p2);
    p.push_back(p3);
    p.push_back(p4);
    p.push_back(p5);
    
    p.sort(compare_person);
    print_person(p);
}

// 程序入口，依次调用各个list练习函数
int main()
{
    // list_overview();
    // list_constructor();
    // list_assign_swap();
    // list_size();
    // list_insert_erase();
    // list_access();
    // list_reverse_sort();
    list_sort_case();
    return 0;
}
