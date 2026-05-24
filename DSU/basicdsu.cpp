#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod 1000000007
#define endl "\n"
using namespace std;

//BASIC DSU

int findparent(int a,vector<int>parent){
      if(parent[a]==a) return a;
      return findparent(parent[a],parent);
}
void unionn(int a,int b,vector<int>&parent){
      a=findparent(a,parent);
      b=findparent(b,parent);
      if(a==b){
            return;
      }
      parent[a]=b;
}
