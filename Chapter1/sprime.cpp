/*
ID: sak0909
PROG: sprime
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

vector <int> primes;


void generatePrimeRibs ()
{
    primes._PB(2);
    primes._PB(3);
    primes._PB(5);
    primes._PB(7);

    int startIndex = 0;
    int endIndex = primes._SZ;

    for(int N=2; N <= 8; ++N)
    {
        for(int i = startIndex; i < endIndex; ++i)
        {
            for(int n = 1; n <= 9; n+=2)
            {
                int t = primes[i] * 10 + n;

                if(isPrime(t))
                    primes._PB(t);
            }
        }
        startIndex = endIndex, endIndex = primes._SZ;
    }

}

int main()
{
//    ifstream fin("test.in");
//    ofstream fout("test.out");
    ifstream fin("sprime.in");
    ofstream fout("sprime.out");

    int N;
    fin >> N;

    generatePrimeRibs();

    for(auto num:  primes)
    {
        if(num >= pow10(N-1) && num < pow10(N))
            fout << num << endl;
    }


    return 0;
}
