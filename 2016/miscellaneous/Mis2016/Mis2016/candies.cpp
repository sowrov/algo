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

int r[BN];
int cand[BN];


int main () {
    int n;

    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>r[i];
    }

    int k=-1;
    for (int i=0; i<n; i++) {
        cand[i] = 1;
        if (i>0 && r[i] > r[i-1]) {
            cand[i] =cand[i-1]+1;
        } else if (i>0 && r[i] < r[i-1]) {
            cand[i] =cand[i-1]-1;
        }
        
    }
    return 0;
}