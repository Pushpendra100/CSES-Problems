#include <bits/stdc++.h>
using namespace std;


int main() {

    int t;
    cin>>t;
    while (t--)
    {
        int y, x;
        cin>>y>>x;
        long long ans;
        if(x>y){
            if((x&1)==1){ //x is odd
                ans = x*1LL*x;
                ans -= (y-1);
            }else{
                ans = (x-1)*1LL*(x-1) + 1;
                ans += (y-1);
            }
        }else{
            if((y&1)==1){ 
                ans = (y-1)*1LL*(y-1) + 1;
                ans += (x-1);
            }else{
                ans = y*1LL*y;
                ans -= (x-1);
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}