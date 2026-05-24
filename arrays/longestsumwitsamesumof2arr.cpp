#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    int maxlength=0;
    for(int i=0;i<n;i++)
    {
        int s1=0,s2=0;
        for(int j=i;j<n;j++)
        {

            s1+=a[j];
            s2+=b[j];
            if(s1==s2)
            {
                int len=j-i+1;
                if(len>maxlength)
                    maxlength=len;
            }
        }
    }
    cout<<maxlength;

}
