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
using vector_int=vector<int>;

void test_using()
{
    cout << "using 类型别名练习" << endl;
    // TODO: using alias practice
    vector_int v1(10,5);
    v1.push_back(4);
    for_each(v1.begin(),v1.end(),[](int val){cout<<val<<"";});
    cout<<endl;
    
}

int main()
{
    test_using();
    return 0;
}
