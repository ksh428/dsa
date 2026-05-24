//GOOD QUESTION
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
       // vector<int>v;
        cin>>n>>k;
        int a[n+1];
        for(int i=1;i<=n;i++) // 1 based indexing
        {
            cin>>a[i];
        }
        for(int i=1;i<=k;i++)
        {
            vector<int>v; // create vector for each set
            for(int j=i;j<=n;j+=k)
                v.push_back(a[j]); // extract value of the array to vector
            sort(v.begin(),v.end()); // sort all the possible set
            int vindex=0;
            for(int j=i;i<=n;j+=k) // inserting values back from where it was extracted
            {
                a[j]=v[vindex++];
            }
        }
        int flag=0; // check if a and b are equal
       for(int i=1;i<=n;i++)
       {
           if(a[i]<a[i-1])
           {
               flag=1;
               break;

           }
            else
            flag=flag;
       }
       if(flag)
        cout<<"no"<<endl;
        else cout<<"yes"<<endl;


    }
}
