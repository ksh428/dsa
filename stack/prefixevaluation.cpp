#include<bits/stdc++.h>
typedef long long ll;
#define mod 1000000007
#define endl "\n"
using namespace std;

int prefixevaluation(string s){
    stack<int>st;
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]>='0' and s[i]<='9') st.push(s[i]-'0');
        else{
            int v1=st.top();
            st.pop();
            int v2=st.top(); st.pop();
            switch(s[i]){
                case '+': st.push(v1+v2);
                break;
                case '-': st.push(v1-v2);
                break;
                case '/': st.push(v1/v2);
                break;
                case '*': st.push(v1*v2);
                break;
                default: break;
            }
        }
    }
    return st.top();
}

int main(){

}
