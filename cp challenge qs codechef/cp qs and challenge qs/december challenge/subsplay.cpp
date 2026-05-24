//GOOD QUESTION ..REVIEW IT
//review this one
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int min=INT_MAX;
        int last[26]={0};//holds the last occurence of the element
        for(int i=0;i<n;i++){
            if (last[s[i]-'a']==0){
                last[s[i]-'a']=i;
            }else{
                int val=i-last[s[i]-'a'];
                last[s[i]-'a']=i;
                if(min>val)
                min=val;
            }

        }
        if(min==0)
        cout<<"0"<<endl;
        else
        {
            min-=1;
            cout<<n-1-min<<endl;
        }
    }

}
