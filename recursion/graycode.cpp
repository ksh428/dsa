
class Solution
{
    public:
    vector<string> graycode(int n)
    {
        if(n==1){
            vector<string>base;
            base.push_back("0");
            base.push_back("1");
            return base;
        }
        vector<string>prev=graycode(n-1);
        vector<string>currans;
        for(int i=0;i<prev.size();i++){
            currans.push_back("0"+prev[i]);
        }
        for(int i=prev.size()-1;i>=0;i--){
            currans.push_back("1"+prev[i]);
        }
        return currans;
    }
};
