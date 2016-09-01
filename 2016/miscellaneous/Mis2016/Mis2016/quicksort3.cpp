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
int arr[5001];

void qsort3(int s, int e, int n) {
	if (s >= e || s>=n || e<0) {
		return;
	}
	int g = -1, p=e;
	bool sw = false;
	for (int i = s; i < e; i++) {
		if (arr[i] > arr[p] && g==-1) {
			g = i;
		} else if (arr[i] < arr[p] && g != -1) {
			arr[i] ^= arr[g];
			arr[g] ^= arr[i];
			arr[i] ^= arr[g];
			g++;
			sw = true;
		}
	}

	if (g != -1) {
		arr[p] ^= arr[g];
		arr[g] ^= arr[p];
		arr[p] ^= arr[g];
		p = g;
		sw = true;
	}
	if (true) {
		for (int i = 0; i < n; i++) {
			if (i != 0) {
				cout << " ";
			}
			cout << arr[i];
		}
		cout << endl;
	}
	qsort3(s, p - 1, n);
	qsort3(p+1, e, n);
}
int main() {
	int n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	qsort3(0, n-1, n);
	return 0;
}
