#include <bits/stdc++.h>
using namespace std;

// https://codeforces.com/blog/entry/70018

// 0/1 knapsack - subset
/*
we will go order wise thus it will only give the combinations not the permutations and thus save us from duplicates

dp(i, s) = it stores 1 if upto ith index we can make sum s otherwise 0

base case dp(0, 0) = 1;
*/



#define ll long long

const int mxN = 105;
const int mxSum = 100005;
int dp[105][mxSum];
int v[mxN];



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    for(int i = 1; i<=n; i++){
        cin>>v[i];
    }

    dp[0][0] = 1;
    for(int i = 1; i<=n; i++){
        for (int j = 0; j <mxSum; j++)
        {
            dp[i][j] = dp[i-1][j];
            int left = j - v[i];
            if(left>=0 && dp[i-1][left]) dp[i][j] = 1;
        }
    }

    vector<int> ans;
    for (int i = 1; i < mxSum; i++)
    {
        if(dp[n][i]) ans.push_back(i);
    }
    
    cout<<ans.size()<<"\n";
    for(int v: ans){
        cout<<v<<" ";
    }

    return 0;
}