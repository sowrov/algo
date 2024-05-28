#include "queue"
#include "iomanip"
#include "utility"
#include "string"
#include "set"
#include "cmath"
#include "iostream"
#include "cstdio"
#include "cstring"
#include "functional"
#include "sstream"
#include "cassert"
#include "cctype"
#include "deque"
#include "numeric"
#include "algorithm"
#include "map"
#include "ctime"
#include "list"
#include "bitset"
#include "cstdlib"
#include "stack"
#include "vector"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)

class PlatypusDuckAndBeaver {
public:
    int minimumAnimals(int webbedFeet, int duckBills, int beaverTails) {
        int out=-1;
        int d=webbedFeet/2, b=webbedFeet/4, p=webbedFeet/4;
        int tf, td, tt;
        for (int i=0; i<=d; i++) {
            for (int j=0; j<=b; j++) {
                for (int k=0; k<=p; k++) {
                    tf = i*2 + j*4 + k*4;
                    td = i+k;
                    tt = j+k;

                    if (tf==webbedFeet && td==duckBills && tt == beaverTails) {
                        return i+j+k;
                    }
                }
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
            int webbedFeet = 4;
            int duckBills = 1;
            int beaverTails = 1;
            int expected_ = 1;

            clock_t start_           = clock();
            int received_ = PlatypusDuckAndBeaver().minimumAnimals(webbedFeet, duckBills, beaverTails);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            int webbedFeet = 0;
            int duckBills = 0;
            int beaverTails = 0;
            int expected_ = 0;

            clock_t start_           = clock();
            int received_ = PlatypusDuckAndBeaver().minimumAnimals(webbedFeet, duckBills, beaverTails);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            int webbedFeet = 10;
            int duckBills = 2;
            int beaverTails = 2;
            int expected_ = 3;

            clock_t start_           = clock();
            int received_ = PlatypusDuckAndBeaver().minimumAnimals(webbedFeet, duckBills, beaverTails);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            int webbedFeet = 60;
            int duckBills = 10;
            int beaverTails = 10;
            int expected_ = 20;

            clock_t start_           = clock();
            int received_ = PlatypusDuckAndBeaver().minimumAnimals(webbedFeet, duckBills, beaverTails);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 4: {
            int webbedFeet = 1000;
            int duckBills = 200;
            int beaverTails = 200;
            int expected_ = 300;

            clock_t start_           = clock();
            int received_ = PlatypusDuckAndBeaver().minimumAnimals(webbedFeet, duckBills, beaverTails);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        default:
            return -1;
        }
    }

    //This method will only accept input files that are formatted in proper way.
    //Command line example: PlatypusDuckAndBeaver.exe -2 <PlatypusDuckAndBeaverIO.txt
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        int webbedFeet;
        int duckBills;
        int beaverTails;
        int expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            std::cin>>webbedFeet; std::cin.ignore(10, '\n');
            std::cin>>duckBills; std::cin.ignore(10, '\n');
            std::cin>>beaverTails; std::cin.ignore(10, '\n');
            std::cin>>expected_; std::cin.ignore(10, '\n');
            clock_t start_           = clock();
            int received_ = PlatypusDuckAndBeaver().minimumAnimals(webbedFeet, duckBills, beaverTails);
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
