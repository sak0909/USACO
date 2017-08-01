/*
ID: sak0909
PROG: milk2
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
typedef unordered_map<string, int> UMSI;
#define F first
#define S second
#define PB push_back
#define MP make_pair


bool myComparison(const pair<int,int> &a,const pair<int,int> &b)
{
       return a.F<b.F;
}

int main() {
//    ofstream fout ("test.out");
//    ifstream fin ("test.in");
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    string ip;
    int N;
    fin >> N;

    vector<pair<int, int>> times;
    int t= N;
    int l,r;
    while(t--)
    {
        fin >> l >> r;
        times.PB(MP(l, r));
    }

    sort(times.begin(), times.end(), myComparison);

    int cST, cET, bMT, bIT;
    cST = times[0].F;
    cET = times[0].S;
    bMT = cET-cST;
    bIT = 0;

    for(auto time: times)
    {
        if(time.F <= cET)
        {
            if(time.S > cET)
            {
                cET = time.S;
                bMT = max(bMT, cET-cST);
            }
        }
        else
        {
            bIT = max(bIT, time.F-cET);
            cST  = time.F;
            cET = time.S;
        }
    }

    fout << bMT << " " << bIT << endl;

    return 0;
}
