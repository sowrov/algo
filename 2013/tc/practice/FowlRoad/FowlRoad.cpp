#include "cmath"
#include "algorithm"
#include "bitset"
#include "set"
#include "functional"
#include "cstring"
#include "iostream"
#include "utility"
#include "string"
#include "iomanip"
#include "list"
#include "cstdio"
#include "ctime"
#include "numeric"
#include "sstream"
#include "deque"
#include "vector"
#include "stack"
#include "map"
#include "queue"
#include "cassert"
#include "cstdlib"
#include "cctype"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)

class FowlRoad {
public:
    int crossings(int roadY, vector<int> bobX, vector<int> bobY) {
        int out=0;
        bool flag=0;
        if(bobY[0] > roadY) {
            flag=1;
        }

        for(int i=1; i<bobX.size(); i++) {
            if(bobY[i]<roadY && flag) {
                flag=0;
                out++;
            } else if(bobY[i]>roadY && !flag) {
                flag=1;
                out++;
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
            int roadY = 6;
            int bobX[] = {3, 7, 9, 2};
            int bobY[] = {-3, 8, 8, 2};
            int expected_ = 2;

            clock_t start_           = clock();
            int received_ = FowlRoad().crossings(roadY, vector<int>(bobX, bobX + (sizeof bobX / sizeof bobX[0])), vector<int>(bobY, bobY + (sizeof bobY / sizeof bobY[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            int roadY = 10;
            int bobX[] = {3, 7, 9, 2};
            int bobY[] = {-3, 8, 8, 2};
            int expected_ = 0;

            clock_t start_           = clock();
            int received_ = FowlRoad().crossings(roadY, vector<int>(bobX, bobX + (sizeof bobX / sizeof bobX[0])), vector<int>(bobY, bobY + (sizeof bobY / sizeof bobY[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            int roadY = 0;
            int bobX[] = {3, 2, 5, 6, 9};
            int bobY[] = {2, 0, 0, 2, -88};
            int expected_ = 1;

            clock_t start_           = clock();
            int received_ = FowlRoad().crossings(roadY, vector<int>(bobX, bobX + (sizeof bobX / sizeof bobX[0])), vector<int>(bobY, bobY + (sizeof bobY / sizeof bobY[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            int roadY = 0;
            int bobX[] = {3, 2, 5, 6, 9};
            int bobY[] = {-2, 0, 0, 2, -88};
            int expected_ = 2;

            clock_t start_           = clock();
            int received_ = FowlRoad().crossings(roadY, vector<int>(bobX, bobX + (sizeof bobX / sizeof bobX[0])), vector<int>(bobY, bobY + (sizeof bobY / sizeof bobY[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        default:
            return -1;
        }
    }

    //This method will only accept input files that are formatted in proper way.
    //Command line example: FowlRoad.exe -2 <FowlRoad.io
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        int roadY;
        vector<int> bobX;
        int bobX_sin;
        vector<int> bobY;
        int bobY_sin;
        int expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            std::cin>>roadY; std::cin.ignore(10, '\n');
            bobX.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::cin>>bobX_sin; std::cin.ignore(10, '\n');
                bobX.push_back(bobX_sin);
            }
            bobY.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::cin>>bobY_sin; std::cin.ignore(10, '\n');
                bobY.push_back(bobY_sin);
            }
            std::cin>>expected_; std::cin.ignore(10, '\n');
            clock_t start_           = clock();
            int received_ = FowlRoad().crossings(roadY, bobX, bobY);
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
