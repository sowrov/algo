#include "fstream"
#include "iomanip"
#include "map"
#include "list"
#include "bitset"
#include "utility"
#include "set"
#include "cstdio"
#include "numeric"
#include "algorithm"
#include "cassert"
#include "string"
#include "cctype"
#include "cstdlib"
#include "stack"
#include "iostream"
#include "deque"
#include "ctime"
#include "vector"
#include "cmath"
#include "cstring"
#include "sstream"
#include "queue"
#include "functional"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)
#define Rep(_var, _N) for (int _var=0; _var<_N; _var++ )
#define For(_var, _S,  _N) for (int _var=_S; _var<=_N; _var++ )

class TheShuttles {
public:
    int getLeastCost(vector<int> cnt, int baseCost, int seatCost) {
        int out=1e9;
        
        for (int n=1; n<=100; n++) {
            int v=0;
            for (int i=0; i<cnt.size(); i++) {
                int nc = cnt[i]/n;
                if (cnt[i]%n!=0) {
                    nc++;
                }
                v += nc* (baseCost+n*seatCost);
            }
            out = min(out, v);
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
            int cnt[] = {9};
            int baseCost = 30;
            int seatCost = 5;
            int expected_ = 75;

            clock_t start_           = clock();
            int received_ = TheShuttles().getLeastCost(vector<int>(cnt, cnt + (sizeof cnt / sizeof cnt[0])), baseCost, seatCost);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            int cnt[] = {9, 4};
            int baseCost = 30;
            int seatCost = 5;
            int expected_ = 150;

            clock_t start_           = clock();
            int received_ = TheShuttles().getLeastCost(vector<int>(cnt, cnt + (sizeof cnt / sizeof cnt[0])), baseCost, seatCost);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            int cnt[] = {9, 4};
            int baseCost = 10;
            int seatCost = 5;
            int expected_ = 105;

            clock_t start_           = clock();
            int received_ = TheShuttles().getLeastCost(vector<int>(cnt, cnt + (sizeof cnt / sizeof cnt[0])), baseCost, seatCost);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            int cnt[] = {51, 1, 77, 14, 17, 10, 80};
            int baseCost = 32;
            int seatCost = 40;
            int expected_ = 12096;

            clock_t start_           = clock();
            int received_ = TheShuttles().getLeastCost(vector<int>(cnt, cnt + (sizeof cnt / sizeof cnt[0])), baseCost, seatCost);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        default:
            return -1;
        }
    }

    const std::string currentDateTime() {
        time_t     now = time(0);
        struct tm  tstruct;
        char       buf[80];
        tstruct = *localtime(&now);
        strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);
        return buf;
    }

    //This method will only accept input files that are formatted in proper way.
    //Command line example: TheShuttles.exe -2 <TheShuttles.io
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        vector<int> cnt;
        int cnt_sin;
        int baseCost;
        int seatCost;
        int expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            cnt.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::cin>>cnt_sin; std::cin.ignore(10, '\n');
                cnt.push_back(cnt_sin);
            }
            std::cin>>baseCost; std::cin.ignore(10, '\n');
            std::cin>>seatCost; std::cin.ignore(10, '\n');
            std::cin>>expected_; std::cin.ignore(10, '\n');
            clock_t start_           = clock();
            int received_ = TheShuttles().getLeastCost(cnt, baseCost, seatCost);
            correct += verify_case(caseNo, expected_, received_, clock()-start_);
        }//end of testCase for loop

        if (testCase == 0) {
            cerr << "No test cases run." << endl;
        } else if (correct < testCase) {
            cerr << "Some cases FAILED (passed " << correct << " of " << testCase << ")." << endl;
        } else {
            cerr << "All " << testCase << " tests passed!" << endl;
            std::ofstream ofs("TheShuttles.st", std::ios_base::app);
            ofs<<currentDateTime()<<std::endl;
            ofs.close();
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
