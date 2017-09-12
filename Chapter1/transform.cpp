/*
ID: sak0909
PROG: transform
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

int n;
char before[11][11],after[11][11],temp[11][11];
bool cmp( char a[11][11],char b[11][11] )
{
    for (int i=0;i!=n;i++)
    for(int j=0;j!=n;j++)
    if(a[i][j]!=b[i][j])
    return false;
    return true;
}
void r90(char b[11][11])
{
    char a[11][11];
    memcpy(a,b,sizeof(char)*121);
    for(int i=0;i!=n;i++)
    for(int j=0;j!=n;j++)
    temp[j][n-i-1]=a[i][j];
}
void reflect(char a[11][11])
{

    for(int i=0;i!=n;i++)
    for(int j=0;j!=n;j++)
    temp[i][j]=a[i][n-j-1];
}
int main()
{
    ifstream fin("transform.in");
    ofstream fout("transform.out");
    fin >> n;
    char in;
    for(int i=0;i!=n;i++)
    {
        for(int j=0;j!=n;j++)
        {
            fin >> in;
            before[i][j]=temp[i][j]=in;
        }
    }

    for(int i=0;i!=n;i++)
    {
        for(int j=0;j!=n;j++)
        {
            fin >> in;
            after[i][j]=in;
        }
    }

    bool run=true;
    for(int i=0;i!=3;i++)
    {
        r90(temp);
        if( cmp(temp,after) && run )
        {
            fout << i+1 <<endl;
            run = false;
        }
    }
    if(run)
    {
        reflect(before);
        if( cmp(temp,after))
        {
            fout << 4 <<endl;
            run = false;
        }
    }
    if(run)
    {
        reflect(before);
        for(int i=0;i!=3 && run ;i++)
        {
            r90(temp);
            if( cmp(temp,after) && run )
            {
                fout << 5 <<endl;
                run = false;
            }
        }
    }
    if( cmp(before,after) && run )
    {
        fout <<6 <<endl;
        run = false;
    }
    if(run)
    fout << 7 <<endl;
    //system("pause");
    return 0;
}
