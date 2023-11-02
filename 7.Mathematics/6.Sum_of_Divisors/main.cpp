#include <bits/stdc++.h>
using namespace std;
// https://usaco.guide/problems/cses-1082-sum-of-divisors/solution
// https://www.youtube.com/watch?v=JqWiWJQOQyU&t=40s

/*
-> n = 10^12 implies that the desired time complexity is O(sqrt(n))


-> Calculating the sum of the divisors for each number from 1 to n seems to be
impossible- even if it was doable in constant time the solution would still TLE.
What if instead of starting from the numbers, we started from the divisors instead?
*/



/*
we know we will get the ocurrence of a number by n/i
i.e. ocurrence of 5 in n = 12 => 12/5 = 2.



i      1 2 3 4 5 6 7 8 9 10 11 12
12/i  12 6 4 3 2 2 1 1 1  1  1  1
there are in total 2sqrt(n) separate blocks over 1 to n
thus tc will be O(2*sqrt(n))

for i = 1 => q = 12/1 = 12      i' = 12/q + 1 = 2 gives the next block
for i = 2 => q = 12/2 = 6       i' = 12/6 + 1 = 3
for i = 3 => q = 12/3 = 4       i' = 12/4 + 1 = 4
for i = 4 => q = 12/4 = 3       i' = 12/4 + 1 = 5
for i = 5 => q = 12/5 = 2       i' = 12/2 + 1 = 7
for i = 7 => q = 12/7 = 1       i' = 12/1 + 1 = 13

now we have to add all the divisors
sum of n numbers is n(n+1)/2

12*1 + 6*2 + 4*3 + 3*4 + 2*(5+6) + 1*(7+8+9+10+11+12)





Also, (a/b)%M = ((a%M)*(b^M-2))%M         
and we can find b^(M-2) and this is find out using binExp using M

*/


#define ll long long
#define ln '\n'



const int M = 1e9+7;

int binExp(int a, int b){
    ll ans = 1;
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


int main() {

    ll n;
    cin>>n;
    ll answer = 0;

    for (ll i = 1, j; i <= n; i = j)
    {
        ll q = n/i; //no. of ocurrences
        j = n/q + 1; //beginning of next lot
        ll rangeSumUptoJminus1 = (((j%M)*((j-1)%M))%M)*binExp(2, M-2)%M;
        ll rangeSumUptoIminus1 = (((i%M)*((i-1)%M))%M)*binExp(2, M-2)%M;
        ll range = (rangeSumUptoJminus1 - rangeSumUptoIminus1 + M)%M;   //we add M inside the bracket to make sure the bracket remains positive always
        answer = (answer + (q%M)*range)%M;
    }
    cout<<answer;
    

    return 0;
}