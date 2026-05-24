#include<iostream>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--)
    {
        string s1,s2;
        cin>>s1>>s2;
        int a[26]={0} ;int b[26]={0};
        int k=int(s1.size());
        for(int i=0;i<k;i++)
        {
           /* char x=s1[i];
            int p= int x;
            int in=p-97;
            a[in]++;
            char x1=s2[i];
            int p1=int x1;
            int in1= p1-97;
            b[in1]++; */
            int x=s1[i]-97;
            a[x]++;
            int y=s2[i]-97;
            b[y]++;
    }
    int c=0;
    for(int j=0;j<26;j++)
    {
        if(a[j]!=b[j])
            c++;
    }
    if(c>1)
        cout<<"no";
    else
        cout<<"yes";
}
}
