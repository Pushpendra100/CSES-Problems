#include <bits/stdc++.h>
using namespace std;

/*
dp(i, x): no. of valid arrays of size i such that ith element or say last element is x;

dp(N, 1) + dp(N, 2) + ..... + dp(N, m) final answer
    summation from x = 1 to m  dp(N, x)

Recurrence
dp(i, x) = 0 if Ai != 0 && Ai != x
         = dp(i-1, x-1) + dp(i-1, x) + dp(i-1, x+1)  or Ai = 0 || Ai = x

Base case
dp(1, x) = 1 if A1 = 0 || A1 = x
         = 0  A1 != x  
*/

const int M = 1e9+7;


int solve(int n, int m, vector<int> &v){
    int dp[n+2][m+2]; //+2 so that we don't need to handle edge cases i.e. x+1 can exceed m
    memset(dp, 0, sizeof dp);

    for (int i = 1; i <= n; i++)
    {
        for(int x = 1; x<=m; x++){ // at ith position we are trying to place x
            if(i==1){ //base case
                if(v[i]==0 || v[i] == x){
                    dp[i][x] = 1;
                }else dp[i][x] = 0;
            }else {
                if(v[i]==0 || v[i] == x){
                    dp[i][x] = ((dp[i-1][x-1] + dp[i-1][x]) % M + dp[i-1][x+1]) % M;
                }else dp[i][x] = 0;
            }
        }
    }
    

    int ans = 0;
    for(int x = 1; x<=m; x++){
        ans = (ans + dp[n][x]) % M;
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;
    vector<int> v(n+1);
    for(int i = 1; i<=n; i++){
        cin>>v[i];
    }
    cout<<solve(n, m, v);

    return 0;
}