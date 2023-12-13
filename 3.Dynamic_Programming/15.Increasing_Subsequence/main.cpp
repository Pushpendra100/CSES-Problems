#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=66w10xKzbRM
// https://www.youtube.com/watch?v=66w10xKzbRM

// Longest Increasing Subsequence in O(NlogN);  DP + Binary search
// general solution is O(N^2)

/*
10 9 2 5 3 7 101 18
subarray is continous part of array i.e. 2 5 3
subsequence only keeps the order same in how they appear in array i.e. 9 3 7 18

longest increasing subsequence -> 2 5 7 101 = 4
                               -> 2 3 7 18 = 4
*/


/*
dp(i): length of longest subsequence that ends at the ith element

ans = max dp(i)  for all i from 1 to N

a1 . . . . . . | ai
dp(i) = 1 + max[dp(j)]  for all j from 1 to i-1 but ai>aj  
if no such valid j comes 
then dp(i) = 1 as it will be itself starting point  

This is O(N^2) - you can see luv file no. 92 for code 
*/


// Now O(NlogN) approach 
/*

a  =   [  7   3   5   3   6   2   9   8  ]
dp =      1   1 


v      7  3
adv    1  1

since 3 is always better than 7 

thus 
v       3  5
adv     1  2    

in some cases 5 is better and for some cases 3 is better like for x = 4,  3 is less than 4 and give adv 1
while for case 6, 5 provide better advantage than 3 

now we see again 3 with adv 1 is coming but there is already 3 with the same advantage thus we will not add it our potential candidates list

v       3  5  6
adv     1  2  3
6 -> 3 is also a good candidate as it provides more advantage

v       2  3  5  6  
adv     1  1  2  3  
now we add 2 -> 1 candidate we see that having 3 -> 1 candidate is useless, as 2 is less than 3 and also provides the same advantage    
thus 


v       2  5  6  
adv     1  2  3  

now, 
v       2  5  6  9
adv     1  2  3  4

now, 
v       2  5  6  8  9
adv     1  2  3  4  4
again same case, 9->4 become useless


v       2  5  6  8  
adv     1  2  3  4  





Observation 
1. sorted values, larger value => sorted advantage
2. for same advantage keep smaller value
    x->a and y->a
    and x < y 
    then we keep x->a



*/


int getBestCandidates(int v , map<int, int> &candidates){
    auto it = candidates.lower_bound(v);  
    if(it == candidates.begin()) return 0;
    it--;
    return it->second;
}

void insert(int v, int adv, map<int, int> &candidates){
    if(candidates[v] >= adv) return;
    candidates[v] = adv;
    auto it = candidates.find(v);
    it++;
    while (it!=candidates.end() && it->second <= adv)
    {
        auto temp = it;
        it++;
        candidates.erase(temp);
    }
}

int solve(int n, vector<int> &v){
    int dp[n];
    map<int, int> candidates;

    dp[0] = 1;
    candidates[v[0]] = dp[0];

    for(int i = 1; i<n; i++){
        dp[i] = 1 + getBestCandidates(v[i], candidates);
        insert(v[i], dp[i], candidates);
    }

    return *max_element(dp, dp+n);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    cout<<solve(n, v);

    return 0;
}