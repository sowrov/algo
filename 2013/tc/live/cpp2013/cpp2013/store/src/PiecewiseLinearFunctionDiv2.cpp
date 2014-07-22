#pragma warning ( disable : 4786)
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <bitset>
#include <deque>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 2147483647
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)
#define Rep(_var, _N) for (int _var=0; _var<_N; _var++ )
#define For(_var, _S,  _N) for (int _var=_S; _var<=_N; _var++ )

class PiecewiseLinearFunctionDiv2 {
public:
    vector <int> countSolutions( vector <int> Y, vector <int> query ) {
        vector<int>res(query.size(), 0);
        Rep (q, query.size()) {
            For (i, 1, Y.size()-1) {
                if (Y[i-1]==Y[i]) {
                    if (Y[i]==query[q]) {
                        res[q]=-1;
                        break;
                    }
                } else if(Y[i-1]>Y[i]) {
                    if (query[q]<=Y[i-1] && query[q]>=Y[i]) {
                        res[q]++;
                    }
                } else {
                    if (query[q]>=Y[i-1] && query[q]<=Y[i]) {
                        res[q]++;
                    }
                }
                if (i>1 && query[q]==Y[i-1]) {
                    res[q]--;
                }
            }
        }
        return res;
    }
};

// <editor-fold defaultstate="collapsed" desc="Generated Code">
namespace moj_harness {
    int run_test_case(int);
    void run_test(int casenum = -1, bool quiet = false) {
        if (casenum != -1) {
            if (run_test_case(casenum) == -1 && !quiet) {
                cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
            }
            return;
        }
        
        int correct = 0, total = 0;
        for (int i=0;; ++i) {
            int x = run_test_case(i);
            if (x == -1) {
                if (i >= 100) break;
                continue;
            }
            correct += x;
            ++total;
        }
        
        if (total == 0) {
            cerr << "No test cases run." << endl;
        } else if (correct < total) {
            cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
        } else {
            cerr << "All " << total << " tests passed!" << endl;
        }
    }
    
    template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

    int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, clock_t elapsed) { 
        cerr << "Example " << casenum << "... "; 
        
        string verdict;
        vector<string> info;
        char buf[100];
        
        if (elapsed > CLOCKS_PER_SEC / 200) {
            sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
            info.push_back(buf);
        }
        
        if (expected == received) {
            verdict = "PASSED";
        } else {
            verdict = "FAILED";
        }
        
        cerr << verdict;
        if (!info.empty()) {
            cerr << " (";
            for (int i=0; i<(int)info.size(); ++i) {
                if (i > 0) cerr << ", ";
                cerr << info[i];
            }
            cerr << ")";
        }
        cerr << endl;
        
        if (verdict == "FAILED") {
            cerr << "    Expected: " << expected << endl; 
            cerr << "    Received: " << received << endl; 
        }
        
        return verdict == "PASSED";
    }

    int run_test_case(int casenum) {
        switch (casenum) {
        case 0: {
            int Y[]                   = {1, 4, -1, 2};
            int query[]               = {-2, -1, 0, 1};
            int expected__[]          = {0, 1, 2, 3 };

            clock_t start__           = clock();
            vector <int> received__   = PiecewiseLinearFunctionDiv2().countSolutions(vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(query, query + (sizeof query / sizeof query[0])));
            return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
        }
        case 1: {
            int Y[]                   = {0, 0};
            int query[]               = {-1, 0, 1};
            int expected__[]          = {0, -1, 0 };

            clock_t start__           = clock();
            vector <int> received__   = PiecewiseLinearFunctionDiv2().countSolutions(vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(query, query + (sizeof query / sizeof query[0])));
            return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
        }
        case 2: {
            int Y[]                   = {2, 4, 8, 0, 3, -6, 10};
            int query[]               = {0, 1, 2, 3, 4, 0, 65536};
            int expected__[]          = {3, 4, 5, 4, 3, 3, 0 };

            clock_t start__           = clock();
            vector <int> received__   = PiecewiseLinearFunctionDiv2().countSolutions(vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(query, query + (sizeof query / sizeof query[0])));
            return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
        }
        case 3: {
            int Y[]                   = {-178080289, -771314989, -237251715, -949949900, -437883156, -835236871, -316363230, -929746634, -671700962} ;
            int query[]               = {-673197622, -437883156, -251072978, 221380900, -771314989, -949949900, -910604034, -671700962, -929746634, -316363230};
            int expected__[]          = {8, 6, 3, 0, 7, 1, 4, 8, 3, 4 };

            clock_t start__           = clock();
            vector <int> received__   = PiecewiseLinearFunctionDiv2().countSolutions(vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(query, query + (sizeof query / sizeof query[0])));
            return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
        }

        // custom cases

        /*
        case 4: {
            int Y[]                   = ;
            int query[]               = ;
            int expected__[]          = ;

            clock_t start__           = clock();
            vector <int> received__   = PiecewiseLinearFunctionDiv2().countSolutions(vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(query, query + (sizeof query / sizeof query[0])));
            return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
        }
        //*/
        /*
        case 5: {
            int Y[]                   = ;
            int query[]               = ;
            int expected__[]          = ;

            clock_t start__           = clock();
            vector <int> received__   = PiecewiseLinearFunctionDiv2().countSolutions(vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(query, query + (sizeof query / sizeof query[0])));
            return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
        }
        //*/
        /*
        case 6: {
            int Y[]                   = ;
            int query[]               = ;
            int expected__[]          = ;

            clock_t start__           = clock();
            vector <int> received__   = PiecewiseLinearFunctionDiv2().countSolutions(vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(query, query + (sizeof query / sizeof query[0])));
            return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
        }
        //*/
        default:
            return -1;
        }
    }
}


int main(int argc, char *argv[]) {
    if (argc == 1) {
        moj_harness::run_test();
    } else {
        for (int i=1; i<argc; ++i)
            moj_harness::run_test(atoi(argv[i]));
    }
}
// </editor-fold>
