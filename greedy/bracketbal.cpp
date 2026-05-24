
//REVIEW !!
#include<bits/stdc++.h>
using namespace std;
int countmax(string s,int n){
int c=0;
vector<int>pos;
for(int i=0;i<n;i++)
{
   if(s[i]=="["){
    pos.push_back(i); //store all the indexes of [
   }
}
//int c=0;
int ans=0;
for(int i=0;i<n;i++)
{
    if(s[i]=="[")
        {c++;
        p++;
        }
    if(s[i]=="]")
        c--;
    if(count<0) //we need swapping
    {
        ans+=pos[p]-i; //no of po
        swap(s[i],s[pos[p]]);
        p++;
        c=1;


    }

}
cout<<ans;



}



int main()
{
    string s;
    cin>>s;
    int n=s.size();
    countmax(s,n);
}
