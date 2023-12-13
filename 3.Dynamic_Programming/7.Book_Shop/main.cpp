#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=qpNy2nuSuaI


// This is 0/1 bounded knapsack


/*
1. Defining dp state = dp(i, x): upto index i can select and x is the price limit and it stores the max pages i can get for this condition
2. Defining our answer = dp(N, X): this is our final answer
3. Defining recurrence
    dp(i, x) = 1. dp(i-1, x)    //didn't buy the book
               2. pi + dp(i-1, x-ci) //buy the book
               so i will choose max out of these two 1 and 2

Space and Time Complexity is O(NX) ~ 10^8
*/  

int n, x;
const int mxN = 1e3+10;
vector<int> price(mxN), pages(mxN);
int dp[mxN][100010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>x;
    for (int i = 1; i <=n; i++)
        cin>>price[i];
    for (int i = 1; i <=n; i++)
        cin>>pages[i];
    
    for (int i = 1; i <=n; i++){
        for(int money = 0; money<=x; money++){
            if(money==0){
                dp[i][money] = 0;   //base condition
                continue;
            }  

            int op1 = dp[i-1][money];
            int op2 = (money < price[i])? 0: pages[i] + dp[i-1][money - price[i]];
            dp[i][money] = max(op1, op2);
        }
    }

    cout<<dp[n][x];

    return 0;
}