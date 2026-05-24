#include<bits/stdc++.h>
using namespace std;
bool palcheck(string s,int start,int last){
    if(start==last)
        return true;
    if(s[start]!=s[last])
        return false;
    if(start<last)
        return palcheck(s,start+1,last-1);
}
bool ispal(string s){
    if(s.size()==0)
        return true;
    palcheck(string s,int 0,int n-1);

}

int main()
{
    string s;
    cin>>s;
    int start=0;
    int last=s.size()-1;
    cout<<ispal1(s);
}
