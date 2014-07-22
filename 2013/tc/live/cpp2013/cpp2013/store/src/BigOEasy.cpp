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

int D[51][51];

class BigOEasy {
public:
    string isBounded( vector <string> graph ) {
        return hasCycle1(graph)?"Unbounded":"Bounded";
    }

    bool hasCycle1(vector<string>& grf) {
        Zclr(D);
        for (int i=0; i<grf.size(); i++) {
            for (int j=0; j<grf[i].size(); j++) {
                D[i][j]=grf[i][j]=='Y'?1:10000;
            }
        }
        int N = grf.size();
        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (D[i][k] + D[k][j] < D[i][j]) {
                        D[i][j] = D[i][k] + D[k][j];
                    }
                }
            }
        }

        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (D[i][j]==0) {
                    return false;
                }
            }
        }
        return true;
    }
    bool hasCycle(vector<string>& grf) {
        for (int i=0; i<grf.size(); i++) {
            if (walk(grf, i)) return true;
        }
        return false;
    }

    bool walk(vector<string>&grf, int s) {
        //Zclr(flg);
        //Zclr(enq);
        queue<int> q;
        q.push(s);
        //enq[s]=1;

        while(!q.empty()) {
            int id = q.front();
            q.pop();
            //if (flg[id]) return true;
            //flg[id]=1;

            for (int i=0; i<grf[id].size(); i++) {
                if (grf[id][i]=='Y') {
                    if (i==s) {
                        return true;
                    }
                    q.push(i);
                }
            }
        }
        return false;
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
                   string graph[]            = {"NYY",
 "YNY",
 "YYN"};
                   string expected__         = "Unbounded";

                   clock_t start__           = clock();
                   string received__         = BigOEasy().isBounded(vector <string>(graph, graph + (sizeof graph / sizeof graph[0])));
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         case 1: {
                   string graph[]            = {"NYYN",
 "NNNY",
 "NNNY",
 "NNNN"};
                   string expected__         = "Bounded";

                   clock_t start__           = clock();
                   string received__         = BigOEasy().isBounded(vector <string>(graph, graph + (sizeof graph / sizeof graph[0])));
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         case 2: {
                   string graph[]            = {"NYN",
 "NNY",
 "YNN"};
                   string expected__         = "Bounded";

                   clock_t start__           = clock();
                   string received__         = BigOEasy().isBounded(vector <string>(graph, graph + (sizeof graph / sizeof graph[0])));
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         case 3: {
                   string graph[]            = {"NYYN",
 "YNNN",
 "NNNY",
 "NNYN"};
                   string expected__         = "Bounded";

                   clock_t start__           = clock();
                   string received__         = BigOEasy().isBounded(vector <string>(graph, graph + (sizeof graph / sizeof graph[0])));
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         case 4: {
                   string graph[]            = {"NYY",
 "YNN",
 "YNN"};
                   string expected__         = "Unbounded";

                   clock_t start__           = clock();
                   string received__         = BigOEasy().isBounded(vector <string>(graph, graph + (sizeof graph / sizeof graph[0])));
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         case 5: {
                   string graph[]            = {"NYNYN",
 "NNYNY",
 "YNNNN",
 "NNNNN",
 "YNNNN"};
                   string expected__         = "Unbounded";

                   clock_t start__           = clock();
                   string received__         = BigOEasy().isBounded(vector <string>(graph, graph + (sizeof graph / sizeof graph[0])));
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         case 6: {
                   string graph[]            = {"NYYN",
 "NNYN",
 "NNNY",
 "YNNN"};
                   string expected__         = "Unbounded";

                   clock_t start__           = clock();
                   string received__         = BigOEasy().isBounded(vector <string>(graph, graph + (sizeof graph / sizeof graph[0])));
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         case 7: {
                   string graph[]            = {"NYYNNNNYNNYNYNNNNYYNNYNYNNNNNNNNNNYNNNNNNNYYNYNNNN",
 "NNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "YYYNYYNYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYYYNYYYYYNYYN",
 "YYYNNNNYNNYNYNNNNYYNNNNYNNNNNNNNNNYNNNNNNNYYNYNNNN",
 "YYYNYNNYNNYYYNNNYYYNNYNYNNYNYYYNYYYYYYNYNYYYNYNYNN",
 "YYYYYYNYYYYYYYYYYYYYYYYYYNYNYYYYYYYYYYYYNYYYYYNYYN",
 "NYYNNNNNNNYNYNNNNYNNNNNYNNNNNNNNNNNNNNNNNNYNNYNNNN",
 "YYYNYNNYNNYYYNNNNYYNNYNYNNYNYYYYYYYYYYNYNYYYNYNYNN",
 "YYYNYNNYNNYYYNNNNYYNYYNYNNYNYYYNYYYYYYNYNYYYNYNYNN",
 "NNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NYYNNNNYNNYNYNNNNYYNNNNYNNNNNNNNNNYYNNNNNNYYNYNNNN",
 "NNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "YYYNYNNYYNYYYNNNNYYNNYNYNNYNYYYNYYYYYYNYNYYYNYNYNN",
 "YYYNYNNYNNYYYNNNNYYYNYNYNNYNYYYNYYYYYYNYNYYYNYNYNN",
 "YYYNYNNYNNYYYNNNNYYNNYYYNNYNYYYNYYYYYYNYNYYYNYNYNN",
 "YYYNYNNYNYYYYNNNNYYNNYNYNNYNYYYNYYYYYYNYNYYYNYNYNN",
 "NNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "NYYNNNNNNNYNYNNNNYNNNNNYNNNNNNNNNNYNNNNNNNNNNYNNNN",
 "YYYNYNNYNNYYYNNNNYYNNYNYNNYNYYYNYYYYYYYYNYYYNYNYNN",
 "YYYNYNNYNNYYYNNNNYYNNYNYYNYNYYYNYYYYYYNYNYYYNYNYNN",
 "NYYNNNNYNNYNYNNNNYYNNNNYNNNNNNYNNNYNNNNNNNYYNYNNNN",
 "YYYNYYNYNNYYYNNNNYYNNYNYNNYNYYYNYYYYYYNYNYYYNYNYNN",
 "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNN",
 "YYYNYNNYNNYYYYNNNYYNNYNYNNYNYYYNYYYYYYNYNYYYNYNYNN",
 "YYYNYYNYYYYYYYYYYYYYYYYYYNYNYYYYYYYYYYYYNYYYYYNYYY",
 "NYYNNNNYNNYNYNNNNYYNNNNYNNNNYNNNNNYNNNNNNNYYNYNNNN",
 "YYYNYYNYYYYYYYYYYYYYYYYYYNYNYYYYYYYYYYYYYYYYYYNYYN",
 "NYYNNNNYNNYNYNNNNYYNNNNYNNNNNNNNNNYNNNNNNNYYNYNYNN",
 "NYYNNNNYNNYYYNNNNYYNNNNYNNNNNNNNNNYNNNNNNNYYNYNNNN",
 "NYYNNNNYNNYNYNNNNYYNNNNYNNYNNNNNNNYNNNNNNNYYNYNNNN",
 "YYYNYNNYNNYYYNYNNYYNNYNYNNYNYYYNYYYYYYNYNYYYNYNYNN",
 "YYYNYNNYNNYYYNNNNYYNNYNYNNYNYYYNNYYYNYNYNYYYNYNYNN",
 "NYYNNNNYNNYNYNNNNYYNNNNYNNNNNNNNNNYNNNNYNNYYNYNNNN",
 "NYYNNNNYNNYNYNNNNYNNNNNYNNNNNNNNNNNNNNNNNNNNNYNNNN",
 "NYYNNNNYNNYNYNNNNYYNNNNYNNNNNNNNNYYNNNNNNNYYNYNNNN",
 "YYYNYNNYNNYYYNNNNYYNNYNYNNYNYYYNYYYYNNNYNYYYNYNYNN",
 "YYYNYNNYNNYYYNNNNYYNNYNYNNYNYYYNNYYYYNNYNYYYNYNYNN",
 "YYYNYNNYNNYYYNNYNYYNNYNYNNYNYYYNYYYYYYNYNYYYNYNYNN",
 "NYYNNNNYNNYNYNNNNYYNNNNYNNNNNNNNNNYNNNNNNYYYNYNNNN",
 "YYYNYYNYYYYYYYYYYYYYYYYYYNYNYYYYYYYYYYYYNYYYYYYYYN",
 "NYYNYNNYNNYNYNNNNYYNNNNYNNNNNNNNNNYNNNNNNNYYNYNNNN",
 "NYYNNNNNNNYNYNNNNYNNNNNYNNNNNNNNNNNNNNNNNNNYNYNNNN",
 "NYYNNNNNNNYNYNNNNYYNNNNYNNNNNNNNNNNNNNNNNNNNNYNNNN",
 "YYYNYYNYYYYYYYYYYYYYYYYYYNYNYYYYYYYYYYYYNYYYNYNYNN",
 "NYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
 "YYYNYYNYYYYYYYYYYYYYYYYYYYYNYYYYYYYYYYYYNYYYYYNYYN",
 "NYYNNNNYNNYNYNNNNYYNNNNYNNNNNYNNNNYNNNNNNNYYNYNNNN",
 "YYYNYYNYYYYYYYYYYYYYYYYYYNYNYYYYYYYYYYYYNYYYYYNYNN",
 "YYYNYYYYYYYYYYYYYYYYYYYYYNYNYYYYYYYYYYYYNYYYYYNYYN"};
                   string expected__         = "Bounded";

                   clock_t start__           = clock();
                   string received__         = BigOEasy().isBounded(vector <string>(graph, graph + (sizeof graph / sizeof graph[0])));
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }

         // custom cases

         /*
         case 8: {
                   string graph[]            = ;
                   string expected__         = ;

                   clock_t start__           = clock();
                   string received__         = BigOEasy().isBounded(vector <string>(graph, graph + (sizeof graph / sizeof graph[0])));
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         //*/
         /*
         case 9: {
                   string graph[]            = ;
                   string expected__         = ;

                   clock_t start__           = clock();
                   string received__         = BigOEasy().isBounded(vector <string>(graph, graph + (sizeof graph / sizeof graph[0])));
                   return verify_case(casenum, expected__, received__, clock()-start__);
         }
         //*/
         /*
         case 10: {
                   string graph[]            = ;
                   string expected__         = ;

                   clock_t start__           = clock();
                   string received__         = BigOEasy().isBounded(vector <string>(graph, graph + (sizeof graph / sizeof graph[0])));
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
