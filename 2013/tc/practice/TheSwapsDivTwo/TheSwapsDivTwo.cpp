#include "cstring"
#include "map"
#include "string"
#include "stack"
#include "bitset"
#include "cassert"
#include "cctype"
#include "sstream"
#include "numeric"
#include "cstdlib"
#include "functional"
#include "ctime"
#include "iostream"
#include "deque"
#include "list"
#include "utility"
#include "queue"
#include "vector"
#include "algorithm"
#include "set"
#include "iomanip"
#include "cstdio"
#include "cmath"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)

class TheSwapsDivTwo {
public:
    int find(vector<int> sequence) {
        int out=0;
        bool flg=false;

        for (int i=0; i<sequence.size(); i++) {
            for (int j=i+1; j<sequence.size(); j++) {
                if (sequence[i] != sequence[j]) {
                    out++;
                } else if (sequence[i]==sequence[j]) {
                    flg=true;
                    //flg[sequence[j]] = false;
                }
            }
        }
        return flg?out+1:out;
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
            int sequence[] = {4, 7, 4};
            int expected_ = 3;

            clock_t start_           = clock();
            int received_ = TheSwapsDivTwo().find(vector<int>(sequence, sequence + (sizeof sequence / sizeof sequence[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            int sequence[] = {1, 47};
            int expected_ = 1;

            clock_t start_           = clock();
            int received_ = TheSwapsDivTwo().find(vector<int>(sequence, sequence + (sizeof sequence / sizeof sequence[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            int sequence[] = {9, 9, 9, 9};
            int expected_ = 1;

            clock_t start_           = clock();
            int received_ = TheSwapsDivTwo().find(vector<int>(sequence, sequence + (sizeof sequence / sizeof sequence[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            int sequence[] = {22, 16, 36, 35, 14, 9, 33, 6, 28, 12, 18, 14, 47, 46, 29, 22, 14, 17, 4, 15, 28, 6, 39, 24, 47, 37};
            int expected_ = 319;

            clock_t start_           = clock();
            int received_ = TheSwapsDivTwo().find(vector<int>(sequence, sequence + (sizeof sequence / sizeof sequence[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        default:
            return -1;
        }
    }

    //This method will only accept input files that are formatted in proper way.
    //Command line example: TheSwapsDivTwo.exe -2 <TheSwapsDivTwo.io
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        vector<int> sequence;
        int sequence_sin;
        int expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            sequence.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::cin>>sequence_sin; std::cin.ignore(10, '\n');
                sequence.push_back(sequence_sin);
            }
            std::cin>>expected_; std::cin.ignore(10, '\n');
            clock_t start_           = clock();
            int received_ = TheSwapsDivTwo().find(sequence);
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
