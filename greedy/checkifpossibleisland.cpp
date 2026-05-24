


#include <bits/stdc++.h>

using namespace std;

int main()
{
   int m,n,s;  //m:req/day   n:buy/day   s:no of days to surrvive
   cin>>s>>n>>m;
   int x=s/7;
   int y=s-x;
   int sm=s*m;
   int d=sm/n;
   if(sm%n!=0) d++;
   if(d<=y) cout<<"1";
   else cout<<"0";
}
