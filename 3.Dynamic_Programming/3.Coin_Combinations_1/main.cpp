#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=5BdAl6gfusg

// Unbounded knapsack problem
// In knapsack problem we have choice to select a element or not and this can be done only once i.e. called 0/1 knapsack problem
// in unbounded we also have choice to select a element or not but we can again and again select the same element

// dp[i]: no. of ways to form sum==i 
// dp[x]
// dp[i] = dp[i-c1] + dp[i-c2] + ..... + dp[i-cn]

// Space Complexity - O(X)

// Time Complexity - O(NX) ~ 10^8 thus it will work
// as there are x states and for every state there are O(N) time

const int M = 1e9+7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin>>n>>x;

    vector<int> v(n);
    int dp[x+1];

    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    
    dp[0] = 1; // base case
    // you don't take any coin - this is the only one way to make sum zero
    for(int i = 1; i<=x; i++){
        dp[i] = 0;
        for(int coin_value: v){
            if(coin_value <= i)
                dp[i] = (dp[i]+dp[i-coin_value]) % M;
        }
    }
    cout<<dp[x];

    return 0;
}