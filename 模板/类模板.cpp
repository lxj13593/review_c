#include<iostream>
using namespace std;

template<class Name,class Age>
class Person
{
public:
    Person(Name name,Age age):name(name),age(age) {}

    Name name;
    Age age;
};


ostream& operator<<(ostream &out,const Person<string,int> &p)
{
    out<<p.name<<" "<<p.age<<endl;
    return out;
}

void test_1()
{
    Person<string,int> p1("李小嘉",23);
    cout<<p1;
}

int main()
{
    test_1();
    return 0;
}
