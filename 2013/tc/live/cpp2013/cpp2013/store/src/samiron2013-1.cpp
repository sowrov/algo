/**
 * Author        : mmz
 * Problem Name  : samiron2013-1
 * Date          : Thursday, November 07, 2013
 */

#pragma warning ( disable : 4786)
#include <vector>
#include <list>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <ctime>
#include <cstring>
#include <climits>
using namespace std;

#define All(X) X.begin(),X.end()
#define For(i, s, n) for(int i=(s); i<=(n); i++)
#define Rep(i, n) for(int i=0; i<(n); i++)
#define Clr(arr) memset(arr, 0, sizeof(arr))
#define Slr(arr) memset(arr, -1, sizeof(arr))
#define Co continue
#define Re return
#define Sf scanf
#define Pf printf
#define Ss stringstream
#define Ox 2147483647
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)
int main() {
    int totalCount=1500;
    int ccount=1; //1
    int M[3]={1, 1, 1};
    int last=1;
    while(ccount<totalCount) {
        int v2 = 2*M[0];
        int v3 = 3*M[1];
        int v5 = 5*M[2];
        int mv = min(v2, min(v3, v5));
        
        if (mv==v2) {
            M[0]=mv+1;
        } 
        if (mv==v3) {
            M[1]=mv+1;
        }
        if (mv==v5) {
            M[2]=mv+1;
        }
        ccount++;
        last=mv;
        printf("%d\n",last);
    }
    printf("%d\n",last);
    return 0;
}

int main2() {
    int prime[] = {2,3,5};
    int totalCount=100;
    int ccount=0;
    int maxV = 100;
    long long x = 1;
    x<<=40;
    for (long long i=1; ccount<totalCount ; i++) {
        if(i>x) {
            printf("%lld\n",i);
            break;
        }
        int j=0;
        long v=i;
        int count[]={0,0,0};

        while(j<3) {
            while(v>1 && v%prime[j]==0) {
                v/=prime[j];
                count[j]++;
            }
            j++;
        }
        if (v<=1) {
            ccount++;
            //if (ccount%500==0)
                printf("%4d: %d %d %d - %lld\n",ccount, count[0], count[1], count[2], i);
        }
    }
    Re 0;
}
