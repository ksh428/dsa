//check 2 string are rotations of each other

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1,s2;
    int n1=s1.size();
    int n2=s2.size();
    if(n1!=n2)
        cout<<"no"<<endl;
    else{
        string temp=s1+s1;
        int res=temp.size();
        if(temp.find(s2) != string::npos){ //learn
            cout<<"yes";
        }else cout<<"no";


    }




}
