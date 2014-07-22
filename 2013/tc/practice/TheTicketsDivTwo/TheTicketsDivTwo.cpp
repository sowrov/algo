#include "vector"
#include "algorithm"
#include "deque"
#include "iostream"
#include "cassert"
#include "cctype"
#include "cstdio"
#include "ctime"
#include "fstream"
#include "string"
#include "functional"
#include "map"
#include "queue"
#include "stack"
#include "iomanip"
#include "cstring"
#include "numeric"
#include "bitset"
#include "sstream"
#include "utility"
#include "set"
#include "cmath"
#include "list"
#include "cstdlib"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)
#define Rep(_var, _N) for (int _var=0; _var<_N; _var++ )
#define For(_var, _S,  _N) for (int _var=_S; _var<=_N; _var++ )

double dpm[11][11][11];
class TheTicketsDivTwo {
public:
    double find(int n, int m, int k) {
        double out=0;
        //if (k<m) return 0;
        For(i, 0, 10) For(j, 0, 10) For(l, 0, 10) dpm[i][j][l]=-2.0;
        return dp(n, m, k);
    }

    double dp(int n, int m, int k) {
        if (k==0) {
            if (m==1) return 1.0;
            return 0;
        }
        if (n==1) {
            if (m==1) return 1.0;
            return 0;
        }
        double &res = dpm[n][m][k];
        //cout<<n<<" "<<m<<" "<<k<<" "<<res<<endl;
        if (res>-1.0) return res;
        res=0;
        if (m==1) {
            res=(1.0/6.0) + (1.0/2.0)*dp(n, n, k-1);
        } else {
            res=((1.0/2.0)*dp(n, m-1, k-1))+((1.0/3.0)*dp(n-1,m-1, k-1));
            //cout<<res<<endl;
        }

        return res;
    }
};

// <editor-fold defaultstate="collapsed" desc="Generated Code">
namespace otocoder {
#ifndef isinf
#define isinf(x) std::isinf(x)
//(!_finite(x))
#define isnan(x) std::isnan(x)
//_isnan(x)
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
            int n = 2;
            int m = 1;
            int k = 1;
            double expected_ = 0.16666666666666666;

            clock_t start_           = clock();
            double received_ = TheTicketsDivTwo().find(n, m, k);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            int n = 2;
            int m = 1;
            int k = 2;
            double expected_ = 0.5833333333333334;

            clock_t start_           = clock();
            double received_ = TheTicketsDivTwo().find(n, m, k);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            int n = 7;
            int m = 7;
            int k = 4;
            double expected_ = 0.0;

            clock_t start_           = clock();
            double received_ = TheTicketsDivTwo().find(n, m, k);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            int n = 4;
            int m = 2;
            int k = 10;
            double expected_ = 0.25264033564814814;

            clock_t start_           = clock();
            double received_ = TheTicketsDivTwo().find(n, m, k);
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
    //Command line example: TheTicketsDivTwo.exe -2 <TheTicketsDivTwo.io
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        int n;
        int m;
        int k;
        double expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            std::cin>>n; std::cin.ignore(10, '\n');
            std::cin>>m; std::cin.ignore(10, '\n');
            std::cin>>k; std::cin.ignore(10, '\n');
            std::cin>>expected_; std::cin.ignore(10, '\n');
            clock_t start_           = clock();
            double received_ = TheTicketsDivTwo().find(n, m, k);
            correct += verify_case(caseNo, expected_, received_, clock()-start_);
        }//end of testCase for loop

        if (testCase == 0) {
            cerr << "No test cases run." << endl;
        } else if (correct < testCase) {
            cerr << "Some cases FAILED (passed " << correct << " of " << testCase << ")." << endl;
        } else {
            cerr << "All " << testCase << " tests passed!" << endl;
            std::ofstream ofs("TheTicketsDivTwo.st", std::ios_base::app);
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
