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
    Person()=default;
    Person(const Person &p)=default;
};

void test_default()
{
    cout << "default 练习" << endl;
    // TODO: default practice
}

int main()
{
    test_default();
    return 0;
}
