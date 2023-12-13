#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=-pXjopzMVrE

// For finding ordered ways in knapsack 
//we need to open elements one by one

/*
Given n coins c1, c2, c3, ... , cn; make sum x

        N,X
      0      1
    N-1,X   N, X-cn
*/

/*
 dp(i, x): valid ways to make x using c1, c2, ..., ci
 our final answer is dp(n, x);

 dp(i, x) = dp(i-1, x) + dp(i, x-ci);

 Time and Space Complexity = O(NX)
*/

int n, x;
const int M = 1e9+7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>x;
    vector<int> v(n+1);
    for(int i = 1; i<=n; i++){
        cin>>v[i];
    }    

    int dp[n+1][x+1];   

    for(int i = 1;i<=n; i++){
        for(int sum = 0; sum<=x; sum++){
            if(sum == 0) dp[i][sum] = 1; // we don't choose any coin at all //base case
            else{
                int op1 = (v[i]>sum)? 0 : dp[i][sum-v[i]]; //taken ith coin
                int op2 = (i==1)? 0:dp[i-1][sum]; //not taken ith coin
                dp[i][sum] = (op1 + op2) % M;
            }
        }
    }

    cout<<dp[n][x];


    return 0;
}