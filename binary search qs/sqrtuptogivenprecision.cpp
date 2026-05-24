
#include <bits/stdc++.h>

using namespace std;

//double eps=1e-6;//for precision upto 5 decimal places
//for precision upto p places use 1e-(p+1)

int main()
{
   double x;
   int p;
   cin>>p;//precisoon
   cin>>x;
   double eps=pow(10,-(p+1));
   cout<<eps;
   double l=1,h=x,mid;
   while(h-l>eps){
       mid=(l+h)/2;
       if(mid*mid<x) {
           l=mid;
       }else h=mid;
   }
   cout<<l;
}

