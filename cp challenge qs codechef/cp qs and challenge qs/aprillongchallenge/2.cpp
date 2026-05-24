#include<bits/stdc++.h>
#define m 1000000007
typedef long long ll;
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
  int n;
  cin>>n;
   ll a[n];
  for(int i=0;i<n;i++)
  {
      cin>>a[i];
  }
  //sort(a,a+n);
 // reverse(a,a+n);
  ll sum=0;
  for(int i=0;i<n;i++)
  {
      if(a[i]<=i)
      {
          a[i]=0;
      }
      else
      {
          a[i]-=i;
      }
  }
  for(int i:a)
  {
      sum+=i;
      sum%m;
  }
  cout<<sum%m<<endl;
  }



}
