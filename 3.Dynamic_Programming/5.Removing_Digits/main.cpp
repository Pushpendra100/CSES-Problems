#include <bits/stdc++.h>
using namespace std;


/*
            (d1d2d3d4...dk)

        x1      x2              xk              where xk = (d1d2d3...dk) - dk
        .
        .
        .
        0
*/

/*
dp(i): minimum steps needed to go from i to 0
dp(n): this is our answer
dp(n): this will be our recurrence
    dp(n) = min(dp(n), 1+dp(n-di));
dp(0) = 0 : base case
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> dp(n+1);
    dp[0] = 0;
    for (int i = 1; i <=n; i++)
    {
        int temp = i;
        dp[i] = 1e6+2; // my steps will be less than this as n is upto 1e6 only
        while (temp!=0)
        {
            int di = temp % 10; //last digit of temp
            temp /= 10; //last digit removed from temp
            dp[i] = min(dp[i], 1+dp[i-di]);
        }
    }
    
    cout<<dp[n];
    

    return 0;
}