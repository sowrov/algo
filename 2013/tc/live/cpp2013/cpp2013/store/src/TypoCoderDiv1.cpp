#include "cstdlib"
#include "list"
#include "cassert"
#include "fstream"
#include "functional"
#include "iostream"
#include "vector"
#include "set"
#include "map"
#include "stack"
#include "iomanip"
#include "cstring"
#include "queue"
#include "bitset"
#include "cctype"
#include "ctime"
#include "deque"
#include "sstream"
#include "numeric"
#include "algorithm"
#include "utility"
#include "cstdio"
#include "string"
#include "cmath"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)
#define Rep(_var, _N) for (int _var=0; _var<_N; _var++ )
#define For(_var, _S,  _N) for (int _var=_S; _var<=_N; _var++ )
#define M 2200
int dp[51][M+1];
class TypoCoderDiv1 {
public:
    vector<int> d;
    int memo(int s, int v) {
        if (s==d.size()) {
            return 0;
        }
        if (v < M && dp[s][v]!=-1) {
            return dp[s][v];
        }
        if (v>=M) {
            if (v - d[s]  >= M ) {
                return -1;
            }
            return memo(s+1, v-min(v, d[s])) + 1;
        } else {
            int up = memo(s+1, v+d[s]) + ((v+d[s])>=M?1:0);
            int down = memo(s+1,  v-min(v, d[s]));
            dp[s][v] = max(up, down);
            return dp[s][v];
        }
    }
    int getmax(vector<int> D, int X) {
        int out;
        Nclr(dp);
        d = D;
        //printf("%d", d[0]);
        //return 0;
        return memo(0, X);
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
            int D[] = {100, 200, 100, 1, 1};
            int X = 2000;
            int expected_ = 3;

            clock_t start_           = clock();
            int received_ = TypoCoderDiv1().getmax(vector<int>(D, D + (sizeof D / sizeof D[0])), X);
            return verify_case(casenum, expected_, received_, clock()-start_);
                }
        case 1: {
            int D[] = {0, 0, 0, 0, 0};
            int X = 2199;
            int expected_ = 0;

            clock_t start_           = clock();
            int received_ = TypoCoderDiv1().getmax(vector<int>(D, D + (sizeof D / sizeof D[0])), X);
            return verify_case(casenum, expected_, received_, clock()-start_);
                }
        case 2: {
            int D[] = {90000, 80000, 70000, 60000, 50000, 40000, 30000, 20000, 10000};
            int X = 0;
            int expected_ = 1;

            clock_t start_           = clock();
            int received_ = TypoCoderDiv1().getmax(vector<int>(D, D + (sizeof D / sizeof D[0])), X);
            return verify_case(casenum, expected_, received_, clock()-start_);
                }
        case 3: {
            int D[] = {1000000000, 1000000000, 10000, 100000, 2202, 1};
            int X = 1000;
            int expected_ = 4;

            clock_t start_           = clock();
            int received_ = TypoCoderDiv1().getmax(vector<int>(D, D + (sizeof D / sizeof D[0])), X);
            return verify_case(casenum, expected_, received_, clock()-start_);
                }
        case 4: {
            int D[] = {2048, 1024, 5012, 256, 128, 64, 32, 16, 8, 4, 2, 1, 0};
            int X = 2199;
            int expected_ = 0;

            clock_t start_           = clock();
            int received_ = TypoCoderDiv1().getmax(vector<int>(D, D + (sizeof D / sizeof D[0])), X);
            return verify_case(casenum, expected_, received_, clock()-start_);
                }
        case 5: {
            int D[] = {61, 666, 512, 229, 618, 419, 757, 217, 458, 883, 23, 932, 547, 679, 565, 767, 513, 798, 870, 31, 379, 294, 929, 892, 173, 127, 796, 353, 913, 115, 802, 803, 948, 592, 959, 127, 501, 319, 140, 694, 851, 189, 924, 590, 790, 3, 669, 541, 342, 272};
            int X = 1223;
            int expected_ = 29;

            clock_t start_           = clock();
            int received_ = TypoCoderDiv1().getmax(vector<int>(D, D + (sizeof D / sizeof D[0])), X);
            return verify_case(casenum, expected_, received_, clock()-start_);
                }
        case 6: {
            int D[] = {34, 64, 43, 14, 58, 30, 2, 16, 90, 58, 35, 55, 46, 24, 14, 73, 96, 13, 9, 42, 64, 36, 89, 42, 42, 64, 52, 68, 53, 76, 52, 54, 23, 88, 32, 52, 28, 96, 70, 32, 26, 3, 23, 78, 47, 23, 54, 30, 86, 32};
            int X = 1328;
            int expected_ = 20;

            clock_t start_           = clock();
            int received_ = TypoCoderDiv1().getmax(vector<int>(D, D + (sizeof D / sizeof D[0])), X);
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
    //Command line example: TypoCoderDiv1.exe -2 <TypoCoderDiv1IO.txt
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        vector<int> D;
        int D_sin;
        int X;
        int expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            D.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::cin>>D_sin; std::cin.ignore(10, '\n');
                D.push_back(D_sin);
            }
            std::cin>>X; std::cin.ignore(10, '\n');
            std::cin>>expected_; std::cin.ignore(10, '\n');
            clock_t start_           = clock();
            int received_ = TypoCoderDiv1().getmax(D, X);
            correct += verify_case(caseNo, expected_, received_, clock()-start_);
        }//end of testCase for loop

        if (testCase == 0) {
            cerr << "No test cases run." << endl;
        } else if (correct < testCase) {
            cerr << "Some cases FAILED (passed " << correct << " of " << testCase << ")." << endl;
        } else {
            cerr << "All " << testCase << " tests passed!" << endl;
            std::ofstream ofs("TypoCoderDiv1.st", std::ios_base::app);
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
