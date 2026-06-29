#include <iostream>
#include <vector>

using namespace std;


// vector构造函数
void vector_constructor()
{
    cout << "----------vector构造函数----------" << endl;
    
}


// vector赋值操作
void vector_assign()
{
    cout << "----------vector赋值操作----------" << endl;
}


// vector容量和大小
void vector_capacity_size()
{
    cout << "----------vector容量和大小----------" << endl;
}


// vector插入和删除
void vector_insert_erase()
{
    cout << "----------vector插入和删除----------" << endl;
}


// vector数据存取
void vector_access()
{
    cout << "----------vector数据存取----------" << endl;
}


// vector互换容器
void vector_swap()
{
    cout << "----------vector互换容器----------" << endl;
}


// vector预留空间
void vector_reserve()
{
    cout << "----------vector预留空间----------" << endl;
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
