#include<iostream>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int s=0;
    s+=a;
    while(a>=b)
    {
        s+=a/b;
        a=(a/b) +(a%b);
    }
    cout<<s<<endl;
}
