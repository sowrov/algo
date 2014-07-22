/**
 * Author        : mmz
 * Problem Name  : ALEXNUMB
 * Date          : Sunday, December 08, 2013
 */

#pragma warning ( disable : 4786)
#include <vector>
#include <list>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <ctime>
#include <cstring>
#include <climits>
using namespace std;

#define All(X) X.begin(),X.end()
#define For(i, s, n) for(int i=(s); i<=(n); i++)
#define Rep(i, n) for(int i=0; i<(n); i++)
#define Clr(arr) memset(arr, 0, sizeof(arr))
#define Slr(arr) memset(arr, -1, sizeof(arr))
#define Co continue
#define Re return
#define Sf scanf
#define Pf printf
#define Ss stringstream
#define Ox 2147483647
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)
int main() {
    int T;
    Sf("%d", &T);
    while (T--) {
        int n, v;
        Sf("%d", &n);
        for (int i=0; i<n; i++) {
            Sf("%d", &v);
        }
        long long out = n;
        out *= (n-1);
        out >>=1;
        Pf("%lld\n", out);
    }
    Re 0;
}
