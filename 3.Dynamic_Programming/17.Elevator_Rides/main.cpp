#include <bits/stdc++.h>
using namespace std;


//Bitmask DP

// https://www.youtube.com/watch?v=UEkvzjsodDk

/*
Some binary things
no. of subsets = 2^n
and 2^n = 1<<n

thus we declare dp as dp[1<<n]


We have find very subset possible and tried to add a new element to it hoping to reduce the no. of rides if possible
and to represent subsets we have used bitmasking


            ->                 ->                   ->
4 (1, 4)        4,8  (2, 4)         4,8,6  (2, 10)      4,8,6,1 (2, 9)
8 (1, 8)        4,6  (1, 10)        4,8,1  (2, 5)
6 (1, 6)        4,1  (1, 5)         4,6,1  (2, 1)
1 (1, 1)        8,6  (2, 6)         8,6,1  (2, 7)
                8,1  (1, 9)
                6,1  (1, 7)



*/

int n, limit;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>limit;
    vector<int> weights(n);
    for(int i = 0; i<n; i++) cin>>weights[i];

    vector<pair<int, int>> dp(1<<n, {1e9+1, 1e9+1});
    dp[0] = {1, 0};
    for(int mask = 1; mask < (1<<n); mask++){
        for(int bit = 0; bit<n; bit++){
            if((1<<bit)&mask){
                int space_taken = dp[mask^(1<<bit)].second;
                if(space_taken + weights[bit]<=limit){
                    dp[mask] = min(dp[mask], {dp[mask^(1<<bit)].first, space_taken + weights[bit]});
                }else{
                    dp[mask] = min(dp[mask], {dp[mask^(1<<bit)].first + 1, weights[bit]});
                }
            }
        }
    }
    cout<<dp[(1<<n)-1].first;
    return 0;
}