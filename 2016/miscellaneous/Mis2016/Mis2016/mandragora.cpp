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

int h[100001];
int main() {
    int t, n;
    long long p, sum;

    cin>>t;
    while(t--) {
        cin>>n;
        for (int i=0; i<n; i++) {
            cin>>h[i];
        }
        sort(h, h+n);
        sum = 1;
        p=0;
        for (int i=0; i<n; i++) {

        }
    }
    return 0;
}