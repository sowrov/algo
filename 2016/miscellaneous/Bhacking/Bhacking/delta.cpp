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
	int v, pv;
	vector<int> del;
	while (scanf("%d", &v) == 1) {
		if (del.size() == 0) {
			del.push_back(v);
			pv = v;
		} else {
			del.push_back(v-pv);
			pv = v;
		}
	}
	cout << del[0];
	for (int i = 1; i < del.size(); i++) {
		cout << " ";
		if (del[i] > 127 || del[i] < -127) {
		
			cout << -128 << " " ;
		}
		cout << del[i];
	}
	cout << endl;
	return 0;
}
