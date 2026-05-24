//find duplicates in string using bitwise
#include<bits/stdc++.h>
using namespace std;
int main(){
   string s;
   cin>>s;
   int h=0;
   int x=0;
   for(int i=0;i<s.size();i++){
    x=1;
    int diff=s[i]-97;
    x=x<<diff;
    if(x&h){
        cout<<s[i]<<" ";

    }else{
        h=x|h;
    }

   }
}
