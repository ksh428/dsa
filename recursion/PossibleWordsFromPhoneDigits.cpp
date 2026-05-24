
class Solution{
    public:
    int n;
    vector<string>ans;
     unordered_map<int,string>m;
    void func(int idx,int a[],string temp){
        if(idx==n){
            ans.push_back(temp);
            return;
        }
        string curr=m[a[idx]];
        for(char c:curr){
            temp+=c;
            func(idx+1,a,temp);
            temp.pop_back();//backtrack
        }

    }
    vector<string> possibleWords(int a[], int N)
    {
        n=N;
        if(n==0) return ans;
        m[2]="abc";m[3]="def";m[4]="ghi";m[5]="jkl";m[6]="mno";
        m[7]="pqrs";m[8]="tuv";m[9]="wxyz";
        func(0,a,"");
        return ans;
    }
};
