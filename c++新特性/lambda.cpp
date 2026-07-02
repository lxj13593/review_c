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

void test_lambda()
{
    cout << "lambda 表达式练习" << endl;
    // TODO: lambda practice
    vector<int> v1{10,7,6,9,8,4,1,2,3};
    sort(v1.begin(),v1.end(),[](int a,int b){return a>b;});
    for_each(v1.begin(),v1.end(),[](int a){cout<<a<<" ";});
    cout<<endl;
    auto it=find_if(v1.begin(),v1.end(),[](int a){return a>5;});
    cout<<*it<<endl;
}

int main()
{
    test_lambda();
    return 0;
}
