#include "vector"
#include "deque"
#include "list"
#include "cassert"
#include "algorithm"
#include "string"
#include "iomanip"
#include "utility"
#include "cstring"
#include "set"
#include "bitset"
#include "iostream"
#include "cmath"
#include "queue"
#include "cctype"
#include "functional"
#include "map"
#include "ctime"
#include "numeric"
#include "sstream"
#include "cstdio"
#include "cstdlib"
#include "stack"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)

class TheSimilarNumbers {
public:
    int find(int lower, int upper) {
        int out=0;
        int cn = lower;
        while(cn <= upper) {
            out++;
            cn *=10;
            cn++;
        }

        return out;
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
            int lower = 1;
            int upper = 10;
            int expected_ = 1;

            clock_t start_           = clock();
            int received_ = TheSimilarNumbers().find(lower, upper);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            int lower = 5;
            int upper = 511;
            int expected_ = 3;

            clock_t start_           = clock();
            int received_ = TheSimilarNumbers().find(lower, upper);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            int lower = 5;
            int upper = 4747;
            int expected_ = 3;

            clock_t start_           = clock();
            int received_ = TheSimilarNumbers().find(lower, upper);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            int lower = 1;
            int upper = 1000000;
            int expected_ = 6;

            clock_t start_           = clock();
            int received_ = TheSimilarNumbers().find(lower, upper);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 4: {
            int lower = 10;
            int upper = 10110;
            int expected_ = 3;

            clock_t start_           = clock();
            int received_ = TheSimilarNumbers().find(lower, upper);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        default:
            return -1;
        }
    }

    //This method will only accept input files that are formatted in proper way.
    //Command line example: TheSimilarNumbers.exe -2 <TheSimilarNumbersIO.txt
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        int lower;
        int upper;
        int expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            std::cin>>lower; std::cin.ignore(10, '\n');
            std::cin>>upper; std::cin.ignore(10, '\n');
            std::cin>>expected_; std::cin.ignore(10, '\n');
            clock_t start_           = clock();
            int received_ = TheSimilarNumbers().find(lower, upper);
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
