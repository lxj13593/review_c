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

class Animal
{
public:
    virtual void show()=0;
    virtual ~Animal() {}
};

class Dog:public Animal
{
public:
    void show() override
    {
        cout<<"小狗"<<endl;
    }
};

void test_override()
{
    cout << "override 练习" << endl;
    // TODO: override practice
    Dog d;
    Animal &a=d;
    a.show();
}

int main()
{
    test_override();
    return 0;
}
