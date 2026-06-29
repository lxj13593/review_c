#include<iostream>
using namespace std;

void init_arr()
{
    int a[10];
    a[0]=1;
    cout<<a[0]<<endl;

    int b[10]={1,2,3,4,5,6,7,8,9,10};

    for(int v:b)
    {
        cout<<v<<" ";
    }
    cout<<endl;

    int c[]={1,2,3,4};

    for(int v:c)
    {
        cout<<v<<" ";
    }
    cout<<endl;
}

void arr_name()
{
    int arr[]={41,0,0,0};
    cout<<sizeof(arr)<<endl;
    cout<<&arr[0]<<endl;
}

void reverse_arr()
{
    int a[]={1,2,3,4,5};
    for(int i=0;i<2;i++)
    {
        int t=a[i];
        a[i]=a[5-i-1];
        a[5-i-1]=t;
    }
    for(int v:a)
    {
        cout<<v<<" ";
    }
    cout<<endl;
}

void init_two_arr()
{
    int arr[2][2]={1,2,3,4};
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<arr[i][j]<<' ';
        }
        cout<<endl;
    }
}

void grade_case()
{
    int a[3][3]
    {
        {100,100,100},
        {90,50,100},
        {60,70,80}
    };
    for(int i=0;i<3;i++)
    {
        int sum=0;
        for(int j=0;j<3;j++)
        {
            sum+=a[i][j];
        }
        cout<<sum<<' ';
    }
}

int main()
{
    // init_arr();
    // arr_name();
    // reverse_arr();
    // init_two_arr();
    grade_case();
    return 0;
}
