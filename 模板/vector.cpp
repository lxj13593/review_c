#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 打印vector
void print(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

// vector构造函数
void vector_constructor()
{
    cout << "----------vector构造函数----------" << endl;
    vector<int> v1;
    for (int i = 0; i < 5; i++)
    {
        v1.push_back(i);
    }
    vector<int> v2(v1.begin(), v1.end());
    vector<int> v3(v2);
    vector<int> v4(5, 6);
    print(v1);
    print(v2);
    print(v3);
    print(v4);
}

// vector赋值操作
void vector_assign()
{
    cout << "----------vector赋值操作----------" << endl;
    vector<int> v1;
    for (int i = 0; i < 5; i++)
    {
        v1.push_back(i);
    }
    vector<int> v2;
    v2 = v1;
    vector<int> v3;
    print(v1);
    print(v2);
    v3.assign(v2.begin(), v2.end());
    print(v3);
    v3.assign(2, 3);
    print(v3);
}

// vector容量和大小
void vector_capacity_size()
{
    cout << "----------vector容量和大小----------" << endl;
    vector<int> v1;
    cout << v1.empty() << endl;
    for (int i = 0; i < 5; i++)
    {
        v1.push_back(i);
    }
    cout << v1.empty() << endl;
    cout << v1.capacity() << endl;
    cout << v1.size() << endl;
    v1.resize(10);
    print(v1);
}

// vector插入和删除
void vector_insert_erase()
{
    cout << "----------vector插入和删除----------" << endl;
    vector<int> v1;
    for (int i = 0; i < 5; i++)
    {
        v1.push_back(i);
    }
    print(v1);
    v1.pop_back();
    v1.pop_back();
    print(v1);
    v1.insert(v1.begin(), 6);
    print(v1);
    v1.insert(v1.begin(), 6, 3);
    print(v1);
    v1.erase(v1.end());
    print(v1);
    v1.clear();
    print(v1);
}

// vector数据存取
void vector_access()
{
    cout << "----------vector数据存取----------" << endl;
    vector<int> v1;
    for (int i = 0; i < 5; i++)
    {
        v1.push_back(i);
    }
    cout << v1[3] << endl;
    cout << v1.at(2) << endl;
    cout << v1.front() << " " << v1.back() << endl;
}

// vector互换容器
void vector_swap()
{
    cout << "----------vector互换容器----------" << endl;
    vector<int> v1;
    for (int i = 0; i < 5; i++)
    {
        v1.push_back(i);
    }
    vector<int> v2;
    for (int i = 0; i < 5; i++)
    {
        v2.push_back(i * 2);
    }
    print(v1);
    print(v2);
    v1.swap(v2);
    print(v1);
    print(v2);
}

// vector预留空间
void vector_reserve()
{
    cout << "----------vector预留空间----------" << endl;
    vector<int> v;

    // 预留空间
    // v.reserve(100000);

    int num = 0;
    int *p = NULL;
    for (int i = 0; i < 100000; i++)
    {
        v.push_back(i);
        if (p != &v[0])
        {
            p = &v[0];
            num++;
        }
    }

    cout << "num:" << num << endl;
}

int main()
{
    vector_constructor();
    vector_assign();
    vector_capacity_size();
    vector_insert_erase();
    vector_access();
    vector_swap();
    vector_reserve();
    return 0;
}
