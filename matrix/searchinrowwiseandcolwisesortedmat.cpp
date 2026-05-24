int matSearch (int N, int M, int matrix[][M], int x)
{
    int f=0;
    int i=0;
    int j=M-1;
    while(i<N && j>=0){
        if(matrix[i][j]==x) {
            f=1;
            break;
        }else if(matrix[i][j]>x){
            j--;
        }else i++;
    }
    if(f) return 1;
    else return 0;
}
//TC: O(M+N)
