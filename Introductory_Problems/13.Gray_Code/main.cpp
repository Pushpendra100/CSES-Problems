#include <bits/stdc++.h>
using namespace std;

/*
n=1
0
1

from n=1 to n=2
0 0
0 1
1 1
1 0

from n=2 to 
n= 3
0 0 0
0 0 1
0 1 1
0 1 0
1 1 0
1 1 1
1 0 1
1 0 0
*/


int main() {

    int n;
    cin>>n;

    vector<string> gray;
    gray.push_back("0");
    gray.push_back("1");

    for (int i = 2; i <=n; i++)
    {
        int size = gray.size();
        for (int j = size-1; j >= 0; j--)
        {
            gray.push_back(gray[j]);
        }
        for (int i = 0; i < size; i++)
        {
            gray[i] = "0" + gray[i];
            gray[i+size] = "1" + gray[i+size];
        }
    }
    
    for (string code : gray)
    {
     cout<<code<<"\n";   
    }
    


    return 0;
}
