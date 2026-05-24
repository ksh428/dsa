#include<bits/stdc++.h>
typedef long long ll;
#define mod 1000000007
#define endl "\n"
using namespace std;

void printencoding(string s,string osf){
    if(s.size()==0){
        cout<<osf<<endl;
        return;
    }
    else if(s.size()==1){
        if(s[0]=='0') return;
        else{
            int no=s[0]-'0';
            char req=(char)('a'+no-1);
            cout<<osf+req<<endl;
        }
    }else{
        //1 char use
        char ch=s[0];
        string req=s.substr(1);
        if(ch=='0') return;
        else{
            int no=ch-'0';
            char reqch=(char)('a'+no-1);
            //osf+=reqch;
            printencoding(req,osf+reqch);
        }
        //2 char use
        int a=(s[0]-'0')*10+(s[1]-'0');
        //string s2=s.substr(0,2);
        string newreq=s.substr(2);
       //int a=stoi(s2);
        if(a<=26){
            char code=(char)('a'+a-1);
            printencoding(newreq,osf+code);
        }else return;


    }
}

int main(){
   string s;
   cin>>s;
   printencoding(s,"");
}
