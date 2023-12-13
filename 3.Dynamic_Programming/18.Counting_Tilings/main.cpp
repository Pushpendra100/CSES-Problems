#include <bits/stdc++.h>
using namespace std;

// DP with bitmasking
// https://www.youtube.com/watch?v=lPLhmuWMRag

/*
dp(i, mask): number of ways to fill the columns from ith till mth given
    that some positions are already filled

dp(1, 0): answer


we are filling tile from left to right
*/
const int M = 1e9+7;
int n, m;
int dp[1001][1<<11];

void generate_next_masks(int current_mask, int i, int next_mask, int n, vector<int>& next_masks){
    if(i == n+1){
        next_masks.push_back(next_mask);
        return;
    } 
    if((current_mask & (1<<i)) != 0)
        generate_next_masks(current_mask, i+1, next_mask, n, next_masks);
    if(i != n)
        if((current_mask & (1<<i)) == 0 && (current_mask & (1 << (i+1))) == 0)
            generate_next_masks(current_mask, i+2, next_mask, n, next_masks);
    if((current_mask & (1<<i)) == 0)
        generate_next_masks(current_mask, i+1, next_mask + (1<<i), n, next_masks);
}


int solve(int col, int mask, const int m, const int n){

    //base case
    if(col == m+1){
        if(mask == 0) return 1;
        return 0;
    }

    if(dp[col][mask] != -1) return dp[col][mask];
    int answer = 0;
    vector<int> next_masks;
    generate_next_masks(mask, 1, 0, n, next_masks);

    for(int next_mask: next_masks){
        answer = (answer + solve(col+1, next_mask, m, n)) % M;
    }
    return dp[col][mask] = answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;

    memset(dp, -1, sizeof dp);  
    cout<<solve(1, 0, m, n);

    return 0;
}