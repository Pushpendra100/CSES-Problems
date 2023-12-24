#include <bits/stdc++.h>
using namespace std;


/*
Distribution

Case1: Empty boxes allowed
    The number of ways of distributing r distinct things in n distinct boxes so that each box is filled with 0 or more things (empty boxes allowed) = n^r.

    e.g. first book have 3 options and second book also have 3 options
    thus 3^2 is our answer

Case2: Empty boxes not allowed
    The number of ways of distributing n distinct things in r distinct boxes so that each box is filled with at least one thing (empty boxes not allowed)
    = n^r - nC1(n-1)^r + nC2(n-2)^r - .... + (-1)^n-1.nCn-1(1)^r

Case3: Identical things in distinct boxes
    The number of ways of distributing r identical things in n distinct boxes so that each box is filled with 0 or more things (empty boxes are allowed) = r+n-1Cn-1
*/

const int M = 1e9+7;
const int mxN = 2e6+10;
int fact[mxN];


int binExp(int a, int b, int m){
    int result = 1;
    while (b>0)
    {
        if(b&1){
            result = (result * 1LL * a) % m;
        }
        a = (a * 1LL * a) % m;
        b>>=1;
    }
    return result;
}// O(logM)



int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fact[0] = 1;
    for (int i = 1; i <mxN; i++)
    {
        fact[i] = (fact[i-1]*1LL*i)%M;
    }
    

    int n, r;
    cin>>n>>r;

    int ans = fact[r+n-1]; 
    int den = (fact[n-1]*1LL*fact[r]) % M;
    ans = (ans * 1LL * binExp(den, M-2, M)) % M;
    cout<<ans<<"\n";

    return 0;
}