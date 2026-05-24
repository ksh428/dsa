#include<bits/stdc++.h>
using namespace std;
int main()
{
    int s,n,m;
    cin>>s>>n>>m;
    if(m>n)
        cout<<"No"<<endl;
    else{
        int av=n/m;
        int rem=s-av;
        int c=1;
        while(rem>0)
        {
            c++;
            rem/=m;
        }
        cout<<"Yes"<<c<<endl;
    }
}
