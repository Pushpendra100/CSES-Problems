#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=8QfWrRRK2PA
// Josephus Problem - https://cp-algorithms.com/others/josephus_problem.html
/*
# O(N) solution  to find the last remaining element

Using brute force modeling we can construct a table of values, (open the link given above)
and we can find out the following pattern:
    Jn,k = ((Jn-1,k + k -1)mod n) + 1; // this is 1 based indexing ( when numbers are starting from 1)
    // if you instead number the positions from 0, you get a very elegant formula //  Jn,k = ((Jn-1,k + k -1)mod n)
    given J1,k = 1;

// this delete the kth position number and goes on to do that until last number is left and it returns the last remaining number
// int josephus(int n, int k){
//     return n>1? (josephus(n-1, k) + k -1) % n + 1 : 1;
// }
*/

//but here we need to output the sequence of numbers that are going to be deleted
// here we have to delete every other child

/*
n = 7 odd
1 2 3 4 5 6 7    
1 3 6 7
3 7
7

we can see every time subproblem becomes (n+1)/2
// total time complexity is O(n.logn)


n = 10 even
1 2 3 4 5 6 7 8 9 10
1 3 5 7 9
1 5 9
5


when n is odd then the last element of this will become the first element in the next line
while when n is even then the first element of this will remain the first element in the next line



*/



#define ll long long


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin>>n;
    vector<int> children(n);
    for(int i = 0; i<n; i++)
        children[i] = i+1;
    while (children.size() > 1)
    {
        vector<int> survivors;
        for(int i = 0; i<children.size(); i++){
            if(i%2 == 1){  // even no., as even no. are placed on odd indexes
                cout<<children[i]<<" ";
            }else{
                survivors.push_back(children[i]);
            }
        }
        if(children.size()%2 == 0) children = survivors;
        else {
            int starter = survivors.back();
            survivors.pop_back();
            children.clear();
            children.push_back(starter);
            for(int z: survivors) children.push_back(z);
        }
    }// this while loop runs logn times and inside it runs O(n) times
    // thus tc = O(nlogn);
    cout<<children[0];

    return 0;
}