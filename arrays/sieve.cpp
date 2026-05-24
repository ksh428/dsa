#include<bits/stdc++.h>
using namespace std;
int sieve(int p[ ],int n)
{
    // mark odd nos 1 as they may be prime and as all even nos except 2 are non prime
    for(int i=3;i<=n;i+=2)
    {
        p[i]=1;
    }
    //sieve
    for(int i=3;i<=n;i+=2)
    {
        if(p[i]==1)// if no is odd
        {
            for(int j=i*i;j<=n;j+=i)
            {
                p[j]=1;
            }
        }
    }
    p[0]=p[1]=1;
    p[2]=0;
    for(int i=0;i<=n;i++)
    {
        if(p[i]==1)
            cout<<i<<"\n";
    }
}
int main()
{
    int n;
    cin>>n;
    int p[n]={0};
    sieve(p,n);

}
