#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=KnsDFCcBJbY

/*
in the brute force method we can run two for loops i and j and get our answer but time complexity will be O(n^2)


1             6
  2    4
       4          8
    3         6


we will sort all ranges in a order
1---------6
  2---4
    3-----6
      4------8   

our criteria for sorting is li<lj and if li == lj then ri>rj,
thus as we move from top to down to store the max right border, in case of tie in left border than range with large right border will be placed before than the other one
thus we will get max right border set to this value and the below range can get a answer. Thus setting this tie this way is important

and for comparing right side we can maintain a varialbe maxRightBoundary so that we can know the current range is contained in some other range whose right value is set to maxRightBoundary

to find out the range which contains other ranges
we need to move from down to up of this sorted ranges and we will maintain minRightBoundary = INF
all the ranges which are below the ith range will have lj>=li thus left condition is already met but as we move from down to up to reach ith range our minRightBoundary is updated to keep track of min right border and if this is less than or equal to the ri 
then it means our current range contains some other range in its range
*/


#define ln "\n"
#define ll long long

struct range {
    int l, r, index;
    bool operator < (const range &other) const {
        if(l == other.l) return r > other.r;
        return l < other.l;
    }
};


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin>>n;
    vector<range> ranges(n);
    vector<bool> contained(n), contains(n);
    for(int i = 0; i<n; i++){
        cin>>ranges[i].l;
        cin>>ranges[i].r;
        ranges[i].index = i;
    }

    sort(ranges.begin(), ranges.end());
    
    int maxEnd = 0;
    for(int i = 0; i<n; i++){
        if(ranges[i].r <= maxEnd){
            contained[ranges[i].index] = true;
        }
        maxEnd = max(maxEnd, ranges[i].r);
    }
    int minEnd = 1e9+1;
    for(int i = n-1; i>=0; i--){
        if(ranges[i].r >= minEnd) contains[ranges[i].index] = true;
        minEnd = min(minEnd, ranges[i].r);
    } 

    for(int i = 0; i<n; i++){
        cout<<contains[i]<<" ";
    }
    cout<<ln;
    for(int i = 0; i<n; i++){
        cout<<contained[i]<<" ";
    }
    cout<<ln;
    return 0;
}