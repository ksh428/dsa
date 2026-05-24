#include<bits/stdc++.h>
using namespace std;
int divbyfour(int a[])
{
    //a[] =1 2 3 6 4 2
    int c=0,res=0;
    vector<int>v;
    for(int i=0;i<6;i++)
    {
        if(a[i]%2==0)
            {
                v.push_back(a[i]);
            }
    }
    for(int x:v)
    {
        cout<<x;
    }
}
int main()
{
   /* int a[]={1,3,2,4,5,7};
    int c=0,res=0;
    for(int i=0;i<6;i++)
    {
        if(a[i]%2==1)
        {
            c++;
        }
        else
        {
           // d++;
            res+=c*(c+1)/2;
            c=0;
        }
    }
    res+=c*(c+1)/2;
    cout<<res; */
    int a[]={1,2,3,6,4,2};
    divbyfour(a);

}
