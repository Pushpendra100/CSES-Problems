#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 110, mxX = 1e6+10;
int n, c[mxN], x;
ll dp[mxX];


int main() {

    cin>>n>>x;
    for (int i = 0; i < n; i++) 
        cin>>c[i];
    for (int i = 1; i <= x; i++)
    {
        dp[i] = 1e9;
        for (int j = 0; j < n; j++)
            if(c[j]<=i)
                dp[i] = min(dp[i], dp[i-c[j]]+1);
    }
    if(dp[x]>=1e9)
        cout<<-1;
    else
        cout<<dp[x];
    

    return 0;
}