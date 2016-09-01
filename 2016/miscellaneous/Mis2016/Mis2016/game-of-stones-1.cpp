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

int memo[101][2];

bool dp(int n, bool who) {
	if (n < 0) return true;
	if (n < 2) return false;
	
	int *me = &memo[n][who];
	if (*me != -1) return *me;
	bool win = dp(n - 2, !who);
	win &= dp(n - 3, !who);
	win &= dp(n - 5, !who);
	*me = !win;
	return *me;
}

int main() {
	int t, n;
	
	clrm(memo);
	cin >> t;
	while (t--) {
		cin >> n;
		dp(n, true);
		if (memo[n][true]==1) {
			cout << "First\n";
		} else {
			cout << "Second\n";
		}
	}
	return 0;
}
