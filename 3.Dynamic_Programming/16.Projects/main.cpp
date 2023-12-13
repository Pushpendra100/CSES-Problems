#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=MJn3ogwsUbo
// https://www.youtube.com/watch?v=ISuIwMnSyXc


//Subset Problem

/*
P1 P2 P3 . . . . . Pn          arranged in order of end points

                     Pn  ( -> we can either select Pn or not)
            
        0                       1
    [P1 P2 ...  Pn-1]         rn + [P1 P2 . . .  Pi]

    If we select Pn then sn........en
    next project to select should have ei<sn only


dp(i): largest possible reward for P1 P2 .... Pi
dp(n): answer

dp(i) = max(dp(i-1), ri + dp(j))   where j is largest such that ej<si

Base Case dp(0) = 0

Idea is to store end points in a sorted vector(as i not need to insert any things otherwise i can use set) and for finding ej we will use lower bound

Time Complexity will be O(NlogN)
*/
#define ll long long

const int mxN = 2e5+10;
int n;
ll dp[mxN];

struct project{
    int st, ed, rwd;
};

bool cmp(project& p1, project& p2){
    return p1.ed < p2.ed;
}

int findBest(vector<int> &endPts, int val){
    auto it = lower_bound(endPts.begin(), endPts.end(), val);
    if(it == endPts.begin()) return 0;
    it--;
    return distance(endPts.begin(), it);  // all element counting in this range including both ends [endPts.begin(), it]
}

ll solve(vector<project> &v){
    dp[0] = 0;

    vector<int> endPts;
    for(project& p:v){
        endPts.push_back(p.ed);
    }

    for (int i = 1; i <=n; i++)
    {
        ll op1 = dp[i-1];
        ll op2 = v[i].rwd;
        // find the largest j such that end point of j is less than si;
        int j = findBest(endPts, v[i].st);
        op2 += dp[j];

        dp[i] = max(op1, op2);
    }
    return dp[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    vector<project> v(n+1);
    for (int i = 1; i <=n; i++)
    {
        cin>>v[i].st>>v[i].ed>>v[i].rwd;
    }
    sort(v.begin(), v.end(), cmp);
    
    cout<<solve(v);

    return 0;
}


