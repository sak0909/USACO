/*
ID: sak0909
PROG: combo
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
    ifstream fin("combo.in");
    ofstream fout("combo.out");
//    ifstream fin("test.in");
//    ofstream fout("test.out");

    int N, t;
    fin >> N;
    set<tuple<int, int, int>> S;

    int F1, F2, F3, M1, M2, M3;
    fin >> F1 >> F2 >> F3 >> M1 >> M2 >> M3;


    if(N>3)
    {
        int i, j, k;
        for(int ii = F1-2; ii <= F1+2 ;++ii)
            for(int jj = F2-2; jj <= F2+2 ;++jj)
                for(int kk = F3-2; kk <= F3+2 ;++kk)
                {
                    i=ii; j=jj; k=kk;
                    if(i < 1) i=N+i; if(i > N) i=i-N;
                    if(j < 1) j=N+j; if(j > N) j=j-N;
                    if(k < 1) k=N+k; if(k > N) k=k-N;

                    cout << i << j << k << endl;
                    S.insert(make_tuple(i,j,k));
                }


        for(int ii = M1-2; ii <= M1+2 ;++ii)
            for(int jj = M2-2; jj <= M2+2 ;++jj)
                for(int kk = M3-2; kk <= M3+2 ;++kk)
                {
                    i=ii; j=jj; k=kk;
                    if(i < 1) i=N+i; if(i > N) i=i-N;
                    if(j < 1) j=N+j; if(j > N) j=j-N;
                    if(k < 1) k=N+k; if(k > N) k=k-N;

                    cout << i << j << k << endl;
                    S.insert(make_tuple(i,j,k));
                }

        fout << S.size() << endl;
    }
    else
    {
        fout <<int(pow(N,3)) << endl;
    }


    return 0;
}
