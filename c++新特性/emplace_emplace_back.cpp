#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

class Person
{
private:
    string name;
    int age;

public:
    Person() = default;
    Person(string name, int age) : name(name), age(age) {}
    // Person(const Person &p) = delete;
    // Person &operator=(const Person &p) = delete;
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
};

void test_emplace()
{
    cout << "emplace / emplace_back 练习" << endl;
    // TODO: emplace / emplace_back practice
    vector<Person> v1;
    v1.emplace_back("a", 18);
    v1.emplace_back("c", 13);
    v1.emplace_back("b", 16);
    for_each(v1.begin(), v1.end(), [](const Person &p)
             { cout << p.get_name() << " " << p.get_age() << endl; });
}

int main()
{
    test_emplace();
    return 0;
}
