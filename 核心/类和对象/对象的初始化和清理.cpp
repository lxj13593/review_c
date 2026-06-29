#include <iostream>
using namespace std;

class Person
{
private:
    int age;

public:
    Person() {}
    Person(int age) : age(age) {}
    Person(const Person &p) : age(p.age) {}
    ~Person() {}
};

void test_1()
{
    Person p1;
    Person p2(10);
    Person p3(p2);
}

class Person1
{
private:
    int age;
    int *height;
public:
    Person1():age(0),height(nullptr)
    {

    }
    Person1(int age,int height)
    {
        this->age=age;
        this->height=new int(height);
    }
    Person1(const Person1 &p)
    {
        this->age=p.age;
        if(p.height!=nullptr)
        {
            this->height=new int(*p.height);
        }
        else
        {
            height=nullptr;
        }
    }
    ~Person1()
    {
        if(height!=nullptr)
        {
            delete height;
            height=nullptr;
        }
    }
};

class Circle
{
private:
    static int a;
    int b;
public:
    static void fun()
    {
        cout<<a<<endl;
        // cout<<b<<endl;
    }
    void setA(const int &a)
    {
        this->a=a;
    }
    static int getA()
    {
        return a;
    }
};

int Circle::a=10;

void static_member()
{
    Circle c1;
    c1.setA(20);
    cout<<Circle::getA()<<endl;
    Circle::fun();
}

int main()
{
    // test_1();
    static_member();
    return 0;
}
