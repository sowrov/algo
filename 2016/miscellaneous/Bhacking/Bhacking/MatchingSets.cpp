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

#define BN 100001

vector<int> X, Y;
int main() {
	int n, v;
	cin>>n;
	for (int i=0; i<n; i++) {
		cin>>v;
		X.push_back(v);
	}

	for (int i=0; i<n; i++) {
		cin>>v;
		Y.push_back(v);
	}
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	long long dec= 0;
	long long inc=0;
	for (int i=0; i<n; i++) {
		if (X[i]<Y[i]) {
			inc += abs(X[i]-Y[i]);
		} else {
			dec += abs(X[i]-Y[i]);
		}
	}
	if (inc==dec) {
		cout<<inc<<endl;
	} else {
		cout<<"-1";
	}
	
	return 0;
}
