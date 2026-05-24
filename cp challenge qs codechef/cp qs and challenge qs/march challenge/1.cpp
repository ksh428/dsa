#include<bits/stdc++.h>

using namespace std;
int main()
{

    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int f[n];
        int p[n];

        for(int i=0;i<n;i++){
            cin>>f[i];
        }
        for(int i=0;i<n;i++){
            cin>>p[i];
        }

        vector<int>v;
        int a[50]={0};//check for included or not
        int included=0;
        for(int i=0;i<n;i++){
            int s=0;
            int type=f[i];
            if(a[type]==0){
            a[type]=1;
            s+=p[i];
            for(int j=i+1;j<n;j++){
                if(f[j]==type){
                        s+=p[j];

                }else{
                    s=s;
                }
            }
            v.push_back(s);
            }else{
                continue;
            }
        }
        sort(v.begin(),v.end());
        cout<<v[0]<<endl;


    }
}
/*
or we can do
for(int i=0;i<n;i++){
int s=0;
for(int j=0;j<n;j++){
    if(f[i]==f[j]){
    s+=f[j]
    }
}
v.pushback(S);
}
*/
