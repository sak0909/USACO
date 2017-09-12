/*
ID: sak0909
PROG: ride
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
typedef vector<vector<int>> VVI;
typedef pair<int,int> PII;
#define F first
#define S second
#define PB push_back
#define MP make_pair


int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string comet, group;
    fin >> comet >> group;
    int C = 1;
    int G = 1;
    for(int i =0; i < comet.length(); ++i) {
      C *= comet[i] - 'A' + 1;
    }
    for(int i =0; i < group.length(); ++i) {
      G *= group[i] - 'A' + 1;
    }

    if(C%47 == G%47)
        fout << "GO" << endl;
    else
        fout << "STAY" << endl;

    return 0;
}
