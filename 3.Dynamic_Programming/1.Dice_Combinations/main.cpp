#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 1e6+10, M = 1e9+7;
int n; 
ll dp[mxN];

int main() {

    cin>>n;
    dp[0] = 1;
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <= min(6, i); j++)
        {
            dp[i] = (dp[i]+dp[i-j]) % M;
        }
    }
    cout<<dp[n];
    

    return 0;
}