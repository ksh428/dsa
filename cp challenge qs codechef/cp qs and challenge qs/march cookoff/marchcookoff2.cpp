#include<bits/stdc++.h>
#include<map>
#include<string.h>
#include<vector>
#include<algorithm>
#define ll long long int
#define nl "\n"
#define mod 1000000007
#define db double
#define mp make_pair
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
cin.tie(NULL);
    cout.tie(NULL);

   int t;
   cin>>t;
   while(t--)
   {
      ll n,i,f,l;
      cin>>n;
      ll a[n];
      for(ll i=0;i<n;i++)
        cin>>a[i];
      ll m=*max_element(a,a+n);
      for(i=0;i<n;i++)
      {
          if(a[i]==m)
          {
             f=i;
             break;
          }
      }
      for(i=n-1;i>=0;i--)
      {
          if(a[i]==m)
          {
              l=i;
              break;
          }
      }
      if(l-f>=n/2)
      {
          cout<<0<<nl;
          continue;
      }
      else
      {
          ll index=n/2-f;
          cout<<n-1-l-index+1<<nl;
      }
   }
}
