#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bool possible(string s,int k){ //checks if a k length substr is present in the string
    //USING SLIDING WINDOW TECHNIQUE
    int n=s.size();
    map<int,int>m;
    int f=0,e=0;
    while(e<k){
        m[s[e++]-'0']++;
    }
    if(m[1]>0 && m[2]>0 && m[3]>0) return true;
    while(e<n){
        m[s[e++]-'0']++;
        m[s[f++]-'0']--;
        if(m[1]>0 && m[2]>0 && m[3]>0) return true;

    }
    return false;
}


//OTHER WAY


bool isValid(int k)
{
	int ar[4] = {0};
	for(int i=0;i<k-1;i++)
	{
		int idx = st[i] - '0';
		ar[idx]++;
	}

	for(int i=k-1;i<st.size();i++)
	{
		int idx = st[i] - '0';
		ar[idx]++;

		if((ar[1] > 0) && (ar[2] > 0) && (ar[3] > 0))
		return true;

		idx = st[i-k+1] - '0';
		ar[idx]--;
	}

	return false;
}


int main() {
    int t;
	cin>>t;
	while(t--){
	  string s;
	  cin>>s;
	  int n=s.size();
	  int ans=INT_MAX;
	  int l=3;
	  int r=n;
	  while(l<=r){
	      int m=l+(r-l)/2;
	      if(possible(s,m)){
	          ans=min(ans,m);
	          r=m-1;
	      }else l=m+1;
	  }
	  (ans==INT_MAX)?cout<<0<<endl:cout<<ans<<endl;
	}
}
