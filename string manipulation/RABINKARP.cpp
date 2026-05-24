

#include <bits/stdc++.h>

using namespace std;

#define d 256

void rabin(string txt,string pat,int q){
    int n=txt.size();
    int m=pat.size();
    int p=0,t=0,h=1;
    int i,j;
    for(int i=0;i<m-1;i++) h=(h*d)%q;
    for(i=0;i<m;i++){
        p=(d*p+pat[i])%q;
        t=(d*t+txt[i])%q;
    }
    for(i=0;i<=n-m;i++){
        if(p==t){
            for(int j=0;j<m;j++){
                if(txt[i+j]!=pat[j]) break;
            }
            if(j==m) cout<<"pattern found at "<<i;
        }
        if(i<n-m){
            t=d*(t-h*txt[i])+txt[i+m]%q;
            if(t<0){
                t+=q;
            }
        }
    }

}

int main()
{
    string txt="";
    string pat="";
    int q=101;
    rabin(txt,pat,q);
}

