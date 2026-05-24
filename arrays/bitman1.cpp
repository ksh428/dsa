#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int c=0;
    for(int i=0;i<=n;i++)
    {
        if((n+i)==(i^n))
            c++;



    }
    cout<<c<<endl;

}
