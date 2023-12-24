#include <bits/stdc++.h>
using namespace std;

// code -  https://codeforces.com/blog/entry/82103
// josepush problem - https://cp-algorithms.com/others/josephus_problem.html   // https://www.interviewbit.com/blog/josephus-problem/
// https://www.youtube.com/watch?v=fZ3p2Iw-O2I


/*
We will solve the problem recursively, reducing the problem by at least half at each step. If k<n2, we can see that the answer would be 2k.
Otherwise, we have removed all the even positions. The odd positions can be renamed from 1,2,…,n2 and we can recursively find the solution
for it. And then we can re-map back to our original n by multiplying by 2 and subtracting 1.
Time complexity is O(logn).
*/


#define ll long long

ll f(ll n, ll k){
    if(n==1) return 1;
    if(k<=(n+1)/2){
        if(2*k>n) return (2*k)%n;
        else return 2*k;
    }
    ll temp = f(n/2, k-(n+1)/2);
    if(n%2==1) return 2*temp+1;
    return 2*temp-1;
}

// O(logN)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    while (t--)
    {
        ll n, k;
        cin>>n>>k;
        cout<<f(n, k)<<"\n";
    }
    

    return 0;
}