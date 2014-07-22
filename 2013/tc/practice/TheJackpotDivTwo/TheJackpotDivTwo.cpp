#include "fstream"
#include "queue"
#include "functional"
#include "vector"
#include "deque"
#include "list"
#include "utility"
#include "iomanip"
#include "cctype"
#include "cmath"
#include "sstream"
#include "cassert"
#include "map"
#include "cstring"
#include "ctime"
#include "algorithm"
#include "set"
#include "numeric"
#include "cstdlib"
#include "string"
#include "cstdio"
#include "bitset"
#include "stack"
#include "iostream"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)
#define Rep(_var, _N) for (int _var=0; _var<_N; _var++ )
#define For(_var, _S,  _N) for (int _var=_S; _var<=_N; _var++ )
class TheJackpotDivTwo {
public:
    vector<int> find(vector<int> money, int jackpot) {
        vector<int> out;
        sort(money.begin(), money.end());

        while(jackpot-->0) {
            int v = money[0]+1;
            int i=1;
            while(i<money.size() && v>money[i]) {
                money[i-1]=money[i];
                i++;
            }
            money[i-1]=v;
        }
        return money;
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
            int money[] = {1, 2, 3, 4};
            int jackpot = 2;
            int expected_[] = {2, 3, 3, 4};

            clock_t start_           = clock();
            vector<int> received_ = TheJackpotDivTwo().find(vector<int>(money, money + (sizeof money / sizeof money[0])), jackpot);
            return verify_case(casenum, vector<int>(expected_, expected_ + (sizeof expected_ / sizeof expected_[0])), received_, clock()-start_);
        }
        case 1: {
            int money[] = {4, 7};
            int jackpot = 1;
            int expected_[] = {5, 7};

            clock_t start_           = clock();
            vector<int> received_ = TheJackpotDivTwo().find(vector<int>(money, money + (sizeof money / sizeof money[0])), jackpot);
            return verify_case(casenum, vector<int>(expected_, expected_ + (sizeof expected_ / sizeof expected_[0])), received_, clock()-start_);
        }
        case 2: {
            int money[] = {1};
            int jackpot = 100;
            int expected_[] = {101};

            clock_t start_           = clock();
            vector<int> received_ = TheJackpotDivTwo().find(vector<int>(money, money + (sizeof money / sizeof money[0])), jackpot);
            return verify_case(casenum, vector<int>(expected_, expected_ + (sizeof expected_ / sizeof expected_[0])), received_, clock()-start_);
        }
        case 3: {
            int money[] = {21, 85, 6, 54, 70, 100, 91, 60, 71};
            int jackpot = 15;
            int expected_[] = {21, 21, 54, 60, 70, 71, 85, 91, 100};

            clock_t start_           = clock();
            vector<int> received_ = TheJackpotDivTwo().find(vector<int>(money, money + (sizeof money / sizeof money[0])), jackpot);
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
    //Command line example: TheJackpotDivTwo.exe -2 <TheJackpotDivTwo.io
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        vector<int> money;
        int money_sin;
        int jackpot;
        vector<int> expected_;
        int expected__sin;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            money.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::cin>>money_sin; std::cin.ignore(10, '\n');
                money.push_back(money_sin);
            }
            std::cin>>jackpot; std::cin.ignore(10, '\n');
            expected_.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::cin>>expected__sin; std::cin.ignore(10, '\n');
                expected_.push_back(expected__sin);
            }
            clock_t start_           = clock();
            vector<int> received_ = TheJackpotDivTwo().find(money, jackpot);
            correct += verify_case(caseNo, expected_, received_, clock()-start_);
        }//end of testCase for loop

        if (testCase == 0) {
            cerr << "No test cases run." << endl;
        } else if (correct < testCase) {
            cerr << "Some cases FAILED (passed " << correct << " of " << testCase << ")." << endl;
        } else {
            cerr << "All " << testCase << " tests passed!" << endl;
            std::ofstream ofs("TheJackpotDivTwo.st", std::ios_base::app);
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
