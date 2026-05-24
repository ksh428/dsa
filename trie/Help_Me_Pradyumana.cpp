/* Pradyumn is tired of using auto - correct feature in his smartphone. He needs to correct his auto - correct more times than the auto - correct corrects him. Pradyumn is thinking to make his own app for mobile which will restrict auto - correct feature, instead it will provide auto - completion. Whenever Pradyumn types factorial, auto - correct changes it to fact. Pradyumn's App will show options such as fact, factorial, factory. Now, he can chose from any of these options. As Pradyumn is busy with his front - end work of his App. He asks you to help him. He said "You will be given set of words(words may repeat too but counted as one only). Now, as user starts the app, he will make queries(in lowercase letters only). So, you have to print all the words of dictionary which have the prefix same as given by user as input. And if no such words are available, add this word to your dictionary." As you know, Pradyumn want this app to be as smart as him :P So, implement a program for him such that he can release it on Fun Store.
INPUT CONSTRAINTS
1≤N≤30000
sum(len(string[i]))≤2∗10^5
1≤Q≤10^3
INPUT FORMAT
Single integer N which denotes the size of words which are input as dictionary
N lines of input, where each line is a string of consisting lowercase letter
Single integer Q which denotes the number of queries.
Q number of lines describing the query string on each line given by user
OUTPUT FORMAT
If auto - completions exists, output all of them in lexicographical order else output "No suggestions" without quotes

NOTE: All strings are lowercase
SAMPLE INPUT
3
fact
factorial
factory
2
fact
pradyumn
SAMPLE OUTPUT
fact
factorial
factory
No suggestions */


#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;

struct Node{
      Node* links[26];
      int f=0;
};
void insert(string s,Node* root){
      Node* node=root;
      for(int i=0;i<s.size();i++){
            if(!node->links[s[i]-'a']){
                node->links[s[i]-'a']=new Node();
            }
            node=node->links[s[i]-'a'];
      }
      node->f=1;
}
void dfs(Node* node,string s){
      if(node->f==1){
            cout<<s<<endl;
      }
      for(int i=0;i<26;i++){
            if(node->links[i]){
                  string news=s+char(i+'a');
                 dfs(node->links[i],news);
            }
      }

}
void query(string s,Node* root){
      Node* node=root;
      for(int i=0;i<s.size();i++){
            if(!(node->links[s[i]-'a'])){
                  cout<<"No suggestions"<<endl;
                  insert(s,root);
                  return;
            }else{
                  node=node->links[s[i]-'a'];
            }
      }
     dfs(node,s);

}

void solve() {
      int n;
      cin>>n;

      Node* root=new Node();
      for(int i=0;i<n;i++){
            string s;
            cin>>s;
            insert(s,root);
      }
      int q;
      cin>>q;
      while(q--){
            string t;
            cin>>t;
            query(t,root);
      }


}


int32_t main() {
	//initcode();
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
      solve();
	return 0;
}
