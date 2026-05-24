#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n][n];
        //first initialize all elements to 0
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                a[i][j]=0;
            }
        }
        int num=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                a[i][j]=num;
                num++;
            }
        }
        if(n&1){
            //directly print
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cout<<a[i][j]<<" ";
                }
                cout<<endl;
            }

        }else{
            //for odd row display next ele then prev ele
            int row;
            for(int i=0;i<n;i++){
            row=0;
            if(i%2==0){
                row=1;
            }
            for(int j=0;j<n;j++){
                if(row==1){
                    cout<<a[i][j]<<" ";
                }else{
                    cout<<a[i][j+1]<<" "<<a[i][j]<<" ";
                    j++;//since we are printing 2 elements at the same time
                }
            }
            cout<<endl;
            }
        }
    }

}
