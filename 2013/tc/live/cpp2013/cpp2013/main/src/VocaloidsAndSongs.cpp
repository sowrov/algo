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
int dp[51][51][51][51];
int mod=1000000007;

class VocaloidsAndSongs {
public:
    int count( int S, int gumi, int ia, int mayu ) {
		Nclr(dp);
		return count2(S, gumi, ia, mayu);
    }

	int count2(int S, int gu, int ia, int may ) {
		if (gu<0 || ia<0 || may<0) return -1;

		if (gu==0 && ia==0 && may==0) {
			if (S==0) return 1;
			return -1;
		}
		if (S==0) return -1;
		int& out = dp[S][gu][ia][may];
		if (out!=-1) return out;
		int v=0;
		out=0;
		v = count2(S-1, gu, ia, may-1);
		out += v==-1?0:v;
		out %= mod;
		v = count2(S-1, gu, ia-1, may);
		out += v==-1?0:v;
		out %= mod;
		v = count2(S-1, gu-1, ia, may);
		out += v==-1?0:v;
		out %= mod;
		v = count2(S-1, gu-1, ia-1, may);
		out += v==-1?0:v;
		out %= mod;
		v = count2(S-1, gu-1, ia, may-1);
		out += v==-1?0:v;
		out %= mod;
		v = count2(S-1, gu, ia-1, may-1);
		out += v==-1?0:v;
		out %= mod;
		v = count2(S-1, gu-1, ia-1, may-1);
		out += v==-1?0:v;
		out %= mod;

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
                   int S                     = 3;
                   int gumi                  = 1;
                   int ia                    = 1;
                   int mayu                  = 1;
                   int expected__            = 6;

                   clock_t start__           = clock();
                   int received__            = VocaloidsAndSongs().count(S, gumi, ia, mayu);
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         case 1: {
                   int S                     = 3;
                   int gumi                  = 3;
                   int ia                    = 1;
                   int mayu                  = 1;
                   int expected__            = 9;

                   clock_t start__           = clock();
                   int received__            = VocaloidsAndSongs().count(S, gumi, ia, mayu);
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         case 2: {
                   int S                     = 50;
                   int gumi                  = 10;
                   int ia                    = 10;
                   int mayu                  = 10;
                   int expected__            = 0;

                   clock_t start__           = clock();
                   int received__            = VocaloidsAndSongs().count(S, gumi, ia, mayu);
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         case 3: {
                   int S                     = 18;
                   int gumi                  = 12;
                   int ia                    = 8;
                   int mayu                  = 9;
                   int expected__            = 81451692;

                   clock_t start__           = clock();
                   int received__            = VocaloidsAndSongs().count(S, gumi, ia, mayu);
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         case 4: {
                   int S                     = 50;
                   int gumi                  = 25;
                   int ia                    = 25;
                   int mayu                  = 25;
                   int expected__            = 198591037;

                   clock_t start__           = clock();
                   int received__            = VocaloidsAndSongs().count(S, gumi, ia, mayu);
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }

         // custom cases

         /*
         case 5: {
                   int S                     = ;
                   int gumi                  = ;
                   int ia                    = ;
                   int mayu                  = ;
                   int expected__            = ;

                   clock_t start__           = clock();
                   int received__            = VocaloidsAndSongs().count(S, gumi, ia, mayu);
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         //*/
         /*
         case 6: {
                   int S                     = ;
                   int gumi                  = ;
                   int ia                    = ;
                   int mayu                  = ;
                   int expected__            = ;

                   clock_t start__           = clock();
                   int received__            = VocaloidsAndSongs().count(S, gumi, ia, mayu);
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         //*/
         /*
         case 7: {
                   int S                     = ;
                   int gumi                  = ;
                   int ia                    = ;
                   int mayu                  = ;
                   int expected__            = ;

                   clock_t start__           = clock();
                   int received__            = VocaloidsAndSongs().count(S, gumi, ia, mayu);
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
