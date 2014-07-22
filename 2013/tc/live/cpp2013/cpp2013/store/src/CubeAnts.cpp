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

class CubeAnts {
public:
    int getMinimumSteps( vector <int> pos ) {
        int maxM=-1;
        for (int i=0; i<pos.size(); i++) {
            if (pos[i]==0) {
                maxM = max(maxM, 0);
            } else if (pos[i]==1 || pos[i]==3 || pos[i]==4) {
                maxM = max(maxM, 1);
            } else if (pos[i]==2 || pos[i]==5 || pos[i]==7) {
                maxM = max(maxM, 2);
            } else if (pos[i]==6) {
                maxM = max(maxM, 3);
            }
        }
        return maxM;
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
                   int pos[]                 = {0,1,1};
                   int expected__            = 1;

                   clock_t start__           = clock();
                   int received__            = CubeAnts().getMinimumSteps(vector <int>(pos, pos + (sizeof pos / sizeof pos[0])));
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         case 1: {
                   int pos[]                 = {5,4};
                   int expected__            = 2;

                   clock_t start__           = clock();
                   int received__            = CubeAnts().getMinimumSteps(vector <int>(pos, pos + (sizeof pos / sizeof pos[0])));
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         case 2: {
                   int pos[]                 = {0};
                   int expected__            = 0;

                   clock_t start__           = clock();
                   int received__            = CubeAnts().getMinimumSteps(vector <int>(pos, pos + (sizeof pos / sizeof pos[0])));
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         case 3: {
                   int pos[]                 = {6,1,6};
                   int expected__            = 3;

                   clock_t start__           = clock();
                   int received__            = CubeAnts().getMinimumSteps(vector <int>(pos, pos + (sizeof pos / sizeof pos[0])));
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         case 4: {
                   int pos[]                 = {7,7,3,3,7,7,3,3};
                   int expected__            = 2;

                   clock_t start__           = clock();
                   int received__            = CubeAnts().getMinimumSteps(vector <int>(pos, pos + (sizeof pos / sizeof pos[0])));
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }

         // custom cases

         /*
         case 5: {
                   int pos[]                 = ;
                   int expected__            = ;

                   clock_t start__           = clock();
                   int received__            = CubeAnts().getMinimumSteps(vector <int>(pos, pos + (sizeof pos / sizeof pos[0])));
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         //*/
         /*
         case 6: {
                   int pos[]                 = ;
                   int expected__            = ;

                   clock_t start__           = clock();
                   int received__            = CubeAnts().getMinimumSteps(vector <int>(pos, pos + (sizeof pos / sizeof pos[0])));
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         //*/
         /*
         case 7: {
                   int pos[]                 = ;
                   int expected__            = ;

                   clock_t start__           = clock();
                   int received__            = CubeAnts().getMinimumSteps(vector <int>(pos, pos + (sizeof pos / sizeof pos[0])));
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
