#include "iostream"
#include "algorithm"
#include "functional"
#include "cmath"
#include "sstream"
#include "cctype"
#include "cstdio"
#include "fstream"
#include "deque"
#include "map"
#include "list"
#include "numeric"
#include "ctime"
#include "stack"
#include "cstring"
#include "cstdlib"
#include "set"
#include "cassert"
#include "utility"
#include "vector"
#include "bitset"
#include "iomanip"
#include "queue"
#include "string"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)
#define Rep(_var, _N) for (int _var=0; _var<_N; _var++ )
#define For(_var, _S,  _N) for (int _var=_S; _var<=_N; _var++ )

class TheProgrammingContestDivTwo {
public:
    vector<int> find(int T, vector<int> rtim) {
        vector<int> out;
        sort(rtim.begin(), rtim.end());
        int t=0, p=0, v=0;

        for (int i=0; i<rtim.size(); i++) {
            if (T-rtim[i]>=0) {
                T-=rtim[i];
                t+=rtim[i];
                v+=t;
                p++;
            } else {
                break;
            }
        }
        out.push_back(p);
        out.push_back(v);
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

    template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }


    int verify_case(int casenum, const vector<int> &expected, const vector<int> &received, clock_t elapsed) { 
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
            int T = 74;
            int requiredTime[] = {47};
            int expected_[] = {1, 47};

            clock_t start_           = clock();
            vector<int> received_ = TheProgrammingContestDivTwo().find(T, vector<int>(requiredTime, requiredTime + (sizeof requiredTime / sizeof requiredTime[0])));
            return verify_case(casenum, vector<int>(expected_, expected_ + (sizeof expected_ / sizeof expected_[0])), received_, clock()-start_);
        }
        case 1: {
            int T = 74;
            int requiredTime[] = {4747};
            int expected_[] = {0, 0};

            clock_t start_           = clock();
            vector<int> received_ = TheProgrammingContestDivTwo().find(T, vector<int>(requiredTime, requiredTime + (sizeof requiredTime / sizeof requiredTime[0])));
            return verify_case(casenum, vector<int>(expected_, expected_ + (sizeof expected_ / sizeof expected_[0])), received_, clock()-start_);
        }
        case 2: {
            int T = 47;
            int requiredTime[] = {8, 5};
            int expected_[] = {2, 18};

            clock_t start_           = clock();
            vector<int> received_ = TheProgrammingContestDivTwo().find(T, vector<int>(requiredTime, requiredTime + (sizeof requiredTime / sizeof requiredTime[0])));
            return verify_case(casenum, vector<int>(expected_, expected_ + (sizeof expected_ / sizeof expected_[0])), received_, clock()-start_);
        }
        case 3: {
            int T = 47;
            int requiredTime[] = {12, 3, 21, 6, 4, 13};
            int expected_[] = {5, 86};

            clock_t start_           = clock();
            vector<int> received_ = TheProgrammingContestDivTwo().find(T, vector<int>(requiredTime, requiredTime + (sizeof requiredTime / sizeof requiredTime[0])));
            return verify_case(casenum, vector<int>(expected_, expected_ + (sizeof expected_ / sizeof expected_[0])), received_, clock()-start_);
        }
        case 4: {
            int T = 58;
            int requiredTime[] = {4, 5, 82, 3, 4, 65, 7, 6, 8, 7, 6, 4, 8, 7, 6, 37, 8};
            int expected_[] = {10, 249};

            clock_t start_           = clock();
            vector<int> received_ = TheProgrammingContestDivTwo().find(T, vector<int>(requiredTime, requiredTime + (sizeof requiredTime / sizeof requiredTime[0])));
            return verify_case(casenum, vector<int>(expected_, expected_ + (sizeof expected_ / sizeof expected_[0])), received_, clock()-start_);
        }
        case 5: {
            int T = 100000;
            int requiredTime[] = {100000};
            int expected_[] = {1, 100000};

            clock_t start_           = clock();
            vector<int> received_ = TheProgrammingContestDivTwo().find(T, vector<int>(requiredTime, requiredTime + (sizeof requiredTime / sizeof requiredTime[0])));
            return verify_case(casenum, vector<int>(expected_, expected_ + (sizeof expected_ / sizeof expected_[0])), received_, clock()-start_);
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
    //Command line example: TheProgrammingContestDivTwo.exe -2 <TheProgrammingContestDivTwoIO.txt
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        int T;
        vector<int> requiredTime;
        int requiredTime_sin;
        vector<int> expected_;
        int expected__sin;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            std::cin>>T; std::cin.ignore(10, '\n');
            requiredTime.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::cin>>requiredTime_sin; std::cin.ignore(10, '\n');
                requiredTime.push_back(requiredTime_sin);
            }
            expected_.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::cin>>expected__sin; std::cin.ignore(10, '\n');
                expected_.push_back(expected__sin);
            }
            clock_t start_           = clock();
            vector<int> received_ = TheProgrammingContestDivTwo().find(T, requiredTime);
            correct += verify_case(caseNo, expected_, received_, clock()-start_);
        }//end of testCase for loop

        if (testCase == 0) {
            cerr << "No test cases run." << endl;
        } else if (correct < testCase) {
            cerr << "Some cases FAILED (passed " << correct << " of " << testCase << ")." << endl;
        } else {
            cerr << "All " << testCase << " tests passed!" << endl;
            std::ofstream ofs("TheProgrammingContestDivTwo.st", std::ios_base::app);
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
