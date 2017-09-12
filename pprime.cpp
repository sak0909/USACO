/*
ID: sak0909
PROG: pprime
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

bool isPrime (int p)
{
    if ( p % 2 == 0 || p < 1 ) return false;

    int len = sqrt (p * 1.0);

    for ( int i = 3; i <= len; i += 2 ) if ( p % i == 0 ) return false;
    return true;
}

vector <int> palindromeList;

void oneDigit ()
{
    for ( int i = 1; i <= 9; i += 2 ) palindromeList.push_back (i);
}

void twoDigit ()
{
    for ( int i = 1; i <= 9; i += 2 ) palindromeList.push_back (i * 10 + i);
}

void threeDigit ()
{
    for ( int i = 1; i <= 9; i += 2 ) {
        for ( int j = 0; j <= 9; j++ )
            palindromeList.push_back (100 * i + 10 * j + i);
    }
}

void fourDigit ()
{
    for ( int i = 1; i <= 9; i += 2 ) {
        for ( int j = 0; j <= 9; j++ )
            palindromeList.push_back (1000 * i + 100 * j + 10 * j + i);
    }
}

void fiveDigit ()
{
    for ( int i = 1; i <= 9; i += 2 ) {
        for ( int j = 0; j <= 9; j++ ) {
            for ( int k = 0; k <= 9; k++ )
                palindromeList.push_back (10000 * i + 1000 * j + 100 * k + 10 * j + i);
        }
    }
}

void sixDigit ()
{
    for ( int i = 1; i <= 9; i += 2 ) {
        for ( int j = 0; j <= 9; j++ ) {
            for ( int k = 0; k <= 9; k++ )
                palindromeList.push_back (100000 * i + 10000 * j + 1000 * k + 100 * k + 10 * j + i);
        }
    }
}

void sevenDigit ()
{
    for ( int i = 1; i <= 9; i += 2 ) {
        for ( int j = 0; j <= 9; j++ ) {
            for ( int k = 0; k <= 9; k++ ) {
                for ( int l = 0; l <= 9; l++ )
                    palindromeList.push_back (1000000 * i + 100000 * j + 10000 * k + 1000 * l + 100 * k + 10 * j + i);
            }
        }
    }
}

void eightDigit ()
{
    for ( int i = 1; i <= 9; i += 2 ) {
        for ( int j = 0; j <= 9; j++ ) {
            for ( int k = 0; k <= 9; k++ ) {
                for ( int l = 0; l <= 9; l++ )
                    palindromeList.push_back (10000000 * i + 1000000 * j + 100000 * k + 10000 * l + 1000 * l + 100 * k + 10 * j + i);
            }
        }
    }
}

void generatePalinDrome ()
{
    oneDigit ();
    twoDigit ();
    threeDigit ();
    fourDigit ();
    fiveDigit ();
    sixDigit ();
    sevenDigit ();
    eightDigit ();
}

int main()
{
//    ifstream fin("test.in");
//    ofstream fout("test.out");
    ifstream fin("pprime.in");
    ofstream fout("pprime.out");

    int a, b;
    fin >> a >> b;

    generatePalinDrome();

    for(auto num:  palindromeList)
    {
        if(num >= a && num <= b && isPrime(num))
            fout << num << endl;
    }


    return 0;
}
