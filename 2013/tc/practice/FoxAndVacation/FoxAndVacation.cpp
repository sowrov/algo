#include "stack"
#include "string"
#include "cstdio"
#include "algorithm"
#include "queue"
#include "set"
#include "cstring"
#include "cctype"
#include "cstdlib"
#include "numeric"
#include "iostream"
#include "utility"
#include "map"
#include "deque"
#include "list"
#include "cmath"
#include "vector"
#include "cassert"
#include "iomanip"
#include "sstream"
#include "functional"
#include "ctime"
#include "bitset"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)

class FoxAndVacation {
public:
    int maxCities(int total, vector<int> d) {
        int out=0;
        sort (d.begin(), d.end());
        
        for (int i=0; i<d.size(); i++) {
            total -= d[i];
            if (total<0) break;
            out++;
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
            int total = 5;
            int d[] = {2, 2, 2};
            int expected_ = 2;

            clock_t start_           = clock();
            int received_ = FoxAndVacation().maxCities(total, vector<int>(d, d + (sizeof d / sizeof d[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            int total = 5;
            int d[] = {5, 6, 1};
            int expected_ = 1;

            clock_t start_           = clock();
            int received_ = FoxAndVacation().maxCities(total, vector<int>(d, d + (sizeof d / sizeof d[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            int total = 5;
            int d[] = {6, 6, 6};
            int expected_ = 0;

            clock_t start_           = clock();
            int received_ = FoxAndVacation().maxCities(total, vector<int>(d, d + (sizeof d / sizeof d[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            int total = 6;
            int d[] = {1, 1, 1, 1, 1};
            int expected_ = 5;

            clock_t start_           = clock();
            int received_ = FoxAndVacation().maxCities(total, vector<int>(d, d + (sizeof d / sizeof d[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 4: {
            int total = 10;
            int d[] = {7, 1, 5, 6, 1, 3, 4};
            int expected_ = 4;

            clock_t start_           = clock();
            int received_ = FoxAndVacation().maxCities(total, vector<int>(d, d + (sizeof d / sizeof d[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 5: {
            int total = 50;
            int d[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
            int expected_ = 9;

            clock_t start_           = clock();
            int received_ = FoxAndVacation().maxCities(total, vector<int>(d, d + (sizeof d / sizeof d[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 6: {
            int total = 21;
            int d[] = {14, 2, 16, 9, 9, 5, 5, 23, 25, 20, 8, 25, 6, 12, 3, 2, 4, 5, 10, 14, 19, 12, 25, 15, 14};
            int expected_ = 6;

            clock_t start_           = clock();
            int received_ = FoxAndVacation().maxCities(total, vector<int>(d, d + (sizeof d / sizeof d[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        default:
            return -1;
        }
    }

    //This method will only accept input files that are formatted in proper way.
    //Command line example: FoxAndVacation.exe -2 <FoxAndVacationIO.txt
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        int total;
        vector<int> d;
        int d_sin;
        int expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            std::cin>>total; std::cin.ignore(10, '\n');
            d.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::cin>>d_sin; std::cin.ignore(10, '\n');
                d.push_back(d_sin);
            }
            std::cin>>expected_; std::cin.ignore(10, '\n');
            clock_t start_           = clock();
            int received_ = FoxAndVacation().maxCities(total, d);
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
