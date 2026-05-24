#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        int flag=0;
        cin>>n;
        int a[n];
        int c=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]==1)
                c++;
        }
        if(n==1)
        cout<<"YES"<<endl;
        else if(n<6)
        {
           if(c==1)
                cout<<"YES"<<endl;
           else
            cout<<"NO"<<endl;
        }
        else{
            if(c==1)
                cout<<"YES"<<endl;
            else
            {
                for(int i=0;i<n;i++)
                {
                    if(a[i]==1)
                    {
                        int j=i+1;
                        while(j<n && j<(i+7))
                        {
                            if(a[j]==1)
                               {
                                   flag++;
                                   break;
                               }
                        }
                        if(flag>0)
                            break;

                    }
                }
                if(flag>0)
                    cout<<"NO"<<endl;
                else
                    cout<<"YES"<<endl;
            }
        }
}
}






