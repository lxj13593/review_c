#include <iostream>
using namespace std;
#include <string>
#include<vector>
#include<map>

class Person
{
private:
    string name;
    double salary;

public:
    inline string get_name() const { return name; }
    inline double get_salary() const { return salary; }

    void set_name(const string &name)
    {
        this->name = name;
    }
    void set_salary(const double &salary)
    {
        this->salary = salary;
    }
    Person(string name, double salary) : name(name), salary(salary)
    {
    }
};

class Department
{
private:
    string name;
    int serial_number;

public:
    inline string get_name() const { return name; }
    inline int get_serial_number() const { return serial_number; }

    void set_name(const string &name)
    {
        this->name = name;
    }
    void set_serial_number(const int &serial_number)
    {
        this->serial_number = serial_number;
    }
    Department(string name):name(name)
    {
        if(name=="策划")
        {
            serial_number=1;
        }
        else if(name=="美术")
        {
            serial_number=2;
        }
        else if(name=="研发")
        {
            serial_number=3;
        }
    }
};

void init_ten_person_and_department(multimap<int,Person> &mp)
{
    vector<string> department_name={"美术","策划","研发"};
    vector<string> person_name={"A","B","C","D","E","F","G","H","I","J"};
    for(int i=0;i<person_name.size();i++)
    {
        Department d(department_name[rand()%3]);
        Person p(person_name[i],rand()%3001+5000);
        mp.emplace(d.get_serial_number(),p);
    }

}

void show_person_group_by_department(const multimap<int,Person> &mp)
{
    int t=0;
    for(const auto &val:mp)
    {
        if(val.first!=t) cout<<"第"<<val.first<<"组成员"<<endl;
        cout<<val.first<<" "<<val.second.get_name()<<" "<<val.second.get_salary()<<endl;
        t=val.first;
    }
}

void test_1()
{
    multimap<int,Person> mp;
    init_ten_person_and_department(mp);
    show_person_group_by_department(mp);
}

int main()
{
    srand(time(nullptr));
    test_1();
    return 0;
}