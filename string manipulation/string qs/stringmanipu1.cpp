
//given a string arrange the string in descending order from a given starting index to  ending index
#include <iostream>

using namespace std;

int main()
{
   string s;
    int start,last;

   cin>>s>>start>>last;
   int n=s.size();
   int a[26]={0};
   string ans="";

   for(int i=0;i<start;i++){
       ans+=s[i];

   }
   for(int i=start;i<=last;i++){
       int index=s[i]-97;
       a[index]++;
   }
   for(int i=25;i>=0;i--){
       if(a[i]>0){
           while(a[i]--){
           int ascii=i+97;
           ans+=char(ascii);
           }
       }
   }
   string sub1=s.substr(last+1,n-last-1);
   cout<<ans+sub1;


}
