#include<iostream>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--)
    {
        string s1,s2;cin>>s1>>s2;
        int a[3]={0};
        for(int i=0;i<3;i++)
        {
            if(s1[i]=='b' || s2[i]=='b')
            {
                a[i]=1;
            }
        }
        int bc=0;
        for(int i=0;i<3;i++)
        {
            if(a[i]==1)
                bc++;
        }
        if(bc<=1)
            cout<<"no"<<endl;
        else if(bc==2)
        {
            int index=0;
            for(int j=0;j<3;j++)
            {
                if(a[j]==0)
                {
                    index=j;
                }
            }
            if(s1[index]=='o'||s2[index]=='o')
            {
                cout<<"yes"<<endl;
            }
            else
                cout<<"no"<<endl;
        }
        else if(bc==3)
        {
            int oc=0;
            for(int i=0;i<3;i++)
            {
                if(s1[i]=='o'||s2[i]=='o')
                    oc++;
            }
            if(oc>0)
                cout<<"yes"<<endl;
            else
                cout<<"no"<<endl;
        }

    }
}
