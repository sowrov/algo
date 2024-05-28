#include "algorithm"
#include "ctime"
#include "list"
#include "cstring"
#include "cstdlib"
#include "numeric"
#include "cassert"
#include "functional"
#include "cstdio"
#include "deque"
#include "string"
#include "cmath"
#include "cctype"
#include "set"
#include "iostream"
#include "queue"
#include "iomanip"
#include "utility"
#include "bitset"
#include "map"
#include "sstream"
#include "stack"
#include "vector"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)

class NextOrPrev {
public:
    int getMinimum(int nextCost, int prevCost, string start, string goal) {
        int out=0;
        for (int i=0; i<start.size(); i++) {
            for (int j=i+1; j<start.size(); j++) {
                if (start[j]>start[i] && goal[j]<goal[i] ||
                    start[j]<start[i] && goal[j]>goal[i]) {
                    return -1;
                }
            }
        }
        for (int i=0; i<start.size(); i++) {
            if (goal[i]<start[i]) {
                out += (start[i]-goal[i])*prevCost;
            } else if (goal[i]>start[i]) {
                out += (goal[i]-start[i])*nextCost;
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
            int nextCost = 5;
            int prevCost = 8;
            string start = "ae";
            string goal = "bc";
            int expected_ = 21;

            clock_t start_           = clock();
            int received_ = NextOrPrev().getMinimum(nextCost, prevCost, start, goal);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            int nextCost = 5;
            int prevCost = 8;
            string start = "ae";
            string goal = "cb";
            int expected_ = -1;

            clock_t start_           = clock();
            int received_ = NextOrPrev().getMinimum(nextCost, prevCost, start, goal);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            int nextCost = 1;
            int prevCost = 1;
            string start = "srm";
            string goal = "srm";
            int expected_ = 0;

            clock_t start_           = clock();
            int received_ = NextOrPrev().getMinimum(nextCost, prevCost, start, goal);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            int nextCost = 10;
            int prevCost = 1;
            string start = "acb";
            string goal = "bdc";
            int expected_ = 30;

            clock_t start_           = clock();
            int received_ = NextOrPrev().getMinimum(nextCost, prevCost, start, goal);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 4: {
            int nextCost = 10;
            int prevCost = 1;
            string start = "zyxw";
            string goal = "vuts";
            int expected_ = 16;

            clock_t start_           = clock();
            int received_ = NextOrPrev().getMinimum(nextCost, prevCost, start, goal);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 5: {
            int nextCost = 563;
            int prevCost = 440;
            string start = "ptrbgcnlaizo";
            string goal = "rtscedkiahul";
            int expected_ = 10295;

            clock_t start_           = clock();
            int received_ = NextOrPrev().getMinimum(nextCost, prevCost, start, goal);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 6: {
            int nextCost = 126;
            int prevCost = 311;
            string start = "yovlkwpjgsna";
            string goal = "zpwnkytjisob";
            int expected_ = -1;

            clock_t start_           = clock();
            int received_ = NextOrPrev().getMinimum(nextCost, prevCost, start, goal);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        default:
            return -1;
        }
    }

    //This method will only accept input files that are formatted in proper way.
    //Command line example: NextOrPrev.exe -2 <NextOrPrevIO.txt
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        int nextCost;
        int prevCost;
        string start;
        string goal;
        int expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            std::cin>>nextCost; std::cin.ignore(10, '\n');
            std::cin>>prevCost; std::cin.ignore(10, '\n');
            std::getline(std::cin,start);
            std::getline(std::cin,goal);
            std::cin>>expected_; std::cin.ignore(10, '\n');
            clock_t start_           = clock();
            int received_ = NextOrPrev().getMinimum(nextCost, prevCost, start, goal);
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
