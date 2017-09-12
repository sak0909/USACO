/*
ID: sak0909
PROG: milk
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
#define F first
#define S second
#define PB push_back
#define MP make_pair
typedef stringstream SS;
typedef istringstream ISS;
typedef ostringstream OSS;

bool compare(const PII& l, const PII& r)
{
    return l.F < r.F;
}

int main()
{
    ifstream fin("milk.in");
    ofstream fout("milk.out");
//    ifstream fin("test.in");
//    ofstream fout("test.out");

    int N, M, P, A;
    fin >> N >> M;
    VPII prices;
    while(M--)
    {
        fin >> P >> A;
        prices.PB(MP(P, A));
    }
    sort(prices.begin(), prices.end(), compare);

    int cost =0;
    for(auto pa: prices)
    {
        if(N>pa.S)
        {
            cost += pa.F * pa.S;
            N -= pa.S;
        }
        else
        {
            cost += N * pa.F;
            N = 0;
        }

        if(!N)
            break;
    }

    fout << cost <<endl;
    return 0;
}
