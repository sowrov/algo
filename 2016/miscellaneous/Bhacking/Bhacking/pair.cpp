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

int main() {
	vector<int> arr;
	int n, m, v;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> v;
		arr.push_back(v);
	}
	bool found = false;
	for (int i = 0; i < m && !found; i++) {
		for (int j = i+1; j < m; j++) {
			if (arr[i] + arr[j] == n) {
				cout << "1" << endl;
				found = true;
				break;
			}
		}
	}
	if (!found) {
		cout << "0" << endl;
	}
	return 0;
}
