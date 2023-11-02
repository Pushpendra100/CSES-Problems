#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {

    int n;
    cin>>n;

    /*
    0 will be given by 2*5
    and since 2 is in sufficient amount so we can only count no. of time 5 comes as a prime factor
    */
   
    // int ans = (n/5) + (n/25) + (n/125) ......
    int ans = 0;
    int divider = 5;
    while(divider<=n){
        ans += n/divider;
        divider*=5;
    }
    cout<<ans;
    


    return 0;
}