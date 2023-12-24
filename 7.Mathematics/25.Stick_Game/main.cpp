#include <bits/stdc++.h>
using namespace std;


/*
this question can be thought like dp
dp(i) = when i sticks are there, and we have to make first move,  then if this is winning state (1) or this is losing state(0);
dp(0) = 0; base case, as with 0 sticks this is losing state

dp(i); from i = 1 to n is our answer

                    10
            9       7        6  -> if out of these if any one was losing state for me, and 
    now since i am on 10 and if any one was losing state was for me, now another person will be on that stage
    thus 10 will become my winning state

*/

const int mxN = 1e6;
bool dp[mxN+1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;
    int p[k];
    for (int i = 0; i < k; i++) cin>>p[i]; 
    dp[0] = 0; // 0 is losing state


    for(int i = 1; i<=n; i++){
        for(int j = 0; j<k; j++){
            if(p[j]<=i){
                dp[i]|=(!dp[i-p[j]]);
            }
        }
        cout<<(dp[i]?'W':'L');
    }

    
    return 0;
}