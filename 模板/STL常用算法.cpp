#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <functional>
#include <random>
#include <set>
using namespace std;

class MyPrint
{
public:
    void operator()(int val)
    {
        cout << val << " ";
    }
};

class MyVal
{
public:
    int operator()(int val)
    {
        return val;
    }
};

// 5.1.1 for_each
void algorithm_for_each()
{
    cout << "----------5.1.1 for_each----------" << endl;
    vector<int> v1 = {1, 5, 2, 3, 6, 4};
    for_each(v1.begin(), v1.end(), MyPrint());
    cout << endl;
}

// 5.1.2 transform
void algorithm_transform()
{
    cout << "----------5.1.2 transform----------" << endl;
    vector<int> v1 = {1, 5, 2, 3, 6, 4};
    vector<int> v2;
    v2.resize(v1.size());
    transform(v1.begin(), v1.end(), v2.begin(), MyVal());
    for_each(v2.begin(), v2.end(), MyPrint());
    cout << endl;
}

// 5.2.1 find
void algorithm_find()
{
    cout << "----------5.2.1 find----------" << endl;
    vector<int> v1 = {1, 5, 2, 3, 4, 6};
    auto it = find(v1.begin(), v1.end(), 5);
    if (it != v1.end())
    {
        cout << *it << endl;
    }
}

class Person
{
private:
    string name;
    int age;

public:
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
    Person(string name, int age) : name(name), age(age)
    {
    }
};

class GreaterFive
{
public:
    bool operator()(int val)
    {
        return val > 5;
    }
};

class GreaterTwenty
{
public:
    bool operator()(Person &p)
    {
        return p.get_age() > 20;
    }
};

void test_1()
{
    vector<int> v{2, 5, 6, 8, 9, 4};
    auto it = find_if(v.begin(), v.end(), GreaterFive());
    if (it != v.end())
    {
        cout << *it << endl;
    }
}

void test_2()
{
    vector<Person> v1;
    v1.push_back(Person("a", 18));
    v1.push_back(Person("b", 21));
    v1.push_back(Person("c", 23));
    v1.push_back(Person("d", 50));
    auto it = find_if(v1.begin(), v1.end(), GreaterTwenty());
    if (it != v1.end())
    {
        cout << (*it).get_age() << endl;
    }
}

// 5.2.2 find_if
void algorithm_find_if()
{
    cout << "----------5.2.2 find_if----------" << endl;
    test_1();
    test_2();
}

// 5.2.3 adjacent_find
void algorithm_adjacent_find()
{
    cout << "----------5.2.3 adjacent_find----------" << endl;
    vector<int> v1{5, 2, 3, 3, 6, 8};
    auto it = adjacent_find(v1.begin(), v1.end());
    if (it != v1.end())
    {
        cout << *it << endl;
    }
}

// 5.2.4 binary_search
void algorithm_binary_search()
{
    cout << "----------5.2.4 binary_search----------" << endl;
    vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto it = binary_search(v1.begin(), v1.end(), 6);
    cout << it << endl;
}

// 5.2.5 count
void algorithm_count()
{
    cout << "----------5.2.5 count----------" << endl;
    vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8, 9, 5, 5, 5, 5};
    cout << count(v1.begin(), v1.end(), 5) << endl;
}

// 5.2.6 count_if
void algorithm_count_if()
{
    cout << "----------5.2.6 count_if----------" << endl;
    vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8, 9, 5, 5, 5, 5};
    cout << count_if(v1.begin(), v1.end(), GreaterFive()) << endl;
}

class MyCompare
{
public:
    bool operator()(int val1, int val2)
    {
        return val1 > val2;
    }
};

// 5.3.1 sort
void algorithm_sort()
{
    cout << "----------5.3.1 sort----------" << endl;
    vector<int> v1{5, 6, 9, 84, 2, 1, 4, 5};
    sort(v1.begin(), v1.end());
    sort(v1.begin(), v1.end(), MyCompare());
    for_each(v1.begin(), v1.end(), MyPrint());
    cout << endl;
}

// 5.3.2 random_shuffle
void algorithm_random_shuffle()
{
    cout << "----------5.3.2 random_shuffle----------" << endl;
    vector<int> v1{5, 6, 9, 84, 2, 1, 4, 5};
    shuffle(v1.begin(), v1.end(), default_random_engine(time(nullptr)));
    for_each(v1.begin(), v1.end(), MyPrint());
    cout << endl;
}

// 5.3.3 merge
void algorithm_merge()
{
    cout << "----------5.3.3 merge----------" << endl;
    set<int> s1{5, 6, 4, 1, 2, 3};
    set<int> s2{9, 8, 7, 4, 5, 1, 2};
    set<int> s3;
    for_each(s1.begin(), s1.end(), MyPrint());
    cout << endl;
    for_each(s2.begin(), s2.end(), MyPrint());
    cout << endl;
    merge(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s3, s3.begin()));
    for_each(s3.begin(), s3.end(), MyPrint());
    cout << endl;
}

// 5.3.4 reverse
void algorithm_reverse()
{
    cout << "----------5.3.4 reverse----------" << endl;
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
    reverse(v.begin(), v.end());
    for_each(v.begin(), v.end(), MyPrint());
    cout << endl;
}

// 5.4.1 copy
void algorithm_copy()
{
    cout << "----------5.4.1 copy----------" << endl;
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> v1;
    v1.resize(v.size());
    copy(v.begin(), v.end(), v1.begin());
    for_each(v1.begin(), v1.end(), MyPrint());
    cout << endl;
}

// 5.4.2 replace
void algorithm_replace()
{
    cout << "----------5.4.2 replace----------" << endl;
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
    replace(v.begin(), v.end(), 4, 10);
    for_each(v.begin(), v.end(), MyPrint());
    cout << endl;
}

// 5.4.3 replace_if
void algorithm_replace_if()
{
    cout << "----------5.4.3 replace_if----------" << endl;
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
    replace_if(v.begin(), v.end(), GreaterFive(), 10);
    for_each(v.begin(), v.end(), MyPrint());
    cout << endl;
}

// 5.4.4 swap
void algorithm_swap()
{
    cout << "----------5.4.4 swap----------" << endl;
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> v1{5, 6, 9, 10};
    for_each(v.begin(), v.end(), MyPrint());
    cout << endl;
    for_each(v1.begin(), v1.end(), MyPrint());
    cout << endl;
    swap(v1, v);
    for_each(v.begin(), v.end(), MyPrint());
    cout << endl;
    for_each(v1.begin(), v1.end(), MyPrint());
    cout << endl;
}

// 5.5.1 accumulate
void algorithm_accumulate()
{
    cout << "----------5.5.1 accumulate----------" << endl;
    vector<int> v1;
    v1.resize(10);
    fill(v1.begin(), v1.end(), 10);
    int a = accumulate(v1.begin(), v1.end(), 0);
    cout << a << endl;
}

// 5.5.2 fill
void algorithm_fill()
{
    cout << "----------5.5.2 fill----------" << endl;
    vector<int> v1;
    v1.resize(10);
    fill(v1.begin(), v1.end(), 10);
    int a = accumulate(v1.begin(), v1.end(), 0);
    cout << a << endl;
}

// 5.6.1 set_intersection
void algorithm_set_intersection()
{
    cout << "----------5.6.1 set_intersection----------" << endl;
    vector<int> v1 = {23, 87, 14, 56, 91, 35, 68, 42, 7, 76};
    vector<int> v2 = {12, 64, 99, 31, 56, 80, 3, 58, 72, 26};
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    vector<int> v3;
    v3.resize(v1.size()+v2.size());
    auto it=set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());
    for_each(v3.begin(),it,MyPrint());
    cout<<endl;
}

// 5.6.2 set_union
void algorithm_set_union()
{
    cout << "----------5.6.2 set_union----------" << endl;
    vector<int> v1 = {23, 87, 14, 56, 91, 35, 68, 42, 7, 76};
    vector<int> v2 = {12, 64, 99, 56, 45, 80, 3, 58, 72, 26};
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    vector<int> v3;
    v3.resize(v1.size()+v2.size());
    auto it=set_union(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());
    for_each(v3.begin(),it,MyPrint());
    cout<<endl;
}

// 5.6.3 set_difference
void algorithm_set_difference()
{
    cout << "----------5.6.3 set_difference----------" << endl;
    vector<int> v1 = {23, 87, 14, 56, 91, 35, 68, 42, 7, 76};
    vector<int> v2 = {12, 64, 99, 31, 45, 80, 3, 58, 72, 26};
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    vector<int> v3;
    v3.resize(v1.size()+v2.size());
    auto it=set_difference(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());
    for_each(v3.begin(),it,MyPrint());
    cout<<endl;
}

int main()
{
    algorithm_for_each();
    algorithm_transform();
    algorithm_find();
    algorithm_find_if();
    algorithm_adjacent_find();
    algorithm_binary_search();
    algorithm_count();
    algorithm_count_if();
    algorithm_sort();
    algorithm_random_shuffle();
    algorithm_merge();
    algorithm_reverse();
    algorithm_copy();
    algorithm_replace();
    algorithm_replace_if();
    algorithm_swap();
    algorithm_accumulate();
    algorithm_fill();
    algorithm_set_intersection();
    algorithm_set_union();
    algorithm_set_difference();
    return 0;
}
