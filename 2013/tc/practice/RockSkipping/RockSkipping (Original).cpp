#include "cstring"
#include "cassert"
#include "bitset"
#include "string"
#include "deque"
#include "vector"
#include "queue"
#include "ctime"
#include "iostream"
#include "cmath"
#include "iomanip"
#include "algorithm"
#include "map"
#include "cctype"
#include "set"
#include "cstdlib"
#include "list"
#include "utility"
#include "numeric"
#include "sstream"
#include "cstdio"
#include "stack"
#include "functional"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)

class RockSkipping {
public:
    double probability(string pads, int maxDist) {
        double out;

        return out;
    }
};

// <editor-fold defaultstate="collapsed" desc="Generated Code">
namespace otocoder {
#ifndef isinf
#define isinf(x) (!_finite(x))
#define isnan(x) _isnan(x)
#endif
    static const double epsilon = 1e-9; static bool compareDouble(double expected, double result) { return (fabs(expected - result) <= epsilon * fmax(1.0, fmax(fabs(expected), fabs(result)))); }
    double moj_relative_error(double expected, double result) { if (isnan(expected) || isinf(expected) || isnan(result) || isinf(result) || expected == 0) return 0; return fabs(result-expected) / fabs(expected); }

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

    int verify_case(int casenum, const double &expected, const double &received, clock_t elapsed) { 
        cerr << "Example " << casenum << "... "; 

        string verdict;
        vector<string> info;
        char buf[100];

        if (elapsed > CLOCKS_PER_SEC / 200) {
            sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
            info.push_back(buf);
        }

        if (compareDouble(expected, received)) {
            verdict = "PASSED";
            double rerr = moj_relative_error(expected, received); 
            if (rerr > 0) {
                sprintf(buf, "relative error %.3e", rerr);
                info.push_back(buf);
            }
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
            string pads = ".";
            int maxDist = 100;
            double expected_ = 100.0;

            clock_t start_           = clock();
            double received_ = RockSkipping().probability(pads, maxDist);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            string pads = "...X";
            int maxDist = 2;
            double expected_ = 50.0;

            clock_t start_           = clock();
            double received_ = RockSkipping().probability(pads, maxDist);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            string pads = "........................X";
            int maxDist = 50;
            double expected_ = 11.60725450562586;

            clock_t start_           = clock();
            double received_ = RockSkipping().probability(pads, maxDist);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            string pads = "...X......XXXX...XX.X..X...XX...";
            int maxDist = 48;
            double expected_ = 5.408479511004734E-8;

            clock_t start_           = clock();
            double received_ = RockSkipping().probability(pads, maxDist);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        default:
            return -1;
        }
    }

    //This method will only accept input files that are formatted in proper way.
    //Command line example: RockSkipping.exe -2 <RockSkippingIO.txt
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        string pads;
        int maxDist;
        double expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            std::getline(std::cin,pads);
            std::cin>>maxDist; std::cin.ignore(10, '\n');
            std::cin>>expected_; std::cin.ignore(10, '\n');
            clock_t start_           = clock();
            double received_ = RockSkipping().probability(pads, maxDist);
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
