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

class MagicalStringDiv2 {
public:
    int minimalMoves( string S ) {
		int out=0, hlf = S.size()/2;
		for (int i=0; i<S.size(); i++) {
			if (i<hlf) {
				if (S[i]!='>') {
					out++;
				}
			} else {
				if (S[i]!='<') {
					out++;
				}
			}
		}

		return out;
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
                   string S                  = ">><<><";
                   int expected__            = 2;

                   clock_t start__           = clock();
                   int received__            = MagicalStringDiv2().minimalMoves(S);
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         case 1: {
                   string S                  = ">>>><<<<";
                   int expected__            = 0;

                   clock_t start__           = clock();
                   int received__            = MagicalStringDiv2().minimalMoves(S);
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         case 2: {
                   string S                  = "<<>>";
                   int expected__            = 4;

                   clock_t start__           = clock();
                   int received__            = MagicalStringDiv2().minimalMoves(S);
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         case 3: {
                   string S                  = "<><<<>>>>><<>>>>><>><<<>><><><><<><<<<<><<>>><><><";
                   int expected__            = 20;

                   clock_t start__           = clock();
                   int received__            = MagicalStringDiv2().minimalMoves(S);
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }

         // custom cases

         /*
         case 4: {
                   string S                  = ;
                   int expected__            = ;

                   clock_t start__           = clock();
                   int received__            = MagicalStringDiv2().minimalMoves(S);
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         //*/
         /*
         case 5: {
                   string S                  = ;
                   int expected__            = ;

                   clock_t start__           = clock();
                   int received__            = MagicalStringDiv2().minimalMoves(S);
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         //*/
         /*
         case 6: {
                   string S                  = ;
                   int expected__            = ;

                   clock_t start__           = clock();
                   int received__            = MagicalStringDiv2().minimalMoves(S);
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
