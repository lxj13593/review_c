#include<iostream>
using namespace std;

void use_pointer()
{
    int a=5;
    int *p;
    p=&a;
    cout<<*p<<endl;
}

void const_pointer_case()
{
    int a,b,c,d;
    a=20,b=30,d=40,c=50;
    const int*p=&a;
    int* const p1=&b;
    const int * const p2=&c;
    // *p=30;
    // p1=&C;
}

void pointer_traverse_array()
{
    int a[]={1,2,3,4,5,6};
    int *p=a;
    for(;p!=a+6;p++)
    {
        cout<<*p<<"　";
    }
    cout<<endl;
}

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void test_swap()
{
    int x,y;
    cin>>x>>y;
    swap(&x,&y);
    cout<<x<<y;
}

void bubble_sort(int *a,int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
}

void print(int *arr,int len)
{
    for(int i=0;i<len;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void test_bubble_sort()
{
    int arr[]={1,9,5,2,6,4,7,2};
    int len=sizeof(arr)/sizeof(arr[0]);
    bubble_sort(arr,len);
    print(arr,len);
}

int main()
{
    // use_pointer();
    // pointer_traverse_array();
    // test_swap();
    // test_bubble_sort();
    return 0;
}
