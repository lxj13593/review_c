#include<iostream>

using namespace std;

void heap_array()
{
    int *a=new int[10]{1,2,3,4,5,6,7,8,9,10};
    for(int i=0;i<10;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    delete[] a;
}

int fun_default_value(int a,int b=20)
{
    return a+b;
}

void test_fun_default_value()
{
    int a,b;
    int c=fun_default_value(10);
    cout<<c<<endl;
}

int main()
{
    // heap_array();
    test_fun_default_value();
    return 0; 
}