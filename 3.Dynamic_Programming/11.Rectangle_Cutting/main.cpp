#include <bits/stdc++.h>
using namespace std;

/*
dp(a, b): min cuts required to cut a rect of a*b such that we end up with squares
dp(A, B): this will be our answer

Base case
dp(a, a) = 0

Recurrence 
dp(a, b) = i from 1 to b-1         1 + dp(a, b-i) + dp(a, i)
           i from 1 to a-1         1 + dp(a-i, b) + dp(i, b)
           from all these options whichever is minimum is our answer

Space Complexity = O(A*B)
Time Complexity = O(AB*(A+B)) = O(AB^2 + A^2B) ~ O(A^3)
*/

int solve(int a, int b){
    int dp[a+1][b+1];
    for(int height = 1; height<=a; height++){
        for (int width = 1; width <= b; width++)
        {
            if(height == width) dp[height][width] = 0; //base case
            else{
                int ans = 1e8;
                // all possible vertical cuts
                for(int i = 1; i<width; i++){
                    ans = min(ans, 1 + dp[height][width - i] + dp[height][i]);
                }
                // all possible horizontal cuts
                for(int i = 1; i<height; i++){
                    ans = min(ans, 1 + dp[height - i][width] + dp[i][width]);
                }
                dp[height][width] = ans;
            }
        }
    }

    return dp[a][b];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin>>a>>b;
    cout<<solve(a, b);

    return 0;
}