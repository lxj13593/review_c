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

template<class T>
T max_(T a,T b)
{
    return a>b?a:b;
}

void max_test()
{
    int a=max_<int>(3,5);
    cout<<a<<endl;
}

void test_unique_ptr()
{
    cout << "unique_ptr 练习" << endl;
    unique_ptr<int> p=make_unique<int>(8);
    unique_ptr<int> p2=move(p);
    if(p!=nullptr)
    {
        cout<<*p<<endl;
    }
    if(p2!=nullptr)
    {
        cout<<*p2<<endl;
    }
    // TODO: unique_ptr practice
}

void test_shared_ptr()
{
    cout << "shared_ptr 练习" << endl;
    shared_ptr<int> s=make_shared<int>(5);
    shared_ptr<int> s1=s;
    shared_ptr<int> s2=s1;
    shared_ptr<int> s3=s;
    cout<<s1.use_count()<<endl;
    // TODO: shared_ptr practice
}

void test_weak_ptr()
{
    cout << "weak_ptr 练习" << endl;
    // TODO: weak_ptr practice
}

int main()
{
    max_test();
    test_unique_ptr();
    test_shared_ptr();
    test_weak_ptr();
    return 0;
}
