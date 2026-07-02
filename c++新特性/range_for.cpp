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

void test_range_for()
{
    cout << "范围 for 练习" << endl;
    // TODO: range for practice
    //只读
    vector<int> v1{1,2,3,4,5,6,7,8,9};
    for(const auto& it:v1)
    {
        cout<<it<<' ';
    }
    cout<<endl;
    //修改
    vector<int> v2{1,2,3,4,5,6,7,8,9};
    for(auto& it:v2)
    {
        it=it+1;
    }
    for(auto& it:v2)
    {
        cout<<it<<' ';
    }
    cout<<endl;
}

int main()
{
    test_range_for();
    return 0;
}
