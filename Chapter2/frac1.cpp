/*
ID: sak0909
PROG: frac1
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


void printFractions (ofstream& fout, int n, int s1, int s2, int e1, int e2)
{
   if (s2 + e2 > n)
       return;

   printFractions(fout, n, s1, s2, s1+e1, s2+e2);
   fout << s1+e1 << '/' << s2+e2 << endl;
   printFractions(fout, n, s1+e1, s2+e2, e1, e2);

}

int main()
{
    ifstream fin("test.in");
    ofstream fout("test.out");
//    ifstream fin("frac1.in");
//    ofstream fout("frac1.out");

    int N;
    fin >> N;

    fout << "0/1" << endl;
    printFractions(fout, N, 0, 1, 1, 1);
    fout << "1/1" << endl;


    return 0;
}
