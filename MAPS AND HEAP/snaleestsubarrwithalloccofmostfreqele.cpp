class Solution{
    public:
    vector<int> smallestSubsegment(int a[], int n)
    {
        vector<int>ans;
    	unordered_map<int,int>fm;
    	unordered_map<int,int>sp;
    	int hf=0;
    	int ei=0;
    	int si=0;
    	int len=ei-si+1;
    	for(int i=0;i<n;i++){
    	    if(fm.find(a[i])!=fm.end()){
    	        fm[a[i]]++;
    	    }else{
    	        fm[a[i]]++;
    	        sp[a[i]]=i;
    	    }
    	    if(fm[a[i]]>hf){
    	       hf=fm[a[i]];
    	       ei=i;
    	       si=sp[a[i]];
    	       len=ei-si+1;
    	    }else if(fm[a[i]]==hf){
    	        int newl=i-sp[a[i]]+1;
    	        if(newl<len){
    	            len=newl;
    	            si=sp[a[i]];
    	            ei=i;
    	        }
    	    }
    	}
    	for(int i=si;i<=ei;i++){
    	    ans.push_back(a[i]);
    	}
    	return ans;

    }
};
