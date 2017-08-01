/*
ID: sak0909
PROG: gift1
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
typedef unordered_map<string, int> UMSI;
#define F first
#define S second
#define PB push_back
#define MP make_pair


int main() {
//    ofstream fout ("test.out");
//    ifstream fin ("test.in");
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    int NP;
    fin >> NP;
    VS names(NP);
    UMSI ledger;
    string name;
    for(int i = 0; i < NP; ++i )
    {
        fin >> name; names[i] = name; ledger[name] = 0;
    }
    string giver, receiver;
    int money, noOfRecivers;

    for(int i = 0; i < NP; ++i )
    {
        fin >> giver;
        fin >> money >> noOfRecivers;
        int share = 0;
        if (money && noOfRecivers)
        {
            share = (int)money/noOfRecivers;
        }

        ledger[giver] -= money;
        ledger[giver] += (money - share*noOfRecivers);
        for(int j = 0; j < noOfRecivers; ++j)
        {
            fin >> receiver;
            ledger[receiver] += share;
        }
    }


    for(auto i = names.begin(); i != names.end(); ++i)
    {
        fout << *i << " " << ledger[*i] << endl;
    }

    return 0;
}
