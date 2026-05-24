#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void initialize(int a[],int n)
{
  for(int i=0;i<n;i++)
    a[i]=INT_MAX;
}

int main()
{
  int t,n,m,k,i,j,price;
  cin>>t;
  while(t--)
  {
    cin>>n>>m>>k;
    int COST[m];
    initialize(COST,m);
    for(i=0;i<n;i++)
    {
      for(j=0;j<m;j++)
      {
        cin>>price;
        if(price<COST[j])
          COST[j]=price;
      }
    }
    sort(COST,COST+n);
    int s=0,c=0;
    for(int i=0;i<m;i++)
    {
        s+=COST[i];
        c++;
        if(s>k)
        {
            break;
        }

    }
    cout<<c<<endl;
  }
}

