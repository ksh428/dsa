class Solution {
public:
    vector<int> FindExitPoint(vector<vector<int>>&mat){
        int n=mat.size();
		int m=mat[0].size();
		int d=1;
		unordered_map<int,int>mp;
		int i=0,j=0;
		mp[1]=-2;
		mp[-2]=-1;
		mp[-1]=2;
		mp[2]=1;
		while(1){
		    if(mat[i][j]){
		        d=mp[d];
		        mat[i][j]=0;
		    }
		    if(d==1){
		       j++;
		    }else if(d==-1){
		        j--;
		    }else if(d==2){
		        i--;
		    }else if(d==-2){
		        i++;
		    }
		    if(i<0){
		        i++;
		        break;
		    }else if(j<0){
		        j++;
		        break;
		    }else if(i==n){
		        i--;
		        break;
		    }else if(j==m){
		        j--;
		        break;
		    }
		}
		return {i,j};
    }
};
