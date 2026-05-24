class Solution{
	public:
	int count(int m){//count number of times n can be divided which is equal to number of prime factors -1
	    int c=0;
	    int n=m;
	    for(int i=2;i*i<=n;i++){
	        if(n%i==0){
	            while(n%i==0){
	                c++;
	                n/=i;
	            }
	        }
	    }
	    if(n>2) c++;
	    return c;
	}
	bool prime(int n){
	    for(int i=2;i*i<=n;i++){
	        if(n%i==0) return 0;
	    }
	    return 1;
	}
	//idea:
	/* if there are more than 1 non prime nos then a picks the largest and reduces(divides) it
	then b takes the largest in the new set and continues
	so at end if there is atleast 2 nos which are not equal then a pick up the no which can be divided
	more times and eventually wins
	*/
    bool brainGame(vector<int>a) {
        int n=a.size();
        vector<int>v;
        for(int x:a){
            if(!prime(x)) v.push_back(count(x)-1);
        }
        //cant prove why taking xor works but its the only intuitive thing so observaton
        int x=0;
        for(int i:v) x^=i;
        return x!=0;
    }
};
//https://practice.geeksforgeeks.org/problems/brain-game1742/1#
