#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n, p[20];


int main() {

    cin>>n;
    ll s = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin>>p[i];
        s+=p[i];
    }
    //sum closest to s/2
    // we will iterate through all subsets using bitmasks
    // no. of subsets = 2^n = 1<<n 
    // from 000 to 111 for n=3

    for (int i = 0; i < (1<<n) ; i++)
    {
        ll cs = 0; //current subset
        for (int j = 0; j < n; j++)
        {
            if(i>>j&1){
                cs+=p[j];
            }
        }
        if(cs<=s/2) ans = max(ans, cs);
    }

    // cout<<(s - ans) - ans<<endl;
    cout<<(s - 2*ans)<<endl;
    

    return 0;
}