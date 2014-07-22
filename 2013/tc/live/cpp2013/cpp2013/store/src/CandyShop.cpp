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
int grid[401][401];

class CandyShop {
public:
    int countProbablePlaces( vector <int> X, vector <int> Y, vector <int> R ) {
		Zclr(grid);

		for (int i=0; i<X.size(); i++) {
			int x=X[i]+200;
			int y=Y[i]+200;
			int r=0;
			int a=1;
			for (int s=y-R[i]; s<=y+R[i]; s++) {
				for (int t=x-R[i]; t<=x+R[i]; t++) {
					if (t>=(x-r) && t<=(x+r)) {
						grid[s][t]++;
					}
				}
				r+=a;
				if (r==R[i]) {
					a=-1;
				}
			}
		}
		int si=X.size();
		int out=0;

		for (int i=0; i<401; i++) {
			for (int j=0; j<401; j++) {
				if (grid[i][j]==si) {
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
                   int X[]                   = {0};
                   int Y[]                   = {0};
                   int R[]                   = {1};
                   int expected__            = 5;

                   clock_t start__           = clock();
                   int received__            = CandyShop().countProbablePlaces(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(R, R + (sizeof R / sizeof R[0])));
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         case 1: {
                   int X[]                   = {0};
                   int Y[]                   = {0};
                   int R[]                   = {2};
                   int expected__            = 13;

                   clock_t start__           = clock();
                   int received__            = CandyShop().countProbablePlaces(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(R, R + (sizeof R / sizeof R[0])));
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         case 2: {
                   int X[]                   = {2,3};
                   int Y[]                   = {1,-1};
                   int R[]                   = {2,2};
                   int expected__            = 4;

                   clock_t start__           = clock();
                   int received__            = CandyShop().countProbablePlaces(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(R, R + (sizeof R / sizeof R[0])));
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         case 3: {
                   int X[]                   = {2,3,5};
                   int Y[]                   = {1,-1,0};
                   int R[]                   = {2,2,3};
                   int expected__            = 3;

                   clock_t start__           = clock();
                   int received__            = CandyShop().countProbablePlaces(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(R, R + (sizeof R / sizeof R[0])));
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         case 4: {
                   int X[]                   = {-100,-100,-100,0,0,0,100,100,100};
                   int Y[]                   = {-100,0,100,-100,0,100,-100,0,100};
                   int R[]                   = {1,1,1,1,1,1,1,1,1};
                   int expected__            = 0;

                   clock_t start__           = clock();
                   int received__            = CandyShop().countProbablePlaces(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(R, R + (sizeof R / sizeof R[0])));
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         case 5: {
                   int X[]                   = {-3,3,5,5};
                   int Y[]                   = {4,5,-2,0};
                   int R[]                   = {10,11,8,6};
                   int expected__            = 33;

                   clock_t start__           = clock();
                   int received__            = CandyShop().countProbablePlaces(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(R, R + (sizeof R / sizeof R[0])));
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }

         // custom cases

         /*
         case 6: {
                   int X[]                   = ;
                   int Y[]                   = ;
                   int R[]                   = ;
                   int expected__            = ;

                   clock_t start__           = clock();
                   int received__            = CandyShop().countProbablePlaces(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(R, R + (sizeof R / sizeof R[0])));
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         //*/
         /*
         case 7: {
                   int X[]                   = ;
                   int Y[]                   = ;
                   int R[]                   = ;
                   int expected__            = ;

                   clock_t start__           = clock();
                   int received__            = CandyShop().countProbablePlaces(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(R, R + (sizeof R / sizeof R[0])));
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         //*/
         /*
         case 8: {
                   int X[]                   = ;
                   int Y[]                   = ;
                   int R[]                   = ;
                   int expected__            = ;

                   clock_t start__           = clock();
                   int received__            = CandyShop().countProbablePlaces(vector <int>(X, X + (sizeof X / sizeof X[0])), vector <int>(Y, Y + (sizeof Y / sizeof Y[0])), vector <int>(R, R + (sizeof R / sizeof R[0])));
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
