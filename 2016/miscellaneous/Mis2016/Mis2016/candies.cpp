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
struct Pair {
    int s, e;
    char t;
};

vector<Pair> pList;

int main () {
    int n;
    //pList = new vector<Pair>();
    pList.clear();
    cin>>n;
    cin>>r[0];
    Pair p;
    p.s=0;
    p.e=-1;
    p.t='x';
    for (int i=1; i<n; i++) {
        cin>>r[i];
        if (r[i]<r[i-1]) {
            if(p.t=='i' || p.t=='e') {
                p.e=i-1;
                pList.push_back(p);
                p.s=i-1; //decreasing start from last big number
                p.e=-1;
            }
            p.t='d';
        } else if (r[i]>r[i-1]){
            if(p.t=='d' || p.t=='e') {
                p.e=i-1;
                pList.push_back(p);
                p.s=i-1;
                p.e=-1;
            }
            p.t='i';
        } else {
            if(p.t=='d' || p.t=='i') {
                p.e=i-1;
                pList.push_back(p);
                p.s=i; //ignore last number
                p.e=-1;
            }
            p.t='e';
        }
    }

    if (p.e==-1) {
        if (p.t=='x') {
            p.t='i';
        }
        p.e=n-1;
        pList.push_back(p);
    }
    long long sum=0;
    int v=0;
    for (int i=0; i<pList.size(); i++) {
        if (pList[i].t=='e' || pList[i].t=='i') {
            if (pList[i].s==0 || pList[i].s==pList[i].e || pList[i].t=='e') {
                cand[pList[i].s]=1;
            }
            for (int j=pList[i].s+1; j<=pList[i].e; j++) {
                if (pList[i].t=='i') {
                    cand[j]=cand[j-1]+1;
                } else {
                    cand[j]=1;
                }
            }
        } else {
            v=1;
            for (int j=pList[i].e; j>pList[i].s; j--) {
                cand[j]=v++;
            }
            if (v>cand[pList[i].s]) {
                cand[pList[i].s]=v;
            }
        }
    }

    for (int i=0; i<n; i++) {
        //cout<<cand[i]<<" ";
        sum+=cand[i];
    }
    //cout<<" -- "<<endl;
    cout<<sum<<endl;
    return 0;
}