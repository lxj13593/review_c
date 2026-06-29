#include<iostream>
using namespace std;

// 全局函数做友元
class Person
{
private:
    int age;
    int score;
public:
    friend void print_person(Person p);
    Person(int age,int score):age(age),score(score)
    {

    }
};

void print_person(Person p)
{
    cout<<p.age<<" "<<p.score<<endl;
}

void test_1()
{
    Person p1(10,20);
    print_person(p1);
}

//类做友元
class B;

class A
{
private:
    B *b;
public:
    A();
    A(int x,int y);
    void show();
};

class B
{
private:
    int a;
    int b;
public:
    friend class A;
    B(int a,int b);
};

B::B(int a,int b):a(a),b(b){}

A::A():b(nullptr){}

A::A(int x,int y):b(new B(x,y)){}

void A::show()
{
    cout<<b->a<<" "<<b->b<<endl;
}

void test_2()
{
    A a(1,2);
    a.show();
}


int main()
{
    // test_1();
    // test_2();
    return 0;
}
