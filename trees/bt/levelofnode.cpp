
#include<bits/stdc++.h>
using namespace std;
int findlevel(node * root,int val,int level){
    if(!root) return 0;
    if(root->data==val) return level;
    int lvl=findlevel(root->right,level+1);
    if(lvl!=0) return lvl;
    lvl=findlevel(root->left,level+1);
    return lvl;
}
int main(){
    findlevel(root,4,0);
}
