//check if 2 strings are anagrams or not
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int n1=s1.size();
    int n2=s2.size();
    int a[25]={0};
    for(int i=0;i<n1;i++){
        int index=s1[i]-97;
        a[index]++;
    }
    for(int i=0;i<n2;i++){
        int index=s2[i]-97;
        a[index]--;
    }

    int flag=0;
    for(int x:a){
            if(x!=0)
            {

                flag=1;
                break;
            }

    }
    if(flag==0){
        cout<<"yes"<<endl;
    }else cout<<"no";
}
