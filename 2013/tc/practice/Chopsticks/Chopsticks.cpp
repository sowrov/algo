#include "stack"
#include "cctype"
#include "iomanip"
#include "sstream"
#include "utility"
#include "numeric"
#include "bitset"
#include "set"
#include "vector"
#include "ctime"
#include "list"
#include "deque"
#include "queue"
#include "cstdlib"
#include "iostream"
#include "cassert"
#include "functional"
#include "cstdio"
#include "cmath"
#include "algorithm"
#include "string"
#include "cstring"
#include "map"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)

class Chopsticks {
public:
    int getmax(vector<int> length) {
        int out;
        vector<int>a(101, 0);

        for (int i=0; i<length.size(); i++) {
            a[length[i]]++;
        }
        out = 0;
        for (int i=1; i<101; i++) {
            out += a[i]/2;
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
            int length[] = {5, 5};
            int expected_ = 1;

            clock_t start_           = clock();
            int received_ = Chopsticks().getmax(vector<int>(length, length + (sizeof length / sizeof length[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            int length[] = {1, 2, 3, 2, 1, 2, 3, 2, 1};
            int expected_ = 4;

            clock_t start_           = clock();
            int received_ = Chopsticks().getmax(vector<int>(length, length + (sizeof length / sizeof length[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            int length[] = {1};
            int expected_ = 0;

            clock_t start_           = clock();
            int received_ = Chopsticks().getmax(vector<int>(length, length + (sizeof length / sizeof length[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            int length[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
            int expected_ = 0;

            clock_t start_           = clock();
            int received_ = Chopsticks().getmax(vector<int>(length, length + (sizeof length / sizeof length[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 4: {
            int length[] = {35, 35, 35, 50, 16, 30, 10, 10, 35, 50, 16, 16, 16, 30, 50, 30, 16, 35, 50, 30, 10, 50, 50, 16, 16, 
10, 35, 50, 50, 50, 16, 35, 35, 30, 35, 10, 50, 10, 50, 50, 16, 30, 35, 10, 10, 30, 10, 10, 16, 35};
            int expected_ = 24;

            clock_t start_           = clock();
            int received_ = Chopsticks().getmax(vector<int>(length, length + (sizeof length / sizeof length[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        default:
            return -1;
        }
    }

    //This method will only accept input files that are formatted in proper way.
    //Command line example: Chopsticks.exe -2 <Chopsticks.io
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        vector<int> length;
        int length_sin;
        int expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            length.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::cin>>length_sin; std::cin.ignore(10, '\n');
                length.push_back(length_sin);
            }
            std::cin>>expected_; std::cin.ignore(10, '\n');
            clock_t start_           = clock();
            int received_ = Chopsticks().getmax(length);
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
