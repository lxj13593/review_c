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

void test_auto()
{
    cout << "auto 练习" << endl;
    // TODO: auto practice
    vector<int> v{1,5,6,9,98};
    auto it=v.begin();
    it=it+3;
    cout<<*it<<endl;
}

int main()
{
    test_auto();
    return 0;
}
