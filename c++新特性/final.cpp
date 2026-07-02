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

class Animal final
{

};

// 这样其他类不能再继承 `Animal`。

class Animal1
{
public:
    virtual void speak()
    {
    }
};

class Cat : public Animal1
{
public:
    void speak() final
    {
    }
};

// `Cat` 的子类不能再重写 `speak()`。

void test_final()
{
    cout << "final 练习" << endl;
    // TODO: final practice
    // `final` 可以禁止类被继承，或者禁止虚函数继续被重写
    
}

int main()
{
    test_final();
    return 0;
}
