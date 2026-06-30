#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print_vector(const vector<int> &v)
{
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// 4.1.1 函数对象概念
class MyAdd
{
public:
    int operator()(int a, int b)
    {
        return a + b;
    }
};

void function_object_overview()
{
    cout << "----------4.1.1 函数对象概念----------" << endl;
    MyAdd my_add;
    cout << my_add(10, 20) << endl;
    cout << MyAdd()(100, 200) << endl;
}

// 4.1.2 函数对象使用
class MyPrint
{
private:
    int count;

public:
    MyPrint() : count(0) {}

    void operator()(const string &text)
    {
        cout << text << endl;
        count++;
    }

    int get_count() const
    {
        return count;
    }
};

void function_object_use()
{
    cout << "----------4.1.2 函数对象使用----------" << endl;
    MyPrint my_print;
    my_print("hello");
    my_print("world");
    cout << "调用次数:" << my_print.get_count() << endl;
}

// 4.2.1 谓词概念
class GreaterThanFive
{
public:
    bool operator()(int value)
    {
        return value > 5;
    }
};

void predicate_overview()
{
    cout << "----------4.2.1 谓词概念----------" << endl;
    GreaterThanFive predicate;
    cout << predicate(3) << endl;
    cout << predicate(8) << endl;
}

// 4.2.2 一元谓词
void unary_predicate()
{
    cout << "----------4.2.2 一元谓词----------" << endl;
    vector<int> v = {1, 3, 5, 7, 9};
    auto it = find_if(v.begin(), v.end(), GreaterThanFive());
    if (it != v.end())
    {
        cout << "找到大于5的数:" << *it << endl;
    }
}

// 4.2.3 二元谓词
class MyCompare
{
public:
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

void binary_predicate()
{
    cout << "----------4.2.3 二元谓词----------" << endl;
    vector<int> v = {10, 30, 20, 50, 40};
    sort(v.begin(), v.end(), MyCompare());
    print_vector(v);
}

// 4.3.1 内建函数对象意义
void builtin_function_object_meaning()
{
    cout << "----------4.3.1 内建函数对象意义----------" << endl;
    plus<int> my_plus;
    cout << my_plus(10, 20) << endl;
}

// 4.3.2 算术仿函数
void arithmetic_functor()
{
    cout << "----------4.3.2 算术仿函数----------" << endl;
    negate<int> n;
    plus<int> p;
    cout << n(50) << endl;
    cout << p(10, 20) << endl;
}

// 4.3.3 关系仿函数
void relational_functor()
{
    cout << "----------4.3.3 关系仿函数----------" << endl;
    vector<int> v = {10, 30, 20, 50, 40};
    sort(v.begin(), v.end(), greater<int>());
    print_vector(v);
}

// 4.3.4 逻辑仿函数
void logical_functor()
{
    cout << "----------4.3.4 逻辑仿函数----------" << endl;
    vector<bool> v = {true, false, true, false};
    vector<bool> v2;
    v2.resize(v.size());
    transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());

    for (auto it = v2.begin(); it != v2.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    function_object_overview();
    function_object_use();
    predicate_overview();
    unary_predicate();
    binary_predicate();
    builtin_function_object_meaning();
    arithmetic_functor();
    relational_functor();
    logical_functor();
    return 0;
}
