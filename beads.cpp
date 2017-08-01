/*
ID: sak0909
PROG: beads
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


int main() {
//    ofstream fout ("test.out");
//    ifstream fin ("test.in");
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    string ip;
    int N;
    fin >> N;
    fin >> ip;
    PII f,s;
    f.F = 0; //f.S = '';
    s.F = 0; //s.S = '';

    int i=0;
    int cnt=0;
    char cur='\0';
    int curInd;
    bool looped = false;

    set<int> st(ip.begin(), ip.end());
    bool rin = st.find('r') != st.end();
    bool bin = st.find('b') != st.end();

    if(rin && bin)
    {
        cur = ip[0];
        while(cur == *ip.rbegin() || 'w' == *ip.rbegin())
        {
            std::rotate(ip.rbegin(), ip.rbegin() + 1, ip.rend());
        }
        int wc=0;
        for(auto it= ip.begin(); it != ip.end(); ++it)
        {
            if(*it != 'w')
                break;
            wc++;
        }
        while(wc--)
            ip.PB('w');

        i=0;
        while(true)
        {
            cnt=1;
            curInd = i;
            cur=ip[i];
            while(i+1 < N  && (cur == ip[i+1] || cur == 'w' || ip[i+1] == 'w'))
            {
                i++;
                cnt++;
                if(cur=='w' && cur!=ip[i])
                    cur = ip[i];
            }
            i++;
            if(cnt > f.F)
            {
                s.F=f.F;s.S=f.S;
                f.F=cnt; f.S=curInd;
            }
            else if(cnt > s.F)
            {
                s.F=cnt; s.S=curInd;
            }
            if (i>=N)
                break;
        }

        fout << f.F + s.F << endl;
    }
    else
    {
        fout << ip.size() << endl;
    }




    return 0;
}
