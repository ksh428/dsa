/* C/C++ program to print groups of shifted strings
together. */
#include <bits/stdc++.h>
using namespace std;
const int ALPHA = 26; // Total lowercase letter


string getkey(string s){
    int n=s.size();
    string key="";
    for(int i=1;i<n;i++){
        int dif=s[i]-s[i-1];
        if(dif<0) dif+=26;
        key+=(dif+'0');
        key+='#';
    }
  //  key+='.';
    return key;
}
void groupShiftedString(vector<string>str,int n){
    unordered_map<string,vector<string>>m;
    for(string s:str){
        string key=getkey(s);
        if(m.find(key)!=m.end()){
            m[key].push_back(s);
        }else{
            vector<string>v;
            v.push_back(s);
            m[key]=v;
        }
    }
    for(auto it:m){
        for(auto j:it.second) cout<<j<<" ";
        cout<<endl;
    }

}

int main()
{
	string str[] = {"acd", "dfg", "wyz", "yab", "mop",
					"bdfh", "a", "x", "moqs"
				};
	int n = sizeof(str)/sizeof(str[0]);
	vector<string>v(str,str+n);
	groupShiftedString(v, n);
	return 0;
}

