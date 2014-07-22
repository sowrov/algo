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

class TaroCards {
public:
    long long getNumber( vector <int> first, vector <int> second, int K ) {
        bool arr[51];
        int un=0;
        Zclr(arr);
        for(int i=0; i<first.size(); i++) {
            if(!arr[first[i]]) {
                un++;
                arr[first[i]]=1;
            }
        }

        for(int i=0; i<second.size(); i++) {
            if(!arr[second[i]]) {
                un++;
                arr[second[i]]=1;
            }
        }
        long long res=1;
        if (K>=un) {
            res <<= un;
        } else {
            res <<= K;
            res--;
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
    
    int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) { 
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
                   int first[]               = {1, 2};
                   int second[]              = {2, 3};
                   int K                     = 2;
                   long long expected__      = 3;

                   clock_t start__           = clock();
                   long long received__      = TaroCards().getNumber(vector <int>(first, first + (sizeof first / sizeof first[0])), vector <int>(second, second + (sizeof second / sizeof second[0])), K);
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         case 1: {
                   int first[]               = {3, 1, 2};
                   int second[]              = {1, 1, 1};
                   int K                     = 3;
                   long long expected__      = 8;

                   clock_t start__           = clock();
                   long long received__      = TaroCards().getNumber(vector <int>(first, first + (sizeof first / sizeof first[0])), vector <int>(second, second + (sizeof second / sizeof second[0])), K);
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         case 2: {
                   int first[]               = {4, 2, 1, 3};
                   int second[]              = {1, 2, 3, 4};
                   int K                     = 5;
                   long long expected__      = 16;

                   clock_t start__           = clock();
                   long long received__      = TaroCards().getNumber(vector <int>(first, first + (sizeof first / sizeof first[0])), vector <int>(second, second + (sizeof second / sizeof second[0])), K);
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         case 3: {
                   int first[]               = {1, 2, 3, 4, 5, 6, 7};
                   int second[]              = {2, 1, 10, 9, 3, 2, 2};
                   int K                     = 3;
                   long long expected__      = 17;

                   clock_t start__           = clock();
                   long long received__      = TaroCards().getNumber(vector <int>(first, first + (sizeof first / sizeof first[0])), vector <int>(second, second + (sizeof second / sizeof second[0])), K);
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         case 4: {
                   int first[]               = {1};
                   int second[]              = {2};
                   int K                     = 1;
                   long long expected__      = 1;

                   clock_t start__           = clock();
                   long long received__      = TaroCards().getNumber(vector <int>(first, first + (sizeof first / sizeof first[0])), vector <int>(second, second + (sizeof second / sizeof second[0])), K);
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         case 5: {
                   int first[]               = {6, 20, 1, 11, 19, 14, 2, 8, 15, 21, 9, 10, 4, 16, 12, 17, 13, 22, 7, 18, 3, 5};
                   int second[]              = {4, 5, 10, 7, 6, 2, 1, 10, 10, 7, 9, 4, 5, 9, 5, 10, 10, 3, 6, 6, 4, 4};
                   int K                     = 14;
                   long long expected__      = 2239000;

                   clock_t start__           = clock();
                   long long received__      = TaroCards().getNumber(vector <int>(first, first + (sizeof first / sizeof first[0])), vector <int>(second, second + (sizeof second / sizeof second[0])), K);
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }

         // custom cases

         /*
         case 6: {
                   int first[]               = ;
                   int second[]              = ;
                   int K                     = ;
                   long long expected__      = ;

                   clock_t start__           = clock();
                   long long received__      = TaroCards().getNumber(vector <int>(first, first + (sizeof first / sizeof first[0])), vector <int>(second, second + (sizeof second / sizeof second[0])), K);
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         //*/
         /*
         case 7: {
                   int first[]               = ;
                   int second[]              = ;
                   int K                     = ;
                   long long expected__      = ;

                   clock_t start__           = clock();
                   long long received__      = TaroCards().getNumber(vector <int>(first, first + (sizeof first / sizeof first[0])), vector <int>(second, second + (sizeof second / sizeof second[0])), K);
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         //*/
         /*
         case 8: {
                   int first[]               = ;
                   int second[]              = ;
                   int K                     = ;
                   long long expected__      = ;

                   clock_t start__           = clock();
                   long long received__      = TaroCards().getNumber(vector <int>(first, first + (sizeof first / sizeof first[0])), vector <int>(second, second + (sizeof second / sizeof second[0])), K);
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
