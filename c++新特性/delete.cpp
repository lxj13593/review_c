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
    Person(const Person &p)=delete;
    Person& operator=(const Person &p)=delete;
};

void test_delete()
{
    cout << "delete 练习" << endl;
    // TODO: delete practice
}

int main()
{
    test_delete();
    return 0;
}
