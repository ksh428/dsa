
#include <bits/stdc++.h>

using namespace std;

void fun(Node* root,vector<int>&path,int k){
    if(!root) return;
    path.push_back(root->data);
    fun(root->left,path,k);
    fun(root->right,path,k);
    int s=0;
    for(int j=path.size()-1;j>=0;j--){
        s+=path[j];
        if(s==k){
            for(int m=j;m<path.size();m++){
                cout<<path[m]<<" ";
            }
            cout<<endl;
        }
    }
    path.pop_back();
}

int main()
{
   vector<int>path;
   fun(root,path,k);

}

