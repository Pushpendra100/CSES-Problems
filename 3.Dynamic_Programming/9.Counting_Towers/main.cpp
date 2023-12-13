#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=pMEYMYTX-r0

/*
dp(i): no. of ways to fill positions starting from the ith position to the nth position of tower

[
    If i don't think of extending then there are only two options to put a tile of width 2 or put two tiles of width 1 each
    But if we think of extending then we need to know the previous tile because if there was a tile of width 2 then we have a added option of extending this 
    but if there are two tiles of width 1 each - then we can extend any one of them ( which one? ), or both of them
]

linked -> 1  if i-1th pos had a tile of width 2
linked -> 0  if i-1th pos had 2 tiles of width 1

dp(i, 0) no. of ways to build tower from ith pos to nth pos given that at i-1th pos there were two tile of width 1
dp(i, 1)

Final ans = dp(2, 0) + dp(2, 1)

dp(i, 0) = 1. do not extend any tile -> dp(i+1, 1) + dp(i+1, 0)
           2. extend both -> dp(i+1, 0)
           3. extend one of these: 2 * dp(i+1, 0)
    
dp(i, 1) = 1. do not extend any tile -> dp(i+1, 1) + dp(i+1, 0)
           2. extend -> dp(i+1, 1) 

Base Case
dp(n+1, 1/0) = 1 //we have to do nothing
*/

#define ll long long

const int M = 1e9+7;
const int mxN = 1e6+10;

ll dp[mxN][2];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

//  auto begin = chrono::high_resolution_clock::now();


    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        dp[n+1][0] = dp[n+1][1] = 1;
        for(int i = n; i>=2; i--){
            ll op1 = (dp[i+1][1] + dp[i+1][0]);
            ll op2 = dp[i+1][0] ;
            ll op3 = (2*dp[i+1][0]);
            ll op4 = dp[i+1][1];

            dp[i][0] = (op1 + op2 + op3) % M;
            dp[i][1] = (op1 + op4) % M;
        }

        cout<<(dp[2][1] + dp[2][0]) % M<<"\n";
        memset(dp, 0, sizeof dp);
    }
    

// auto end = chrono::high_resolution_clock::now();
// cout<<setprecision(4)<<fixed;
// cout<< "\nExecution time: "<<chrono::duration_cast<chrono::duration<double>>(end-begin).count()<<" seconds"<<"\n";

    return 0;
}

