#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=lD_irvBkeOk

// Digit DP

/*
    [11, 16]
    11 is not valid
    12, 13, 14, 15, 16 are valid 

    12321 is valid
    1221 is not valid

    Brute force is to iterate from a to b but that would be O(b-a) ~10^18 opeartions


1. [0, b] - [0, a-1]
    if we solve for [0, b] then solving for [0, a-1] is identical
2. [0, b]  b -> n digit     

    dp(n) -> follow property that no two adjacent digits are the same 

    [1 (........)] -> n digit number
    if we put 1 here then n-1 digits should follow the property but 
    only this leading digit should not be 1

    dp(n, x) -> follow property that no two adjacent digits are same and leading digit is not x

    dp(N, -1): this is our answer


    for [0, b] -> n digit number
    e.g. n = 4; then i can write 0 0 0 1, 0 0 0 2, ....
    thus i need to keep track of leading zeroes as well

    dp(N, x, leading_zeroes?)


    b = 8      7      3  6  4
        _      _      _  _  _
       (0,8) 

        0      9      _  _  _
        8     (0, 7)  _  _  _
        8      5   [(_not 5_)  _  _]

    tight = 1 tells us that we are under tight constraint we can't put any digit
    leading_zero = 1 means we can keep putting leading zeros
    dp(N, x, leading_zero, tight)

    [0, b] -> n digit number
    dp(N, -1, 1, 1)
*/


#define ll long long
ll a, b;
ll dp[20][10][2][2]; 

ll solve(string& number, int n, int x, bool leading_zeros, bool tight ){
    if(n==0) return 1;
    if(x!=-1 && dp[n][x][leading_zeros][tight] != -1) 
        return dp[n][x][leading_zeros][tight];
    int lb = 0;
    int ub = tight?(number[number.length()-n] - '0'):9;

    ll answer = 0;
    for(int dig = lb; dig<= ub; dig++){
        if(dig==x && leading_zeros == 0) continue;
        answer += solve(number, n-1, dig, (leading_zeros && dig==0), (tight && (dig==ub)));
    }
    return dp[n][x][leading_zeros][tight] = answer;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof dp);
    cin>>a>>b;
    string A = to_string(a-1);
    string B = to_string(b);
    ll ans1  = solve(B, B.length(), -1, 1, 1);
    memset(dp, -1, sizeof dp);
    ll ans2 = solve(A, A.length(), -1, 1, 1);
    cout<<(ans1 - ans2);

    return 0;
}