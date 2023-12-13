#include <bits/stdc++.h>
using namespace std;

/*
Edit Distance

dp(i, j) = edit distance [si....sn] and [pj....pm]

Answer
dp(1, 1) 

Recurrence
dp(i, j) = 1. 1 + dp(i, j+1)  // insert operation
           2. 1 + dp(i+1, j)  // delete operation
           3. 1 + dp(i+1, j+1) // replace operation (si with pj)

Base Case
dp(n+1, m+1) = 0
*/

/*
Time complexity = O(s.p);
*/

int dp[5001][5001];

int solve(int i, int j, string& s1, string & s2){
    if(i == (int)s1.length() || j == (int)s2.length()){
        return max(s2.length() - j, s1.length() - i);  // when any one string completely ends then we need to do complete addition or complete deletion only which will be equal to the lenght of the other string
    }

    if(~dp[i][j]) return dp[i][j];

    int ans;
    if(s1[i]==s2[j]){
        ans = solve(i+1, j+1, s1, s2);
    }
    else{
        int op1 = 1 + solve(i, j+1, s1, s2);// add
        int op2 = 1 + solve(i+1, j, s1, s2);// remove
        int op3 = 1 + solve(i+1, j+1, s1, s2); //replace
        // ans = min(op1, min(op2, op3));
        ans = min({op1,op2, op3});
    }
    return dp[i][j] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof dp);
    string s1, s2;
    cin>>s1>>s2;
    cout<<solve(0, 0, s1, s2);

    return 0;
}