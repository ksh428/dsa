// C++ implementation to print
// reverse wave form of matrix
#include<bits/stdc++.h>
using namespace std;

#define R 4
#define C 4

// function to print reverse wave
// form for a given matrix
void WavePrint(int m, int n, int arr[R][C])
{
    for(int i=n-1;i>=0;i--){
        if(i&1){
            for(int j=0;j<m;j++){
                cout<<arr[j][i]<<" ";
            }
        }else{
            for(int j=m-1;j>=0;j--){
                cout<<arr[j][i]<<" ";
            }
        }
    }

}

// driver function
int main()
{
	int arr[R][C] = { { 1, 2, 3, 4 },
					{ 5, 6, 7, 8 },
					{ 9, 10, 11, 12 },
					{ 13, 14, 15, 16 } };
	WavePrint(R, C, arr);

	return 0;
}

