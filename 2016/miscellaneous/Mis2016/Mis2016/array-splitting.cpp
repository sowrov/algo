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
#define BN 16385

int A[BN];
int sum[BN][BN];
//int memo[BN][BN];

void show(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			cout << i << " " << j << " " << sum[i][j] << endl;
		}
	}
}

int dp(int s, int e) {
	if (s == e) {
		return 0;
	}
	cout << " - " << s << " " << e << endl;

	if (sum[e][s] != -1) {
		return sum[e][s];
	}
	int mx = -1;
	for (int i = s; i < e; i++) {
		if (sum[s][i] == sum[i + 1][e]) {
			mx = max(dp(s, i), mx);
			mx = max(dp(i+1, e), mx);
		}
	}
	sum[e][s] = mx + 1;
	return mx + 1;
}
int main() {
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		clrm(sum);
		for (int i = 0; i < n; i++) {
			cin >> A[i];
		}
		for (int s = 0; s < n; s++) {
			for (int k = 1; k <= n && s+k<=n; k++) {
				int tk = k;
				int e = s;
				int x = 0;
				while (tk--) {
					x += A[e++];
				}
				sum[s][e - 1] = x;
			}
		}
		//show(n);
		cout << dp(0, n-1)<<endl;
	}
	return 0;
}
