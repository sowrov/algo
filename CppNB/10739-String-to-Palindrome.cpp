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
#define Rep(_var, _N) for (int _var=0; _var<_N; _var++ )
#define For(_var, _S,  _N) for (int _var=_S; _var<=_N; _var++ )

int memo[1001][1001];

int main() {
    int t, cas = 1, out;
    string str;
    cin>>t;
    while (t--) {
        cin>>str;
        
        out = 500000;
        int len = str.size();
        str = "-"+str;
        
        for (int i = 0; i <= len; i++) {
            memo[i][i] = 0;
        }
        
        for (int j=2; j<=len; j++) {
            for (int i=1; i<=len-j+1; i++) {
                int c=i+j-1;
                if (str[i]==str[c]) {
                    memo[i][c]=memo[i+1][c-1];
                }
                else {
                    memo[i][c]=1+min(memo[i+1][c-1], min(memo[i][c-1],memo[i+1][c])); 
                }
                //cout<<i<<' '<< c<<' '<< str[i]<< str[i+j-1]<< memo[i][c]<<endl;
            }
        }
        out=memo[1][len];
        
        cout << "Case " << cas++ << ": " << out << endl;
    }
    return 0;
}
