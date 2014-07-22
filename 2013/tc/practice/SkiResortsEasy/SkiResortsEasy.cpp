#include "cctype"
#include "map"
#include "iostream"
#include "cassert"
#include "cstdlib"
#include "stack"
#include "ctime"
#include "deque"
#include "sstream"
#include "list"
#include "string"
#include "numeric"
#include "cmath"
#include "functional"
#include "iomanip"
#include "cstring"
#include "utility"
#include "cstdio"
#include "bitset"
#include "set"
#include "vector"
#include "algorithm"
#include "queue"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)

class SkiResortsEasy {
public:
    int minCost(vector<int> altitude) {
        int out=0;
        int lv = 100000;
        for (int i=0; i<altitude.size(); i++) {
            if (altitude[i]>lv) {
                out += (altitude[i]-lv);
            } else {
                lv = altitude[i];
            }
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
            int altitude[] = {30, 20, 20, 10};
            int expected_ = 0;

            clock_t start_           = clock();
            int received_ = SkiResortsEasy().minCost(vector<int>(altitude, altitude + (sizeof altitude / sizeof altitude[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            int altitude[] = {5, 7, 3};
            int expected_ = 2;

            clock_t start_           = clock();
            int received_ = SkiResortsEasy().minCost(vector<int>(altitude, altitude + (sizeof altitude / sizeof altitude[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            int altitude[] = {6, 8, 5, 4, 7, 4, 2, 3, 1};
            int expected_ = 6;

            clock_t start_           = clock();
            int received_ = SkiResortsEasy().minCost(vector<int>(altitude, altitude + (sizeof altitude / sizeof altitude[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            int altitude[] = {749, 560, 921, 166, 757, 818, 228, 584, 366, 88};
            int expected_ = 2284;

            clock_t start_           = clock();
            int received_ = SkiResortsEasy().minCost(vector<int>(altitude, altitude + (sizeof altitude / sizeof altitude[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 4: {
            int altitude[] = {712, 745, 230, 200, 648, 440, 115, 913, 627, 621, 186, 222, 741, 954, 581, 193, 266, 320, 798, 745};
            int expected_ = 6393;

            clock_t start_           = clock();
            int received_ = SkiResortsEasy().minCost(vector<int>(altitude, altitude + (sizeof altitude / sizeof altitude[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        default:
            return -1;
        }
    }

    //This method will only accept input files that are formatted in proper way.
    //Command line example: SkiResortsEasy.exe -2 <SkiResortsEasy.io
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        vector<int> altitude;
        int altitude_sin;
        int expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            altitude.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::cin>>altitude_sin; std::cin.ignore(10, '\n');
                altitude.push_back(altitude_sin);
            }
            std::cin>>expected_; std::cin.ignore(10, '\n');
            clock_t start_           = clock();
            int received_ = SkiResortsEasy().minCost(altitude);
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
