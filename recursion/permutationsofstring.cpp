
//RECUSRION + BACKTRACKING

#include <bits/stdc++.h>

using namespace std;

void perm2(string s,int j){
    if(j==s.size()-1){
        cout<<s<<" ";
        return;
    }
    for(int i=j;i<s.size();i++){
        swap(s[i],s[j]);//the original string changes due to swapping
        perm2(s,j+1);
        swap(s[i],s[j]); //keep the original problem  //BACKTRACK
    }
}

int main()
{
    perm2("ABC",0);

}

class Solution
{
	public:
	vector<string>ans;
	void perm(string s,string asf){
	    if(s.size()==0){
	        ans.push_back(asf);
	        return;
	    }
	    for(int i=0;i<s.size();i++){
	        string req=s.substr(0,i)+s.substr(i+1);
	        perm(req,asf+s[i]);
	    }
	}
		vector<string>find_permutation(string s)
		{
		   perm(s,"");
		   sort(ans.begin(),ans.end());
		   return ans;
		}
};
