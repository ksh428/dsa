
class Solution
{
    public:
    int josephus(int n, int k)
    {
       //Your code here
       if(n==1) return 1;
       int x=josephus(n-1,k);
       int y=(x+k-1)%n+1;
       return y;
    }
};
