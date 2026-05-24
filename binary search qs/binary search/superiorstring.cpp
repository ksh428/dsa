#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        string s;
        cin>>n;
        cin>>s;
        char ch='';
        int c=0;

        // create prefix array for every array element
       int pref[n]={0};
        for(int i=0;i<26;i++)
        {
            int c=0;
            for(int j=0;j<n;j++)
            {
                if(s[j]-'a'==i)
                    c++;
                    pref[j]=c;

           }
           // create the 2 arrays
           vector<int>L;
           vector<int>R;
           for(int j=0;j<n;j++)
           {
               L.push_back((2*pref[j-1])-j);
               R.push_back((2*pref[j])-j);
           }

        }


    }
}
