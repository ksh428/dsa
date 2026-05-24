#include<bits/stdc++.h>
using namespace std;
int main()
{
    set<int>s;
    int x;
    int n;
    cin>>n;
    cin>>x;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        s.insert(a[i]);
    }
    auto it =s.lower_bound(x);
    int m=*it;
    it++;
    int c=*it;
    if((x-m)>(c-x))
        cout<<c;
    else if((x-m)==(c-x))
        cout<<m<<" "<<c;
    else cout<<m;




}
