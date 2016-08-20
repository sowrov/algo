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
#define BN 220000

int memo[41];
int primeCount[BN];

//prime sieve
void runSieve(int upperBound) {
	int upperBoundSquareRoot = (int)sqrt((double)upperBound);
	bool *isComposite = new bool[upperBound + 1];
	memset(isComposite, 0, sizeof(bool) * (upperBound + 1));
	int count = 0;
	primeCount[1] = 0;
	for (int m = 2; m <= upperBoundSquareRoot; m++) {
		if (!isComposite[m]) {
			count++;
			//cout << m << " ";
			for (int k = m * m; k <= upperBound; k += m)
				isComposite[k] = true;
		}
		primeCount[m] = count;
	}

	for (int m = upperBoundSquareRoot; m <= upperBound; m++) {
		if (!isComposite[m]) {
			count++;
			//cout << m << " ";
		}
		primeCount[m] = count;
	}
	delete[] isComposite;
}

int dp(int n) {
	if (n < 0) return 0;
	if (n == 0) return 1;
	int *me = &memo[n];
	if (*me != -1) return *me;

	*me = dp(n - 1) + dp(n - 4);
	return *me;
}
int main() {
	int t, n;
	cin >> t;
	runSieve(BN-1);

	while (t--) {
		cin >> n;
		clrm(memo);
		int m = dp(n);

		cout << primeCount[m] << endl;
	}
	return 0;
}
