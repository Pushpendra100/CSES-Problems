#include <bits/stdc++.h>
using namespace std;

#define ll long long

// int main() {

//     int n;
//     cin>>n;
//     vector<int> nums(n-1);
//     for (int i = 0; i < n-1; i++)
//     {
//         cin>>nums[i];
//     }

//     ll nums_sum = accumulate(nums.begin(), nums.end(), 0LL);
//     ll t_sum = (n *1LL * (n+1))/2;

//     cout<<t_sum - nums_sum<<endl;

//     return 0;
// }


// another way in short
int main() {

    ll n, s=0;
    cin>>n;
    vector<int> nums(n-1);
    for (int i = 1; i < n; i++)
    {   
        int a;
        cin>>a;
        s+=a;
    }
    cout<<n*(n+1)/2 - s;

    return 0;
}