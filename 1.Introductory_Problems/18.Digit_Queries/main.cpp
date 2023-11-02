#include <bits/stdc++.h>
using namespace std;

/*
123456789
1011121314.....99
100101102103.....999

no. of two digit numbers = 90 
and thus total digits = 90*2 = 180

thus range of two digit numbers = 10 - 189


if k is given between 10 and 189 we know  10<=n<=99

what is the starting position of 13 --> (13 - 10)*2 digits
--> (13 - 10)*2 + 10 = 16


since we have  10<=n<=99  we can do binary search here
(mid - 10) * 2


no. between 100 & 10 = 100-10 ->no. of 2 digit numbers
no. between 1000 & 100 = 1000-100 ->no. of 3 digit numbers
*/

#define ll long long



int main() {

    int t;
    cin>>t;
    vector<ll> powers(19,1);    
    for (int i = 1; i < 19; i++)
    {
        powers[i] = powers[i-1] * 10;
    }
     
    while (t--)
    {
        ll k;
        cin>>k;

        ll num_dig =0;
        ll digits = 0;
        ll prev_dig = 0;
        for (int i = 1; i < 19; i++)
        {
            digits += (powers[i]-powers[i-1])*i; //no. of digits
            if(digits >= k){
                num_dig = i;
                break;
            }
            prev_dig = digits;
        }
        ll low = powers[num_dig - 1];
        ll high = powers[num_dig] - 1;
        ll ans = 0;
        ll startPosAns = 0;
        while (low<=high)
        {
            ll mid = (high+low)/2;
            ll startPos = (mid - powers[num_dig - 1]) * num_dig + prev_dig +1;
            if(startPos<=k){
                if(mid>ans){
                    ans = mid;
                    startPosAns = startPos;
                }
                low = mid+1;
            }else{
                high = mid - 1;
            }
        }
        string number = to_string(ans);
        cout<<number[k - startPosAns]<<endl;
        
    }
    
    
    return 0;
}