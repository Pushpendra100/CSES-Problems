#include <bits/stdc++.h>
using namespace std;

// https://usaco.guide/problems/cses-1085-array-division/solution
// solution from william lin
// https://www.youtube.com/watch?v=nai96X4ZsJg
// using binary search we are goig to find the maximum sum which is as small as possible of the subarray
/*
from observation we can say that ans>=mx_element_of_array

2 4 7 3 5
we can  divide it like 2 4 | 7 | 3 5
them minimum max sum is 8

if we try all ways which are possible to divide: we need to which max sum we can make
we can see max sum can be         7    8      9       10
                                 no  good    good    good
all these are possible to make which are good
but since we need minimum we have to get minimum we select 8


let's see another example
5 3
2 4 7 6 5

7       8       9       10      11      12      13
no      no      no      no      yes     yes     yes

12 is yes because we can divide the array in such a way that the max sum is less than or equal to yes
thus for y >= x, where x is the max sum of subarray possible ans is yes


This is a monotonic function, we need to find the number where switch happens
Thus we will use binary search.


how we will check that 10 is our answer or not
5 3
2 4 7 6 5
we will start iterating and add the numbers and as sum crosses the 10 we will split it and count the subarrays that we will divide into

2 4 | 7 | 6 | 5
our c = 4, thus we need to move to right as c>3, as big no. will make sure that array is divided less

*/

#define ll long long

const int mxN = 2e5;
int n, k, a[mxN];

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    cin>>n>>k;
    for(int i = 0; i<n; i++) cin>>a[i];

    ll lb = *max_element(a, a+n), rb = 1e18;
    while(lb<rb){
        ll mb = (lb+rb)/2;
        // cout<<mb<<" ";
        int c = 0;
        ll ls = 0;
        for(int i = 0; i<n; i++){
            if(ls + a[i]>mb){ // we need sum of subarray <= clos to mb 
                c++;
                ls = 0;
            }
            ls += a[i];
        }
        ++c;
        // c is counting in how many parts we divide the array
        // cout<<c<<endl;
        if(c>k){ // if we have more no. of subarrays then we increase mb by making lb = mb + 1, thus now less no. of times ls + a[i]>mb will be true
            lb = mb+1;
        }else rb = mb;
    }// O(N.logN)
    cout<<lb;
    return 0;
}