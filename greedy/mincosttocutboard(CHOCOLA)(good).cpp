

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n;
        m--;n--;
        int x[m],y[n];
        for(int i=0;i<m;i++) cin>>x[i];
        for(int j=0;j<n;j++) cin>>y[j];
        sort(x,x+m,greater<int>());
        sort(y,y+n,greater<int>());
        int hor_cnt=1;
        int ver_cnt=1;
        int ans=0;
        int i=0,j=0;
        while(i<m and j<n){
            if(x[i]>y[j]){
                ans+=x[i]*ver_cnt;
                hor_cnt++;
                i++;
            }else{
                ans+=y[j]*hor_cnt;
                ver_cnt++;
                j++;
            }
        }
        while(i<m){
            ans+=x[i]*ver_cnt;
            i++;
        }
        while(j<n){
            ans+=y[j]*hor_cnt;
            j++;
        }
        cout<<ans<<endl;
    }
}

