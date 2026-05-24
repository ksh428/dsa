#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    if(n>m)
    cout<<(n-m)<<endl;
    else
    {
        int c=0;
        while(m>n)
        {
            if(m%2==0)
            {
                m/=2;c++;
            }
            else
            {
                m++;c++;


            }
        }
       cout<<c+(n-m)<<endl;

    }

}
