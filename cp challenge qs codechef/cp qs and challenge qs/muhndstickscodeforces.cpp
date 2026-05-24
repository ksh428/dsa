#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[10]={0};
    int b[6];
    for(int i=0;i<6;i++)
    {
        cin>>b[i];
    }
    for(int i=0;i<10;i++)
    {
        a[b[i]]++;
    }
    sort(b,b+10);
    if(b[5]>=4)
    {
        if(b[4]==0)
            cout<<"Elephant"<<endl;
        else if(b[4]==1)
            cout<<"Bear"<<endl;
        else if(b[4]==1)
            cout<<"Bear"<<endl;
        else if(b[4]==2)
            cout<<"Elephant"<<endl;
    }
    else
        cout<<"Alien"<<endl;

}
