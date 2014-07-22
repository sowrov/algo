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
#define M31 2147483647
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)

class TeamsSelection {
public:
    string simulate( vector <int> preference1, vector <int> preference2 ) {
        int p[51];
        Zclr(p);
        string out="";
        int k=0, i=0, j=0;
        while(1) {
            while(i<preference1.size() && p[preference1[i]-1]) {
                i++;
            }
            if (i<preference1.size()) {
                p[preference1[i]-1]=1;
            }


            while(j<preference2.size() && p[preference2[j]-1]) {
                j++;
            }
            if (j<preference2.size()) {
                p[preference2[j]-1]=2;
            }
            
            if (i+1>=preference1.size() || j+1>=preference2.size()) break;
        }

        for (i=0; i<preference2.size(); i++) {
            if (p[i]==1) {
                out+="1";
            } else {
                out +="2";
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
            int preference1[]         = {1, 2, 3, 4};
            int preference2[]         = {1, 2, 3, 4};
            string expected__         = "1212";

            clock_t start__           = clock();
            string received__         = TeamsSelection().simulate(vector <int>(preference1, preference1 + (sizeof preference1 / sizeof preference1[0])), vector <int>(preference2, preference2 + (sizeof preference2 / sizeof preference2[0])));
            return verify_case(casenum, expected__, received__, clock()-start__);
        }
        case 1: {
            int preference1[]         = {3, 2, 1};
            int preference2[]         = {1, 3, 2};
            string expected__         = "211";

            clock_t start__           = clock();
            string received__         = TeamsSelection().simulate(vector <int>(preference1, preference1 + (sizeof preference1 / sizeof preference1[0])), vector <int>(preference2, preference2 + (sizeof preference2 / sizeof preference2[0])));
            return verify_case(casenum, expected__, received__, clock()-start__);
        }
        case 2: {
            int preference1[]         = {6, 1, 5, 2, 3, 4};
            int preference2[]         = {1, 6, 3, 4, 5, 2};
            string expected__         = "212211";

            clock_t start__           = clock();
            string received__         = TeamsSelection().simulate(vector <int>(preference1, preference1 + (sizeof preference1 / sizeof preference1[0])), vector <int>(preference2, preference2 + (sizeof preference2 / sizeof preference2[0])));
            return verify_case(casenum, expected__, received__, clock()-start__);
        }
        case 3: {
            int preference1[]         = {8, 7, 1, 2, 4, 5, 6, 3, 9};
            int preference2[]         = {7, 2, 4, 8, 1, 5, 9, 6, 3};
            string expected__         = "121121212";

            clock_t start__           = clock();
            string received__         = TeamsSelection().simulate(vector <int>(preference1, preference1 + (sizeof preference1 / sizeof preference1[0])), vector <int>(preference2, preference2 + (sizeof preference2 / sizeof preference2[0])));
            return verify_case(casenum, expected__, received__, clock()-start__);
        }

        // custom cases

        /*
        case 4: {
            int preference1[]         = ;
            int preference2[]         = ;
            string expected__         = ;

            clock_t start__           = clock();
            string received__         = TeamsSelection().simulate(vector <int>(preference1, preference1 + (sizeof preference1 / sizeof preference1[0])), vector <int>(preference2, preference2 + (sizeof preference2 / sizeof preference2[0])));
            return verify_case(casenum, expected__, received__, clock()-start__);
        }
        //*/
        /*
        case 5: {
            int preference1[]         = ;
            int preference2[]         = ;
            string expected__         = ;

            clock_t start__           = clock();
            string received__         = TeamsSelection().simulate(vector <int>(preference1, preference1 + (sizeof preference1 / sizeof preference1[0])), vector <int>(preference2, preference2 + (sizeof preference2 / sizeof preference2[0])));
            return verify_case(casenum, expected__, received__, clock()-start__);
        }
        //*/
        /*
        case 6: {
            int preference1[]         = ;
            int preference2[]         = ;
            string expected__         = ;

            clock_t start__           = clock();
            string received__         = TeamsSelection().simulate(vector <int>(preference1, preference1 + (sizeof preference1 / sizeof preference1[0])), vector <int>(preference2, preference2 + (sizeof preference2 / sizeof preference2[0])));
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
