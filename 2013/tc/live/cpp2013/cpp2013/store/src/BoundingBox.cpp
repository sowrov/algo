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
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)
#define Rep(_var, _N) for (int _var=0; _var<_N; _var++ )
#define For(_var, _S,  _N) for (int _var=_S; _var<=_N; _var++ )

class BoundingBox {
public:
    int smallestArea( vector <int> X, vector <int> Y ) {
        int by=-500, bx=-500, sy=1000, sx=1000;
        int byi, bxi, syi, sxi;
        for (int i=0; i<X.size(); i++) {
            if (X[i]>bx) {
                bx=X[i];
                bxi=i;
            }
            if (Y[i]>by) {
                by=Y[i];
                byi=i;
            }
            if (X[i]<sx) {
                sx=X[i];
                sxi=i;
            }
            if (Y[i]<sy) {
                sy=Y[i];
                syi=i;
            }
        }
        double h = sqrtl((by-sy)*(by-sy));
        double w = sqrtl((bx-sx)*(bx-sx));
        return h*w;
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
    
    int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) { 
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
                   int X[]                   = {0,1};
                   int Y[]                   = {1,0};
                   int expected__            = 1;

                   clock_t start__           = clock();
                   int received__            = BoundingBox().smallestArea(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])));
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         case 1: {
                   int X[]                   = {0,-2,-1};
                   int Y[]                   = {-1,-1,-2};
                   int expected__            = 2;

                   clock_t start__           = clock();
                   int received__            = BoundingBox().smallestArea(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])));
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         case 2: {
                   int X[]                   = {0,0,1,0,-1,2};
                   int Y[]                   = {0,1,2,-2,0,-1};
                   int expected__            = 12;

                   clock_t start__           = clock();
                   int received__            = BoundingBox().smallestArea(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])));
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         case 3: {
                   int X[]                   = {9,-88,-40,98,-55,41,-38};
                   int Y[]                   = {-65,56,-67,7,-58,33,68};
                   int expected__            = 25110;

                   clock_t start__           = clock();
                   int received__            = BoundingBox().smallestArea(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])));
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }

         // custom cases

         /*
         case 4: {
                   int X[]                   = ;
                   int Y[]                   = ;
                   int expected__            = ;

                   clock_t start__           = clock();
                   int received__            = BoundingBox().smallestArea(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])));
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         //*/
         /*
         case 5: {
                   int X[]                   = ;
                   int Y[]                   = ;
                   int expected__            = ;

                   clock_t start__           = clock();
                   int received__            = BoundingBox().smallestArea(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])));
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         //*/
         /*
         case 6: {
                   int X[]                   = ;
                   int Y[]                   = ;
                   int expected__            = ;

                   clock_t start__           = clock();
                   int received__            = BoundingBox().smallestArea(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])));
                   return verify_case(casenum, expected__, received__, clock()-start__);
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
