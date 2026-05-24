#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,s;
        cin>>n>>s;
        int price[n],player[n];
        for(int i=0;i<n;i++)
        {
            cin>>price[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>player[i];

        }
        vector<int>vd;
        //vector<int>vf;
        for(int i=0;i<n;i++)
        {
            if(player[i]==0)
                vd.push_back(price[i]);
           // else
               // vf.push_back(price[i]);
        }
        sort(vd.begin(),vd.end());
       // sort(vf.begin(),vf.end());
        int a=vd[0];
        //int b=vf[0];
        int flag=0;
        for(int i=0;i<n;i++)
        {
            if(player[i]==1)
            {
                if((price[i]+a+s)<=100)
                {
                    flag=1;
                    break;
                }
            }
        }
        if(flag)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;





    }
}
