#include<iostream>
using namespace std;

class Animal
{
public:
    virtual void speak()
    {

    }
};

class Cat:public Animal
{
public:
    void speak()
    {
        cout<<"猫叫"<<endl;
    }
};

class Dog:public Animal
{
public:
    void speak()
    {
        cout<<"狗叫"<<endl;
    }
};

void animal_case(Animal &a)
{
    a.speak();
}

void test_1()
{
    Cat c;
    Dog d;
    animal_case(c);
    animal_case(d );
}

int main()
{
    test_1();
    return 0;
}
