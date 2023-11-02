#include <bits/stdc++.h>
using namespace std;
// Large Exponentiation with ETF & Euler's Theorem 


const int M = 1e9+7;

int binExp(int a, int b, int m){
    int ans = 1;
    while(b){
        if(b&1){
            ans = (ans * 1LL * a) % m; 
        }
        a = (a * 1LL * a)%m;
        b>>=1;
    }
    return ans;
}


int main() {

    int n;
    cin>>n;
    while (n--)
    {
        int a, b, c;
        cin>>a>>b>>c;
        // first we need to find out b^c
        // modulo given to power is (M-1) when M is prime thus 
        cout<<binExp(a, binExp(b, c, M-1), M)<<"\n";

    }
    
    

    return 0;
}