
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node * left;
    node* right;
};
/*

void vertravel(node* root,int hd,map<int,set<int>> &m)
{
    if(root==NULL) return;
    m[hd].insert(root->data);
    vertravel(root->left,hd--,m);
    vertravel(root->right,hd++,m);

}

void verorder(node* root)
{
    map<int,set<int>>m;
    int hd=0;
    vertravel(root,hd,m);
    //display
    for(auto it:m){
        for(int i=0;i<it.second.size();i++){
            cout<<it.second[i]<<" ";
        }
    }
}

 */

 //actual
 map<map<int,set<int,int>>> m;
 void vot(node* root,int col,int row)
 {
     if(root==NULL) return;
     m[col][row].insert(root->data);
     vot(root->left,col--,row++);
     vot(root->right,col++,row++);

 }

 //implementation tbd..

 void solve(node* root)
 {
     vot(root,0,0);
     for(auto it:m){
            for(auto it1:it.second){
                for(auto i:it1.second){
                    for(auto )


                }
            }

     }
 }
int main()
{

}
