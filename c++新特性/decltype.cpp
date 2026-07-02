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
#include <typeinfo>
using namespace std;

void test_decltype()
{
    cout << "decltype 练习" << endl;
    // TODO: decltype practice
    int a=10;
    decltype(a) b=10;
    cout<<typeid(b).name()<<endl;
}

int main()
{
    test_decltype();
    return 0;
}
