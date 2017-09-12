/*
ID: sak0909
PROG: barn1
LANG: C++11
*/

#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>

//2d DP table initialization
//vector<vector<int>> DP(row_size, vector<int>(column_size, 0));

//Print a vector as string seperated by space
//std::copy(distance.begin(), distance.end(), std::ostream_iterator<int>(result, " "));

using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<vector<int>> VVI;
typedef pair<int,int> PII;
typedef pair<int,char> PIC;
typedef vector<PII> VPII;
typedef unordered_map<string, int> UMSI;
#define _F first
#define _S second
#define _PB push_back
#define _MP make_pair
#define _SZ size()
#define _B begin()
#define _E end()
#define _RB rbegin()
#define _RE rend()
typedef stringstream SS;
typedef istringstream ISS;
typedef ostringstream OSS;


int main()
{
    ifstream fin("barn1.in");
    ofstream fout("barn1.out");
//    ifstream fin("test.in");
//    ofstream fout("test.out");

    int M, S, C;
    fin >> M >> S >> C;
    VI distances;
    VI stalls;
    int t, n;
    n = C;

    while(n--){
        fin >> t;
        stalls._PB(t);
    }
    sort(stalls._B, stalls._E);

    for(int i=1; i<stalls._SZ; ++i){
        int t = stalls[i] - stalls[i-1];
        distances._PB(t);
    }
    sort(distances._B, distances._E, greater<int>());

    int ans = *stalls._RB - *stalls._B + 1;

    if(M < C)
        for(int i=0; i< M-1; ++i)
            ans -= distances[i]-1;
    else
        ans = C;

    fout << ans <<endl;
    return 0;
}
