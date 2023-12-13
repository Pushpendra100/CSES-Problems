#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=V64F4wlodUM

/*
dp(i, j) - no. of valid paths from the cell (i, j) to (n, n)

dp(i, j) = dp(i+1, j) + dp(i, j+1)
dp(n, n) = 1

Complexity is O(n^2)
*/

const int M = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    bool grid[n+1][n+1];
    for (int i = 1; i <=n; i++)
    {
        for(int j = 1; j<=n;j++){
            char ch; cin>>ch;
            if(ch=='.') grid[i][j] = 0;
            else grid[i][j] = 1;
        }
    }
    int dp[n+1][n+1];
    for(int i = n; i>=1; i--){
        for(int j = n; j>=1; j--){
            if(i==n && j==n){ //base case
                if(grid[i][j]) dp[i][j] = 0;
                else dp[i][j] = 1; 
            }
            else{
                int op1 = (j==n)? 0: dp[i][j+1];
                int op2 = (i==n)? 0: dp[i+1][j];
                dp[i][j] = (op1 + op2) % M;
                if(grid[i][j]) dp[i][j] = 0;
            }
        }
    }

    cout<<dp[1][1];

    return 0;
}