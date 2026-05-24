
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	while(t--){
   string s;
   getline(cin,s);
   for(int i=0;i<s.size();i++){
       int index=s[i]-96;
       if(index==(-64)){
           cout<<"$";
       }else{
           cout<<index;
       }
   }
}

}
