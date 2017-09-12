/*
ID: sak0909
PROG: numtri
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

//Print a vector as string seperated by space
//std::copy(distance.begin(), distance.end(), std::ostream_iterator<int>(result, " "));

using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef pair<int,char> PIC;
typedef vector<PII> VPII;
typedef unordered_map<string, int> UMSI;
typedef set<int> SI;
typedef unordered_set<int> USI;
typedef tuple<int,int,int> TIII;
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

int findMax(VVI& IP, VVI& cache, int r, int c)
{
    if(r >= IP._SZ || c >= IP[r]._SZ)
        return 0;

    if(cache[r][c] != -1)
        return cache[r][c];

    cache[r][c] = IP[r][c] + max(findMax(IP, cache, r+1, c), findMax(IP, cache, r+1, c+1));
    return cache[r][c];
}

int main()
{
//    ifstream fin("test.in");
//    ofstream fout("test.out");
    ifstream fin("numtri.in");
    ofstream fout("numtri.out");

    int R;
    fin >> R;

    VVI IP(R);
    VVI Cache(R);
    for(int i=0; i < R; ++i)
        for(int j=0; j <= i; ++j)
        {
            int t; fin >> t;
            IP[i]._PB(t);
            Cache[i]._PB(-1);
        }

   fout << findMax(IP, Cache, 0, 0) << endl;

    return 0;
}
