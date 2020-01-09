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

class DoubleWeights {
public:
	int minv= 10000000;
	bool flag[21];
	vector <string> W1, W2;

	void dfs(int node, int s1, int s2) {
		if (node == 1) {
			minv = min(minv, s1*s2);
			return;
		}
		if ( s1*s2 > minv) return;
		//cout << node<<endl;
		

		for (int i = 0; i < W1.size(); i++) {
			if (!flag[i] && W1[node][i] != '.') {
				//pW1[d] = W1[node][i] - '0';
				//pW2[d] = W2[node][i] - '0';
				flag[node] = true;
				dfs(i, s1 + int(W1[node][i] - '0'), s2+ int(W2[node][i] - '0'));
				flag[node] = false;
			}
		}
		
		
	}
    int minimalCost( vector <string> weight1, vector <string> weight2 ) {
		//flag[0] = false;
		W1 = weight1;
		W2 = weight2;
		dfs(0, 0, 0);
		return minv == 10000000 ? -1 : minv;
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
                   string weight1[]          = {"..14",
 "..94",
 "19..",
 "44.."};
                   string weight2[]          = {"..94",
 "..14",
 "91..",
 "44.."};
                   int expected__            = 64;

                   clock_t start__           = clock();
                   int received__            = DoubleWeights().minimalCost(vector <string>(weight1, weight1 + (sizeof weight1 / sizeof weight1[0])), vector <string>(weight2, weight2 + (sizeof weight2 / sizeof weight2[0])));
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         case 1: {
                   string weight1[]          = {"..14",
 "..14",
 "11..",
 "44.."};
                   string weight2[]          = {"..94",
 "..94",
 "99..",
 "44.."};
                   int expected__            = 36;

                   clock_t start__           = clock();
                   int received__            = DoubleWeights().minimalCost(vector <string>(weight1, weight1 + (sizeof weight1 / sizeof weight1[0])), vector <string>(weight2, weight2 + (sizeof weight2 / sizeof weight2[0])));
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         case 2: {
                   string weight1[]          = {"..",
 ".."};
                   string weight2[]          = {"..",
 ".."};
                   int expected__            = -1;

                   clock_t start__           = clock();
                   int received__            = DoubleWeights().minimalCost(vector <string>(weight1, weight1 + (sizeof weight1 / sizeof weight1[0])), vector <string>(weight2, weight2 + (sizeof weight2 / sizeof weight2[0])));
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         case 3: {
                   string weight1[]          = {".....9",
 "..9...",
 ".9.9..",
 "..9.9.",
 "...9.9",
 "9...9."};
                   string weight2[]          = {".....9",
 "..9...",
 ".9.9..",
 "..9.9.",
 "...9.9",
 "9...9."};
                   int expected__            = 2025;

                   clock_t start__           = clock();
                   int received__            = DoubleWeights().minimalCost(vector <string>(weight1, weight1 + (sizeof weight1 / sizeof weight1[0])), vector <string>(weight2, weight2 + (sizeof weight2 / sizeof weight2[0])));
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         case 4: {
                   string weight1[]          = {".4...1",
 "4.1...",
 ".1.1..",
 "..1.1.",
 "...1.1",
 "1...1."};
                   string weight2[]          = {".4...1",
 "4.1...",
 ".1.1..",
 "..1.1.",
 "...1.1",
 "1...1."};
                   int expected__            = 16;

                   clock_t start__           = clock();
                   int received__            = DoubleWeights().minimalCost(vector <string>(weight1, weight1 + (sizeof weight1 / sizeof weight1[0])), vector <string>(weight2, weight2 + (sizeof weight2 / sizeof weight2[0])));
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }

         // custom cases
		 

         //*
         case 5: {
                   string weight1[]          = { "....673......1.358", "..2.9....6..6.826.", ".2.3...6....5..7..", "..3.2..8....2.....", "69.2.7.....4.....1", "7...7.4..19......7", "3....4.41..2.5744.", "..68..4.8.3..85...", "......18.7.....1..", ".6...1..7.68...325", ".....9.3.6.8.29433", "....4.2..88.9.....", ".652.......9.5411.", "1.....58..2.5.79.9", ".8....75..9.47.9..", "327...4.134.199.2.", "56....4..23.1..2.2", "8...17...53..9..2." };
                   string weight2[]          = { "....673......1.358", "..2.9....6..6.826.", ".2.3...6....5..7..", "..3.2..8....2.....", "69.2.7.....4.....1", "7...7.4..19......7", "3....4.41..2.5744.", "..68..4.8.3..85...", "......18.7.....1..", ".6...1..7.68...325", ".....9.3.6.8.29433", "....4.2..88.9.....", ".652.......9.5411.", "1.....58..2.5.79.9", ".8....75..9.47.9..", "327...4.134.199.2.", "56....4..23.1..2.2", "8...17...53..9..2." };
                   int expected__            = 25;

                   clock_t start__           = clock();
                   int received__            = DoubleWeights().minimalCost(vector <string>(weight1, weight1 + (sizeof weight1 / sizeof weight1[0])), vector <string>(weight2, weight2 + (sizeof weight2 / sizeof weight2[0])));
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         //*/
         //*
         case 6: {
                   string weight1[]          = { ".....9", "..9...", ".9.9..", "..9.9.", "...9.9", "9...9." };
                   string weight2[]          = { ".....9", "..9...", ".9.9..", "..9.9.", "...9.9", "9...9." };
                   int expected__            = 2025;

                   clock_t start__           = clock();
                   int received__            = DoubleWeights().minimalCost(vector <string>(weight1, weight1 + (sizeof weight1 / sizeof weight1[0])), vector <string>(weight2, weight2 + (sizeof weight2 / sizeof weight2[0])));
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         //*/
         /*
         case 7: {
                   string weight1[]          = ;
                   string weight2[]          = ;
                   int expected__            = ;

                   clock_t start__           = clock();
                   int received__            = DoubleWeights().minimalCost(vector <string>(weight1, weight1 + (sizeof weight1 / sizeof weight1[0])), vector <string>(weight2, weight2 + (sizeof weight2 / sizeof weight2[0])));
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
