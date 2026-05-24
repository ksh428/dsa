//kadane algo app

class Solution{
public:
	int maxSubstring(string s)
	{
	    int n=s.size();
	    int ovmax=INT_MIN;
	    int currmax=0;
	    for(int i=0;i<n;i++){
	        int x=(s[i]=='0'?1:-1);
	        currmax+=x;
	        if(currmax>ovmax) ovmax=currmax;
	        if(currmax<0) currmax=0;
	    }
	    return ovmax;

	}
};
