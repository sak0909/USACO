/*
ID: sak0909
PROG: skidesign
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
typedef vector<string> VS;
typedef vector<vector<int>> VVI;
typedef pair<int,int> PII;
typedef pair<int,char> PIC;
typedef vector<PII> VPII;
typedef unordered_map<string, int> UMSI;
typedef set<int> SI;
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


int main()
{
    ifstream fin("skidesign.in");
    ofstream fout("skidesign.out");
//    ifstream fin("test.in");
//    ofstream fout("test.out");

    int N;
    fin >> N;
    int x;

    VI H;
    while(fin >> x)
        H._PB(x);

    int ans = INT_MAX;

    int i=0; int j =N-1;

    for (int i=0; i<=83; i++)
    {
        int cost=0,x=0;
        for (int j=0; j<N; j++)
        {
            // if hill is below the interval
            if (H[j]<i)
                x=i-H[j];
            // if hill is above the interval
            else if (H[j]>i+17)
                x=H[j]-(i+17);
            else
                x=0;

            cost+=x*x;
        }
        // update the minimum cost
        ans=min(ans,cost);
    }

    fout << ans << endl;
    return 0;
}
