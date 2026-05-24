bool possible(bool graph[101][101],vector<int>&col,int i,int N,int j){
    for(int k=0;k<N;k++){
        if(graph[k][i] and k!=i and col[k]==j) return false;
    }
    return true;
}

bool solve(bool graph[101][101],int m,int N,int i,vector<int>&col){
    if(i==N) return 1;
    for(int j=1;j<=m;j++){
        if(possible(graph,col,i,N,j)){
            col[i]=j;
            if(solve(graph,m,N,i+1,col)) return 1;
            col[i]=0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int N)
{
   vector<int>col(N,0);
   if(solve(graph,m,N,0,col)) return 1;
   else return 0;
}
