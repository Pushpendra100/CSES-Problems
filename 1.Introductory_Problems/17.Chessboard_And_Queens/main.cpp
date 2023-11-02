#include <bits/stdc++.h>
using namespace std;

#define ll long long


// https://www.youtube.com/watch?v=dm70QwzBsMc
// https://www.youtube.com/watch?v=U-zC2blCz5Y
/*
each row will have a queen but we don't know the column
thus we need to go through all permutations of column and check which are valid
thus row is done, and col is permutations(1->8) 
and now we need to check that they are not on same diagnoal and the square is not reserved

for checking for diagnoals - we maintain boolean array for diagonals i.e. indexing of diagonals
one diagonal will be r-c (row - col + 7)
and another direction diagonal will be  r + c (row + col)
*/

string s[8];
bool b[15];

int main() {

    for (int i = 0; i < 8; i++)
        cin>>s[i];
    int p[8], ans = 0;
    iota(p, p+8, 0);

    do{
        bool ok = 1;
        for (int i = 0; i < 8; i++)
        {
            ok &= s[i][p[i]] == '.';  //checks square is not reserved
        }
        memset(b, 0, 15);
        for (int i = 0; i < 8; i++)
        {
            if(b[i+p[i]])     // r+c
                ok = 0;
            b[i+p[i]]=1;
        }
        memset(b, 0, 15);
        for (int i = 0; i < 8; i++)
        {
            if(b[i+7-p[i]])
                ok = 0; 
            b[i+7-p[i]] = 1;
        }
        ans+=ok;
    }while(next_permutation(p, p+8));

    cout<<ans<<endl;
    
    return 0;
}