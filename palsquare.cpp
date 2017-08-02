/*
ID: sak0909
PROG: palsquare
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

bool isPalindrome(string ip)
{
    int i=0; int j=ip.size()-1;

    while(i<j)
    {
        if(ip[i] != ip[j])
            return false;

        i++; j--;
    }
    return true;
}

string getNumberInBase(int ip, int base)
{
    vector<char> T={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K'};
    string ans;
    int b; char c; OSS S;
    while(ip > 0)
    {
        b = ip%base;
        c = T[b];
        S << c;
        ip /= base;
    }
    ans = S.str();
    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    ifstream fin("palsquare.in");
    ofstream fout("palsquare.out");
//    ifstream fin("test.in");
//    ofstream fout("test.out");

    int B;
    fin >> B;

    for (int i= 1; i <=300; ++i)
    {
        string t = getNumberInBase(i*i, B);
        if(isPalindrome(t))
            fout <<  getNumberInBase(i, B) << " " << t << endl;
    }


    return 0;
}
