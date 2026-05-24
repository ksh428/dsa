class Solution {//TC:O(M^2.N^2)
public:
    vector<string>ans;
    struct Node{
        Node* links[26];
        int f=0;
        string w="";
    };
    void insert(string s,Node* root){
        Node * node=root;
        for(int i=0;i<s.size();i++){
          if(node->links[s[i]-'a']==NULL){
              node->links[s[i]-'a']=new Node();
          }
            node=node->links[s[i]-'a'];
        }
        node->f+=1;
        node->w=s;
    }
    void dfs(int i,int j,vector<vector<char>>& board,Node* curr,int r,int c){
        if(i<0 or j<0 or i>r-1 or j>c-1 or board[i][j]=='$') return ;
        if(curr->links[board[i][j]-'a']==NULL) return;
        curr=curr->links[board[i][j]-'a'];
        if(curr->f > 0){
            ans.push_back(curr->w);
            curr->f-=1;
        }
        char ch=board[i][j];
        board[i][j]='$';
        dfs(i+1,j,board,curr,r,c);
        dfs(i,j+1,board,curr,r,c);
        dfs(i-1,j,board,curr,r,c);
        dfs(i,j-1,board,curr,r,c);
        board[i][j]=ch;

    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int r=board.size();
        int c=board[0].size();
        int l=words.size();
        Node* root=new Node();
        for(string s:words) insert(s,root);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                dfs(i,j,board,root,r,c);
            }
        }
        return ans;
    }
};
