#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=TOsD3BkIKoQ

/*
Observations
1. { 1 2 3 4 5 6 ... n } given n natural numbers
2. thus sum of each set need to be n(n+1)/4 = Sn/4


Thus we have to find sets with sum = Sn/4 and we know that its comliment will exist;
But then we only need to remove the duplicate sets and after getting the no. of unique sets we will divide it by 2 to get our answer and this is our answer
duplicate sets ( in which elements are rearranged - thats what i mean here) can be taken care as we are going order wise taking first i elements


[1 2 3 ............ 500]

                    (500, Sn/4)
        
        0(leave 500)           1(take 500)
        (499, Sn/4)            (499, Sn/4 - 500)


dp(i, x): no. of ways to form x given {1, 2, 3, ... i}
dp(N, Sn/4)/2 = this will be our answer
dp(i, x) = dp(i-1, x) + dp(i-1, x - i);
dp(0, 0) = 1; base case
dp(0, x) = 0; base case

*/

#define ll long long
const int M = 1e9+7;
const int mxN= 505;
ll dp[mxN][mxN*mxN];    //the size of an array must be a constant expression known at compile-time.
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    // ll dp[n+1][n*n]; //wrong
    dp[0][0] = 1;
    for(int i = 1; i<=(n*(n+1)/4); i++) dp[0][i] = 0;

    for(int i = 1; i <= n; i++){
        for(int x = 0; x<= ((n*(n+1))/4); x++){
            dp[i][x] = (((x < i ) ? 0 : dp[i-1][x-i]) + dp[i-1][x]) % M;
        }
    }
    if((n*(n+1)) % 4 != 0) cout<<0;
    // else cout<<dp[n][(n*(n+1)/4)]/2;  // this is wrong
    // we need to take modulo
    // else cout<<(dp[n][(n*(n+1)/4)] * 500000004) % M;
    // or als we can do like this also 
    else cout<<(dp[n][(n*(n+1)/4)] * ((M+1)/2)) % M;

    /*
    for taking modulo in division
    (a/b)%M = (a%M * modular_multiplicative_inverse_with_respect_to_M(b)) % M
    */

    return 0;
}