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

class PalindromicSubstringsDiv2 {
public:
    int count( vector <string> S1, vector <string> S2 ) {
        string s="";
        for (int i=0; i<S1.size(); i++) {
            s+=S1[i];
        }
        for (int i=0; i<S2.size(); i++) {
            s+=S2[i];
        }
        int r=s.size();

        for (int i=1; i<s.size(); i++) {
            for (int j=0; j+i<s.size(); j++) {
                if (isPal(s, j, j+i)) {
                    r++;
                }
            }
        }
        //printf("\n---\n");
        return r;
    }

    bool isPal(string& str, int s, int e) {
        int len=e-s+1;
        int v=0;
        //printf("%d %d\n", s, e);
        for (int i=s; v<len/2; i++, v++) {
            if (str[i]!=str[e-i+s]) {
                return false;
            }
        }
        return true;
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
                   string S1[]               = {""};
                   string S2[]               = {"abba"};
                   int expected__            = 4;

                   clock_t start__           = clock();
                   int received__            = PalindromicSubstringsDiv2().count(vector <string>(S1, S1 + (sizeof S1 / sizeof S1[0])), vector <string>(S2, S2 + (sizeof S2 / sizeof S2[0])));
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         case 1: {
                   string S1[]               = {"zaz"};
                   // string S2[]            = empty, commented out for VC++;
                   int expected__            = 4;

                   clock_t start__           = clock();
                   int received__            = PalindromicSubstringsDiv2().count(vector <string>(S1, S1 + (sizeof S1 / sizeof S1[0])), vector <string>());
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         case 2: {
                   string S1[]               = {"top"};
                   string S2[]               = {"coder"};
                   int expected__            = 8;

                   clock_t start__           = clock();
                   int received__            = PalindromicSubstringsDiv2().count(vector <string>(S1, S1 + (sizeof S1 / sizeof S1[0])), vector <string>(S2, S2 + (sizeof S2 / sizeof S2[0])));
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         case 3: {
                   // string S1[]            = empty, commented out for VC++;
                   string S2[]               = {"daata"};
                   int expected__            = 7;

                   clock_t start__           = clock();
                   int received__            = PalindromicSubstringsDiv2().count(vector <string>(), vector <string>(S2, S2 + (sizeof S2 / sizeof S2[0])));
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }

         // custom cases

         /*
         case 4: {
                   string S1[]               = ;
                   string S2[]               = ;
                   int expected__            = ;

                   clock_t start__           = clock();
                   int received__            = PalindromicSubstringsDiv2().count(vector <string>(S1, S1 + (sizeof S1 / sizeof S1[0])), vector <string>(S2, S2 + (sizeof S2 / sizeof S2[0])));
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         //*/
         /*
         case 5: {
                   string S1[]               = ;
                   string S2[]               = ;
                   int expected__            = ;

                   clock_t start__           = clock();
                   int received__            = PalindromicSubstringsDiv2().count(vector <string>(S1, S1 + (sizeof S1 / sizeof S1[0])), vector <string>(S2, S2 + (sizeof S2 / sizeof S2[0])));
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         //*/
         /*
         case 6: {
                   string S1[]               = ;
                   string S2[]               = ;
                   int expected__            = ;

                   clock_t start__           = clock();
                   int received__            = PalindromicSubstringsDiv2().count(vector <string>(S1, S1 + (sizeof S1 / sizeof S1[0])), vector <string>(S2, S2 + (sizeof S2 / sizeof S2[0])));
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