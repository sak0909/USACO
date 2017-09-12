/*
ID: sak0909
PROG: milk3
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

int M = 21;
VI record(M,0);
VVI visited(M, VI(M,0));
int capacity[3];
void pour(int &from, int &to, int cpfrom, int cpto)
{
    if(to ==cpto)return ;
    int space=cpto-to;
    if(space>=from)
    {
        to=to+from;
        from=0;
    }
    else
    {
        to=cpto;
        from=from-space;
    }
    return ;
}

void dfs(int a, int b, int c)
{
    if(visited[b][c]==1)return;
    visited[b][c]=1;
    if(a==0)record[c]=1;

    int ta,tb,tc;
    ta=a;tb=b;tc=c;
    pour(tc,ta,capacity[2],capacity[0]); dfs(ta,tb,tc);

    ta=a;tb=b;tc=c;
    pour(tc,tb,capacity[2],capacity[1]);dfs(ta,tb,tc);

    ta=a;tb=b;tc=c;
    pour(tb,ta,capacity[1],capacity[0]);dfs(ta,tb,tc);

    ta=a;tb=b;tc=c;
    pour(tb,tc,capacity[1],capacity[2]);dfs(ta,tb,tc);

    ta=a;tb=b;tc=c;
    pour(ta,tb,capacity[0],capacity[1]);dfs(ta,tb,tc);

    ta=a;tb=b;tc=c;
    pour(ta,tc,capacity[0],capacity[2]);dfs(ta,tb,tc);

    return;
}


int main()
{
//    ifstream fin("test.in");
//    ofstream fout("test.out");
    ifstream fin("milk3.in");
    ofstream fout("milk3.out");

    fin>>capacity[0]>>capacity[1]>>capacity[2];
    dfs(0,0,capacity[2]);


    int blank=0;
    for(int i=0;i<M;++i)
    {
        if(record[i]==1)
        {
            if(blank)fout<<" ";
            blank=1;
            fout<<i;
        }
    }
    fout<<endl;
    return 0;

    return 0;
}
