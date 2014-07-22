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

class SwappingDigits {
public:
    string minNumber( string num ) {
        int ind=-1;
        char minv=100;
        for (int i=0; i<num.size(); i++) {
            if (num[i]<=minv && num[i]!='0') {
                minv=num[i];
                ind = i;
            }
        }
        if (ind==0) {
            int k=1;
            while(true) {
                ind=-1;
                minv=100;
                for (int i=k; i<num.size(); i++) {
                    if (num[i]<=minv) {
                        minv=num[i];
                        ind = i;
                    }
                }
                if (ind==-1) {
                    break;
                }
                if (ind==k) {
                    k++;
                }else if(ind!=-1){
                    num[ind]=num[k];
                    num[k]=minv;
                    break;
                }
            }
        }
        else {
            num[ind]=num[0];
            num[0]=minv;
        }
        return num;
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
            string num                = "596";
            string expected__         = "569";

            clock_t start__           = clock();
            string received__         = SwappingDigits().minNumber(num);
            return verify_case(casenum, expected__, received__, clock()-start__);
        }
        case 1: {
            string num                = "93561";
            string expected__         = "13569";

            clock_t start__           = clock();
            string received__         = SwappingDigits().minNumber(num);
            return verify_case(casenum, expected__, received__, clock()-start__);
        }
        case 2: {
            string num                = "5491727514";
            string expected__         = "1491727554";

            clock_t start__           = clock();
            string received__         = SwappingDigits().minNumber(num);
            return verify_case(casenum, expected__, received__, clock()-start__);
        }
        case 3: {
            string num                = "10234";
            string expected__         = "10234";

            clock_t start__           = clock();
            string received__         = SwappingDigits().minNumber(num);
            return verify_case(casenum, expected__, received__, clock()-start__);
        }
        case 4: {
            string num                = "93218910471211292416";
            string expected__         = "13218910471211292496";

            clock_t start__           = clock();
            string received__         = SwappingDigits().minNumber(num);
            return verify_case(casenum, expected__, received__, clock()-start__);
        }

        // custom cases

        /*
        case 5: {
            string num                = ;
            string expected__         = ;

            clock_t start__           = clock();
            string received__         = SwappingDigits().minNumber(num);
            return verify_case(casenum, expected__, received__, clock()-start__);
        }
        //*/
        /*
        case 6: {
            string num                = ;
            string expected__         = ;

            clock_t start__           = clock();
            string received__         = SwappingDigits().minNumber(num);
            return verify_case(casenum, expected__, received__, clock()-start__);
        }
        //*/
        /*
        case 7: {
            string num                = ;
            string expected__         = ;

            clock_t start__           = clock();
            string received__         = SwappingDigits().minNumber(num);
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
