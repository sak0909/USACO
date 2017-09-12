/*
ID: sak0909
PROG: wormhole
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


#define MAX_N 12

int N, X[MAX_N+1], Y[MAX_N+1];
int partner[MAX_N+1];
int next_on_right[MAX_N+1];

bool cycle_exists(void)
{
  for (int start=1; start<=N; start++) {
    // does there exist a cylce starting from start
    int pos = start;
    for (int count=0; count<N; count++)
      pos = next_on_right[partner[pos]];
    if (pos != 0) return true;
  }
  return false;
}

// count all solutions
int solve(void)
{
  // find first unpaired wormhole
  int i, total=0;
  for (i=1; i<=N; i++)
    if (partner[i] == 0) break;

  // everyone paired?
  if (i > N) {
    if (cycle_exists()) return 1;
    else return 0;
  }

  // try pairing i with all possible other wormholes j
  for (int j=i+1; j<=N; j++)
    if (partner[j] == 0) {
      // try pairing i & j, let recursion continue to
      // generate the rest of the solution
      partner[i] = j;
      partner[j] = i;
      total += solve();
      partner[i] = partner[j] = 0;
    }
  return total;
}

int main(void)
{
  ifstream fin("wormhole.in");
  fin >> N;
  for (int i=1; i<=N; i++) fin >> X[i] >> Y[i];
  fin.close();

  for (int i=1; i<=N; i++) // set next_on_right[i]...
    for (int j=1; j<=N; j++)
      if (X[j] > X[i] && Y[i] == Y[j]) // j right of i...
    if (next_on_right[i] == 0 ||
        X[j]-X[i] < X[next_on_right[i]]-X[i])
      next_on_right[i] = j;

  ofstream fout("wormhole.out");
  fout << solve() << "\n";
  fout.close();
  return 0;
}
