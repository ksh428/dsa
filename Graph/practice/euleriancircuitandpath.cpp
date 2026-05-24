//undirected
class Solution {
public:
	int isEularCircuit(int v, vector<int>adj[]){
	    int c=0;
	    int deg[v]={0};
	    for(int i=0;i<v;i++){
	        deg[i]=adj[i].size();
	    }
	    for(int i=0;i<v;i++){
	        if(deg[i]%2==0) c++;
	    }
	    if(c==v) return 2;
	    if(c==v-2) return 1;
	    return 0;
	}
};

//directed


class Solution {
public:
	int isEularCircuit(int v, vector<int>adj[]){
	    int c=0;
	    int indeg[v]={0};
	    int outdeg[v]={0};
	    for(int i=0;i<v;i++){
	        outdeg[i]=adj[i].size();
	        for(int j:adj[i]){
	            indeg[j]++;
	        }
	    }
	    int a=0,b=0;
	    for(int i=0;i<v;i++){
	        if(indeg[i]==outdeg[i]) c++;
	        if(indeg[i]==outdeg[i]+1) a++;
	        if(indeg[i]+1==outdeg[i]) b++;
	    }
	    if(c==n){
	        return 2;
	    }
	    if(c==n-2 and a==1 and b==1) return 1;
	    return 0;
	}
};
