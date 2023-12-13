#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=W1k8fXFIHTY

/*
dp[i][j] = max score P1 can get when he is playing 1st on [i...j];

dp[1][n] = this will be our final answer


ai a(i+1) a(i+2) ..... a(j-2) a(j-1) a(j)

dp[i][j] = 1.  ai + min(dp[i+2][j], dp[i+1][j-1])  // we need to take other player min 
           2.  aj + min(dp[i+1][j-1], dp[i][j-2])
           max of 1 and 2 will be our answer

Base case
1. i==j
    dp[i][j] = a[i];
2. j-1==i
    dp[i][j] = max(a[i], a[j]);
*/

#define ll long long

const int mxN = 5005;
ll dp[mxN][mxN];

ll rec(int l, int r, int a[]){
    //base case
    if(l==r) return a[l];
    if(r-1==l) return max(a[l], a[r]);

    ll &ans = dp[l][r];
    if(~ans) return ans;

    // rec cases
    ans = max(a[l] + min(rec(l+2, r, a), rec(l+1, r-1, a)), a[r] + min(rec(l+1, r-1, a), rec(l, r-2, a)));

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int a[n+1];
    for (int i = 1; i <=n; i++) cin>>a[i];

    memset(dp, -1, sizeof dp);

    cout<<rec(1, n, a)<<"\n";
    

    return 0;
}