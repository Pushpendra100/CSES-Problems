#include <bits/stdc++.h>
using namespace std;
// Prime factorisation and no. of factors

/*
16 - 2^4 thus all divisors are 2^(0<=alpha<=4) => 2^0, 2^1, 2^2, 2^3, 2^4 => 5 divisors
18 - 2.3^2 thus all divisors are 2(0<=alpha<=1).3(0<=beta<=2) = 2 * 3 = 6 divisors  => this is all combinations of 2^alpha.3^bets

if x = p1^α1 + p2^α2 + p3^α3 + .... + pn^αn
then no. of divisors = product of all (αi + 1)


*/

// we can find prime factorisation in sqrt(n)
// and since the given numbers will be at max a million i.e. 10^6 thus no. of primes at most will be only 30 approx
// thus tc O(sqrt(n) + 30) * 10^5 
// O(10^3. 10^5 ) ~ O(10^8) thus we can do this


/*
we don't do i < sqrt(n) bcoz this uses some function and then we have precision issues
thus we do i*i < sqrt(n)
*/


#define ll long long
#define ln '\n'



int main() {

    int q;
    cin>>q;
    while (q--)
    {
        int n;
        cin>>n;
        vector<int> powersOfPrimeFactors;
        for (int i = 2; i*i <= n; i++)
        {
            if(n%i==0){
                int power = 0;
                while (n % i==0)
                {
                    power++;
                    n /= i;
                }
                powersOfPrimeFactors.push_back(power);
            }       
        }
        if(n!=1){ // this is for prime number or for a prime factor which is greater than the sqrt (last factor) -> take example of 10
            powersOfPrimeFactors.push_back(1);
        }

        int numberOfDivisors = 1;
        for (int z : powersOfPrimeFactors)
        {
            numberOfDivisors *= (z+1);
        }
        cout<<numberOfDivisors<<ln;
        
    }
    

    return 0;
}