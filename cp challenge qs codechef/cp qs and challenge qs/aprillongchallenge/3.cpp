// concept :
// number of integers in PF of x >=k
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll countprime(ll n)
{
    int c=0;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {
                c++;
                n/=i;
            }
        }
    }
    return c +(n>1); // if N>1 then we need to count 1 also. if n>1 n is added to c

}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll x,k;
        cin>>x>>k;
       if(countprime(x)>=k)
        cout<<1<<endl;
       else cout<<0<<endl;
    }
}
