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

class MysticAndCandiesEasy {
public:
    int minBoxes( int C, int X, vector <int> high ) {
        sort(high.begin(), high.end());
        int v = C-X, s=0, id=0;
        if (v==0) return high.size();
        for (int i=0; i<high.size(); i++) {
            s+=high[i];
            if (s>=v) {
                id=i;
                break;
            }
        }

        if (s==v) {
            return high.size()-(id+1);
        } else {
            return high.size()-id;
        }
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
                   int C                     = 10;
                   int X                     = 10;
                   int high[]                = {20};
                   int expected__            = 1;

                   clock_t start__           = clock();
                   int received__            = MysticAndCandiesEasy().minBoxes(C, X, vector <int>(high, high + (sizeof high / sizeof high[0])));
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         case 1: {
                   int C                     = 10;
                   int X                     = 7;
                   int high[]                = {3, 3, 3, 3, 3};
                   int expected__            = 4;

                   clock_t start__           = clock();
                   int received__            = MysticAndCandiesEasy().minBoxes(C, X, vector <int>(high, high + (sizeof high / sizeof high[0])));
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         case 2: {
                   int C                     = 100;
                   int X                     = 63;
                   int high[]                = {12, 34, 23, 45, 34};
                   int expected__            = 3;

                   clock_t start__           = clock();
                   int received__            = MysticAndCandiesEasy().minBoxes(C, X, vector <int>(high, high + (sizeof high / sizeof high[0])));
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         case 3: {
                   int C                     = 19;
                   int X                     = 12;
                   int high[]                = {12, 9, 15, 1, 6, 4, 9, 10, 10, 10, 14, 14, 1, 1, 12, 10, 9, 2, 3, 6, 1, 7, 3, 4, 10, 3, 14};
                   int expected__            = 22;

                   clock_t start__           = clock();
                   int received__            = MysticAndCandiesEasy().minBoxes(C, X, vector <int>(high, high + (sizeof high / sizeof high[0])));
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         case 4: {
                   int C                     = 326;
                   int X                     = 109;
                   int high[]                = {9, 13, 6, 6, 6, 16, 16, 16, 10, 16, 4, 3, 10, 8, 11, 17, 12, 5, 7, 8, 7, 4, 15, 7, 14, 2, 2, 1, 17, 1, 7, 7, 12, 17, 2, 9, 7, 1, 8, 16, 7, 4, 16, 2, 13, 3, 13, 1, 17, 6};
                   int expected__            = 15;

                   clock_t start__           = clock();
                   int received__            = MysticAndCandiesEasy().minBoxes(C, X, vector <int>(high, high + (sizeof high / sizeof high[0])));
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }

         // custom cases

         /*
         case 5: {
                   int C                     = ;
                   int X                     = ;
                   int high[]                = ;
                   int expected__            = ;

                   clock_t start__           = clock();
                   int received__            = MysticAndCandiesEasy().minBoxes(C, X, vector <int>(high, high + (sizeof high / sizeof high[0])));
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         //*/
         /*
         case 6: {
                   int C                     = ;
                   int X                     = ;
                   int high[]                = ;
                   int expected__            = ;

                   clock_t start__           = clock();
                   int received__            = MysticAndCandiesEasy().minBoxes(C, X, vector <int>(high, high + (sizeof high / sizeof high[0])));
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         //*/
         /*
         case 7: {
                   int C                     = ;
                   int X                     = ;
                   int high[]                = ;
                   int expected__            = ;

                   clock_t start__           = clock();
                   int received__            = MysticAndCandiesEasy().minBoxes(C, X, vector <int>(high, high + (sizeof high / sizeof high[0])));
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
