
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1000000007
using namespace std;

int main()
{
	int t;
    cin>>t;
    while(t--)
    {
    	int n;
        cin>>n;
        if(n<=5)
        cout<<n*n<<endl;
        else
        {
        	if(n%2)
            {
            	cout<<25+(n-5)*4<<endl;
            }
            else
            cout<<28+(n-6)*4<<endl;
        }
    }
    return 0;
}
