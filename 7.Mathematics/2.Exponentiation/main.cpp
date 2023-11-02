#include <bits/stdc++.h>
using namespace std;

//Binary Exponentiation
// a, b<=10^9
// works for b<=10^18
// and for greater b than this large exponentiation with euler formula is used

const int M = 1e9+7;

int binExpIter(int a, int b){
    int ans = 1;
    while (b)
    {
        if(b&1){
            ans = (ans * 1LL * a) % M;
        }
        a = (a * 1LL * a) % M;
        b>>=1;  
    }
    return ans;
}
// tc:- log(b)

int main() {

    int n;
    cin>>n;
    while (n--)
    {
        int a, b;
        cin>>a>>b;
        cout<<binExpIter(a, b)<<"\n";
    }
    

    return 0;
}