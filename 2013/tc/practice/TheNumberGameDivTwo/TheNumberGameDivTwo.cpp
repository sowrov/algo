#include "vector"
#include "stack"
#include "functional"
#include "cstring"
#include "numeric"
#include "cstdlib"
#include "cctype"
#include "cstdio"
#include "iostream"
#include "list"
#include "deque"
#include "string"
#include "cassert"
#include "sstream"
#include "iomanip"
#include "utility"
#include "bitset"
#include "map"
#include "queue"
#include "algorithm"
#include "ctime"
#include "cmath"
#include "set"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)

class TheNumberGameDivTwo {
public:
    int dp[1001];
    string find(int n) {
        memset(dp, -1, sizeof(dp));
        bool r = find(n, 1);
        return r?"John":"Brus";
    }

    bool find(int n, bool jon) {
        if (dp[n]!=-1) return dp[n];
        for (int i=2; i<n; i++) {
            if (n%i==0) {
                if (!find(n-i, !jon)) {
                    dp[n] = 1;
                    return true;
                }
            }
        }
        dp[n] = 0;
        return false;
    }
};

// <editor-fold defaultstate="collapsed" desc="Generated Code">
namespace otocoder {
    int run_test_case(int );
    bool run_full_test();
    // casenum<-1 to run full test set, casenum=-1 (default) to run all sample test cases,
    // casenum>-1 value to run specific sample case
    void run_test(int casenum = -1, bool quiet = false) {
        if (casenum < -1) {
            if (!run_full_test()) {
                cerr << "Illegal inputs in full test cases!" << endl;
            }
            return;
        }
        if (casenum > -1) {
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
            int n = 6;
            string expected_ = "John";

            clock_t start_           = clock();
            string received_ = TheNumberGameDivTwo().find(n);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            int n = 2;
            string expected_ = "Brus";

            clock_t start_           = clock();
            string received_ = TheNumberGameDivTwo().find(n);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            int n = 747;
            string expected_ = "Brus";

            clock_t start_           = clock();
            string received_ = TheNumberGameDivTwo().find(n);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            int n = 128;
            string expected_ = "Brus";

            clock_t start_           = clock();
            string received_ = TheNumberGameDivTwo().find(n);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        default:
            return -1;
        }
    }

    //This method will only accept input files that are formatted in proper way.
    //Command line example: TheNumberGameDivTwo.exe -2 <TheNumberGameDivTwoIO.txt
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        int n;
        string expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            std::cin>>n; std::cin.ignore(10, '\n');
            std::getline(std::cin,expected_);
            clock_t start_           = clock();
            string received_ = TheNumberGameDivTwo().find(n);
            correct += verify_case(caseNo, expected_, received_, clock()-start_);
        }//end of testCase for loop

        if (testCase == 0) {
            cerr << "No test cases run." << endl;
        } else if (correct < testCase) {
            cerr << "Some cases FAILED (passed " << correct << " of " << testCase << ")." << endl;
        } else {
            cerr << "All " << testCase << " tests passed!" << endl;
        }
        return true;
    }

}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        otocoder::run_test();
    } else {
        for (int i=1; i<argc; ++i)
            otocoder::run_test(atoi(argv[i]));
    }
}
// </editor-fold>
