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

unsigned long long msb64(unsigned long long x) {
	x |= (x >> 1);
	x |= (x >> 2);
	x |= (x >> 4);
	x |= (x >> 8);
	x |= (x >> 16);
	x |= (x >> 32);
	return(x & ~(x >> 1));
}

int main() {
	int t;
	unsigned long long n;
	cin >> t;
	while (t-->0) {
		cin >> n;
		bool rch = true;
		while (n > 1) {
			if ((n & n - 1) == 0) {
				n >>=1;
			} else {
				n -= msb64(n);
			}
			rch = !rch;
		}
		if (rch) {
			cout << "Richard";
		} else {
			cout << "Louise";
		}
		cout << endl;
	}
	return 0;
}
