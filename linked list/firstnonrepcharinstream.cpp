class Solution {
	public:
		string FirstNonRepeating(string a){
		    // Code here
		    int n=a.size();
		    string ans="";
		    vector<int>cnt(26,0);
		    vector<char>vis;
		    for(int i=0;i<n;i++){
		        if(cnt[a[i]-'a']==0){
		            vis.push_back(a[i]);
		        }
		        cnt[a[i]-'a']++;
		        int f=0;
		        for(int j=0;j<vis.size();j++){//will run atmost 26 times
		            if(cnt[vis[j]-'a']==1){
		                f=1;
		                ans+=vis[j];
		                break;
		            }
		        }
		        if(f==0) ans+='#';
		    }
		    return ans;
		}

		//tc: o(26n)

};
