// CPP program for above approach
#include <iostream>
using namespace std;

// Global Array for
// the purpose of memoization.
int t[9][9];

// A recursive program, using ,
// memoization, to implement the
// rod cutting problem(Top-Down).
int un_kp(int price[], int length[],
					int n, int w)
{
    int dp[n+1][w+1];
    for(int i=0;i<=n;i++) dp[i][0]=0;
    for(int i=0;i<=w;i++) dp[0][i]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            if(length[i-1]<=j){
                dp[i][j]=max(price[i-1]+dp[i][j-length[i-1]],dp[i-1][j]);
            }else dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][w];
}

/* Driver program to
test above functions */
int main()
{
	int price[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
	int n = sizeof(price) / sizeof(price[0]);
	int length[n];
	for (int i = 0; i < n; i++) {
		length[i] = i + 1;
	}
	int Max_len = n;

	// Function Call
	cout << "Maxmum obtained value is "
		<< un_kp(price, length, n, Max_len) << endl;
}

