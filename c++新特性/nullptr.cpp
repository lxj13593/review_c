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

void test_nullptr()
{
    cout << "nullptr 练习" << endl;
    // TODO: nullptr practice
    int a=5;
    int *p=&a;
    if(p!=nullptr)
    {
        cout<<*p<<endl;
    }
}

int main()
{
    test_nullptr();
    return 0;
}
