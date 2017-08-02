/*
ID: sak0909
PROG: namenum
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
typedef stringstream SS;
typedef istringstream ISS;
typedef ostringstream OSS;

string getHash(string name)
{
    OSS op;

    for(char c: name){
        if(c < 'Q')
            op << int((c-'A')/3) + 2;
        else
            op << int((c-'Q')/3) + 7;
    }
    return op.str();
}

int main()
{
    ifstream fin("namenum.in");
    ofstream fout("namenum.out");
//    ifstream fin("test.in");
//    ofstream fout("test.out");
    ifstream fdict("dict.txt");

    string ip;
    fin >> ip;
    string t;
    bool found = false;
    while(fdict >> t)
    {
        if(t.length() == ip.length() && ip == getHash(t))
        {
            fout << t << endl;
            found = true;
        }
    }
    if(!found)
        fout << "NONE" << endl;

    return 0;
}
