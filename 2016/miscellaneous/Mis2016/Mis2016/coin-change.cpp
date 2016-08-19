#include "iomanip"
#include "vector"
#include "utility"
#include "cstring"
#include "numeric"
#include "set"
#include "ctime"
#include "fstream"
#include "cstdlib"
#include "bitset"
#include "cctype"
#include "map"
#include "algorithm"
#include "cassert"
#include "cstdio"
#include "string"
#include "list"
#include "sstream"
#include "iostream"
#include "deque"
#include "stack"
#include "cmath"
#include "queue"
#include "functional"

using namespace std;

#define clrz(_arr) memset(_arr, 0, sizeof(_arr))
#define clrm(_arr) memset(_arr, -1, sizeof(_arr))
#define P31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)
#define BN 51

int coins[BN];
int memo[252];

int dp(int t, int p, int m) {
    if (t<0 || p>=m) {
        return -1;
    }
    if (t==0) {
        return 1;
    }
    if (memo[t]!=-1) return memo[t];

    int mx = max(dp(t-coins[p], p, m), dp(t, p+1, m));

    memo[t]=mx;
    return mx;
}
int main () {
    int n, m;
    cin>>n>>m;
    clrm(memo);
    for (int i=0; i<m; i++) {
        cin>>coins[i];
    }

    cout<<dp(n, 0, m)<<endl;
    return 0;
}
