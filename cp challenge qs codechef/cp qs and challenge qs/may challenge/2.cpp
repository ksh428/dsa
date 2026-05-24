#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,q,c;
        cin>>n>>q;
        string s;
        cin>>s;
        int a[26]={0};
        for(int i=0;i<s.size();i++){
            int index=s[i]-97;
            a[index]++;
        }
        for(int i=0;i<q;i++){
            cin>>c;
            if(c==0){
                cout<<s.size()<<endl;

            }else{
                int ans=0;

                for(int i=0;i<26;i++){
                        if(a[i]>0){
                        a[i]-=c;
                            if(a[i]>0){
                                ans+=a[i];
                        }
                        }

                }
                cout<<ans<<endl;
            }

        }

    }
}
