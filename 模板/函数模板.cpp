#include<iostream>
using namespace std;

template<class T>
void swap(T &a,T &b)
{
    T temp=a;
    a=b;
    b=temp;
}

template<class T>
void select_sort(T *a,int len)
{
    for(int i=0;i<len-1;i++)
    {
        T max=a[i];
        int t=i;
        for(int j=i+1;j<len;j++)
        {
            if(a[j]>max)
            {
                max=a[j];
                t=j;
            }
        }
        if(t!=i)
        {
            swap(a[i],a[t]);
        }
    }
}

template<class T>
void print(T *a,int len)
{
    for(int i=0;i<len;i++)
    {
        cout<<(int)a[i]<<" ";
    }
    cout<<endl;
}

void test_1()
{
    char a[]={5,2,3,69,4,1,25};
    int b[]={5,9,6,3,2,1,4,7,8};
    int len1=sizeof(a)/sizeof(a[0]);
    int len2=sizeof(b)/sizeof(b[0]);
    select_sort(a,len1);
    select_sort(b,len2);
    print(a,len1);
    print(b,len2);
}

int main()
{
    test_1();
    return 0;
}