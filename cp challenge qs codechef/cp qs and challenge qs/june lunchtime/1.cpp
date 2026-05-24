#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,s;
	    cin>>s>>n;
	    if(s==n)
	    cout<<"1"<<endl;
	    else if(s<n){
	        if(s&1){
	            if(s==1)
	            cout<<"1"<<endl;
	            else{
	                cout<<"2"<<endl;
	            }
	        }else{
	            cout<<"1"<<endl;
	        }
	    }else{
	        int ans=0;
	        ans+=s/n;
	        int diff=s-(s/n)*n;
	        if(diff==0){
	            ans=ans;
	        }else if(diff&1 && diff!=1){
	            ans+=2;
	        }else if(diff==1){
	            ans+=1;
	        }
	        else{
	            ans++;
	        }
	        cout<<ans<<endl;
	    }



	}
}
