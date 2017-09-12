/*
ID: sak0909
PROG: crypt1
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

bool valid(SI& S, int N)
{
    SS str;
    str << N;
    bool valid = true;
    for(char chr: str.str()){
        if(S._E == S.find(chr-'0')){
            return false;
        }
    }
    return true;
}

int main()
{
    ifstream fin("crypt1.in");
    ofstream fout("crypt1.out");
//    ifstream fin("test.in");
//    ofstream fout("test.out");

    int N, t;
    fin >> N;
    SI S;

    while(N--){
        fin >> t;
        S.insert(t);
    }

    int t1, t2, t3;
    int ans = 0;

    for(int a: S){
        for(int b: S){
            for(int c: S){
                for(int d: S){
                    for(int e: S){
                        t1 = a*100 + b*10 + c;
                        t2 = d*10 + e;
                        t3 = t1*t2;

                        SS chk1; chk1 << t1*d;
                        if(chk1.str()._SZ != 3) continue;

                        SS chk2; chk2 << t1*e;
                        if(chk2.str()._SZ != 3) continue;

                        if(!valid(S, t1*d) || !valid(S, t1*e) || !valid(S, t3))
                            continue;

                        ans++;
                    }
                }
            }
        }
    }

    fout << ans << endl;


    return 0;
}
