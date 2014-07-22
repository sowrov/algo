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

class TaroString {
public:
    string getAnswer( string S ) {
        char ch='C';
        int arr[30];
        Zclr(arr);
        for (int i=0; i<S.size(); i++) {
            arr[S[i]-'A']++;
        }
        if (arr[0]==1 && arr['C'-'A']==1 && arr['T'-'A']==1) {
            for (int i=0; i<S.size(); i++) {
                if (S[i]=='C' && ch=='C') {
                    ch='A';
                } if (S[i]=='A' && ch=='A') {
                    ch='T';
                } if (S[i]=='T' && ch=='T') {
                    return "Possible";
                }
            }
        }
        
        return "Impossible";
        
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
    
    int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) { 
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
                   cerr << "    Expected: \"" << expected << "\"" << endl; 
                   cerr << "    Received: \"" << received << "\"" << endl; 
         }
         
         return verdict == "PASSED";
    }

    int run_test_case(int casenum) {
         switch (casenum) {
         case 0: {
                   string S                  = "XCYAZTX";
                   string expected__         = "Possible";

                   clock_t start__           = clock();
                   string received__         = TaroString().getAnswer(S);
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         case 1: {
                   string S                  = "CTA";
                   string expected__         = "Impossible";

                   clock_t start__           = clock();
                   string received__         = TaroString().getAnswer(S);
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         case 2: {
                   string S                  = "ACBBAT";
                   string expected__         = "Impossible";

                   clock_t start__           = clock();
                   string received__         = TaroString().getAnswer(S);
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         case 3: {
                   string S                  = "SGHDJHFIOPUFUHCHIOJBHAUINUIT";
                   string expected__         = "Possible";

                   clock_t start__           = clock();
                   string received__         = TaroString().getAnswer(S);
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         case 4: {
                   string S                  = "CCCATT";
                   string expected__         = "Impossible";

                   clock_t start__           = clock();
                   string received__         = TaroString().getAnswer(S);
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }

         // custom cases

         /*
         case 5: {
                   string S                  = ;
                   string expected__         = ;

                   clock_t start__           = clock();
                   string received__         = TaroString().getAnswer(S);
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         //*/
         /*
         case 6: {
                   string S                  = ;
                   string expected__         = ;

                   clock_t start__           = clock();
                   string received__         = TaroString().getAnswer(S);
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         //*/
         /*
         case 7: {
                   string S                  = ;
                   string expected__         = ;

                   clock_t start__           = clock();
                   string received__         = TaroString().getAnswer(S);
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
