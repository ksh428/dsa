#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    string p;
	    cin>>p;
	    int hash1[26]={0};
	    int hash2[26]={0};

	    for(int i=0;i<s.size();i++){
	        int index=s[i]-97;
	        hash1[index]++;
	    }
	    for(int i=0;i<p.size();i++){
	        int index=p[i]-97;
	        hash2[index]++;
	    }
	    vector<int> v;
	    for(int i=0;i<26;i++){
	           hash1[i]-=hash2[i];
	           char ch=97+hash1[]
	    }
	    string ans="";
	    int count=0;
	    for(int i=0;i<26;i++){
	         if(p[0]<(hash1[i]+97) && count ==0){
	            ans+=p;
	            ans+=hash1[i]+97;
	            count++;
	        }
	        while(hash1[i]){
	        char ch=97+hash1[i];
	        ans+=ch;
	        hash1[i]--;
	        }
	    }
	    cout<<ans<<endl;

	}
}

