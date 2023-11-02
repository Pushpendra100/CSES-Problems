#include <bits/stdc++.h>
using namespace std;
// solution video
// https://www.youtube.com/watch?v=RlpM5N-ttcU

#define ll long long

int main() {

    /*
    here we are only caring about the combinations and we doesn't care about permutations
    thus for k*k grid we will find out all the combinations and then subtract the combinations which are resticted by the question

    let x = k*k
    now all combinations = xC2 = x(x-1)/2
    also combinations which are not valid are = 2*2*(n-1)*(n-2)
    and these not valid combinations only exist when k>2
    */

    int n;
    cin>>n;
    for (int i = 1; i <=n; i++)
    {
        ll x = i*i;
        ll total_comb = x*(x-1)/2;
        if(i<3){
            cout<<total_comb<<"\n";
        }else{
            int attacking_knights = 4 * (i-1) * (i-2);
            cout<<(total_comb - attacking_knights)<<"\n";
        }
    }
    
    return 0;
}