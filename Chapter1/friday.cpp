/*
ID: sak0909
PROG: friday
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
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    VI count(7);
    int N;
    fin >> N;
    int c=0;
    VI monthDays={0,31,-1,31,30,31,30,31,31,30,31,30,31};
    for(int y = 1900; y < 1900+N; ++y)
    {
        for(int m = 1; m <= 12; ++m)
        {
            count[(c+13)%7] += 1;

            if(m == 2)
            {
                if(y%400 == 0)
                    c += 29;
                else if(y%100 == 0)
                    c += 28;
                else if(y%4 == 0)
                    c += 29;
                else
                    c += 28;
            }
            else
            {
                c += monthDays[m];
            }
        }
    }
    fout << count[6] << " ";
    fout << count[0] << " ";
    fout << count[1] << " ";
    fout << count[2] << " ";
    fout << count[3] << " ";
    fout << count[4] << " ";
    fout << count[5] << endl;

    return 0;
}
