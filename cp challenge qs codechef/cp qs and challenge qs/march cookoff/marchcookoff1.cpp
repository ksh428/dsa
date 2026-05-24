#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,test,j;
    cin>>test;
    while(test-->0)
    {
        int n,X=0,Y=0;
        cin>>n;
        char s[n],p1=NULL;
        for(i=0;i<n;i++)
        cin>>s[i];
        for(i=0;i<n;i++)
        {
            if(s[i]=='L' && p1!='L'&&p1!='R')
            X--;
            else if(s[i]=='R' && p1!='L'&&p1!='R')
            X++;
            else if(s[i]=='U' && p1!='D'&&p1!='U')
            Y++;
            else if(s[i]=='D' && p1!='D'&&p1!='U')
            Y--;
            p1=s[i];
        }
        cout<<X<<" "<<Y<<endl;
    }
    return 0;

}
