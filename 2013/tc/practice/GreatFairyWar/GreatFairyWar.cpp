#include "ctime"
#include "vector"
#include "set"
#include "deque"
#include "stack"
#include "cassert"
#include "utility"
#include "cstring"
#include "cctype"
#include "iostream"
#include "iomanip"
#include "cmath"
#include "string"
#include "cstdlib"
#include "queue"
#include "functional"
#include "map"
#include "numeric"
#include "cstdio"
#include "algorithm"
#include "sstream"
#include "bitset"
#include "list"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)

class GreatFairyWar {
public:
    int minHP(vector<int> dps, vector<int> hp) {
        int out;
        int tdps=0;
        for (int i=0; i<dps.size(); i++) {
            tdps+=dps[i];
        }
        out=0;
        for (int i=0; i<hp.size(); i++) {
            out += (hp[i]*tdps);
            tdps -= dps[i];
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
            int dps[] = {1, 2};
            int hp[] = {3, 4};
            int expected_ = 17;

            clock_t start_           = clock();
            int received_ = GreatFairyWar().minHP(vector<int>(dps, dps + (sizeof dps / sizeof dps[0])), vector<int>(hp, hp + (sizeof hp / sizeof hp[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            int dps[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
            int hp[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
            int expected_ = 55;

            clock_t start_           = clock();
            int received_ = GreatFairyWar().minHP(vector<int>(dps, dps + (sizeof dps / sizeof dps[0])), vector<int>(hp, hp + (sizeof hp / sizeof hp[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            int dps[] = {20, 12, 10, 10, 23, 10};
            int hp[] = {5, 7, 7, 5, 7, 7};
            int expected_ = 1767;

            clock_t start_           = clock();
            int received_ = GreatFairyWar().minHP(vector<int>(dps, dps + (sizeof dps / sizeof dps[0])), vector<int>(hp, hp + (sizeof hp / sizeof hp[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            int dps[] = {5, 7, 7, 5, 7, 7};
            int hp[] = {20, 12, 10, 10, 23, 10};
            int expected_ = 1998;

            clock_t start_           = clock();
            int received_ = GreatFairyWar().minHP(vector<int>(dps, dps + (sizeof dps / sizeof dps[0])), vector<int>(hp, hp + (sizeof hp / sizeof hp[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 4: {
            int dps[] = {30, 2, 7, 4, 7, 8, 21, 14, 19, 12};
            int hp[] = {2, 27, 18, 19, 14, 8, 25, 13, 21, 30};
            int expected_ = 11029;

            clock_t start_           = clock();
            int received_ = GreatFairyWar().minHP(vector<int>(dps, dps + (sizeof dps / sizeof dps[0])), vector<int>(hp, hp + (sizeof hp / sizeof hp[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 5: {
            int dps[] = {1};
            int hp[] = {1};
            int expected_ = 1;

            clock_t start_           = clock();
            int received_ = GreatFairyWar().minHP(vector<int>(dps, dps + (sizeof dps / sizeof dps[0])), vector<int>(hp, hp + (sizeof hp / sizeof hp[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        default:
            return -1;
        }
    }

    //This method will only accept input files that are formatted in proper way.
    //Command line example: GreatFairyWar.exe -2 <GreatFairyWarIO.txt
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        vector<int> dps;
        int dps_sin;
        vector<int> hp;
        int hp_sin;
        int expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            dps.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::cin>>dps_sin; std::cin.ignore(10, '\n');
                dps.push_back(dps_sin);
            }
            hp.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::cin>>hp_sin; std::cin.ignore(10, '\n');
                hp.push_back(hp_sin);
            }
            std::cin>>expected_; std::cin.ignore(10, '\n');
            clock_t start_           = clock();
            int received_ = GreatFairyWar().minHP(dps, hp);
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
