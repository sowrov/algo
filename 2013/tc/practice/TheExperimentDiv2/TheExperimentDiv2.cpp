#include "functional"
#include "cstdlib"
#include "iomanip"
#include "cmath"
#include "cstdio"
#include "set"
#include "iostream"
#include "ctime"
#include "numeric"
#include "queue"
#include "algorithm"
#include "cctype"
#include "bitset"
#include "map"
#include "list"
#include "utility"
#include "deque"
#include "sstream"
#include "vector"
#include "string"
#include "cstring"
#include "stack"
#include "cassert"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)

class TheExperimentDiv2 {
public:
    vector<int> determineHumidity(vector<int> intensity, int L, vector<int> leftEnd) {
        vector<int> out;
        vector<bool> flg(intensity.size(), true);

        for(int i=0; i<leftEnd.size(); i++) {
            int inten=0;
            for (int j=leftEnd[i]; j<leftEnd[i]+L; j++) {
                if(flg[j]) {
                    inten += intensity[j];
                    flg[j] = false;
                }
            }
            out.push_back(inten);
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
            int intensity[] = {3, 4, 1, 1, 5, 6};
            int L = 3;
            int leftEnd[] = {3, 1, 0};
            int expected_[] = {12, 5, 3};

            clock_t start_           = clock();
            vector<int> received_ = TheExperimentDiv2().determineHumidity(vector<int>(intensity, intensity + (sizeof intensity / sizeof intensity[0])), L, vector<int>(leftEnd, leftEnd + (sizeof leftEnd / sizeof leftEnd[0])));
            return verify_case(casenum, vector<int>(expected_, expected_ + (sizeof expected_ / sizeof expected_[0])), received_, clock()-start_);
        }
        case 1: {
            int intensity[] = {5, 5};
            int L = 2;
            int leftEnd[] = {0, 0};
            int expected_[] = {10, 0};

            clock_t start_           = clock();
            vector<int> received_ = TheExperimentDiv2().determineHumidity(vector<int>(intensity, intensity + (sizeof intensity / sizeof intensity[0])), L, vector<int>(leftEnd, leftEnd + (sizeof leftEnd / sizeof leftEnd[0])));
            return verify_case(casenum, vector<int>(expected_, expected_ + (sizeof expected_ / sizeof expected_[0])), received_, clock()-start_);
        }
        case 2: {
            int intensity[] = {92, 11, 1000, 14, 3};
            int L = 2;
            int leftEnd[] = {0, 3};
            int expected_[] = {103, 17};

            clock_t start_           = clock();
            vector<int> received_ = TheExperimentDiv2().determineHumidity(vector<int>(intensity, intensity + (sizeof intensity / sizeof intensity[0])), L, vector<int>(leftEnd, leftEnd + (sizeof leftEnd / sizeof leftEnd[0])));
            return verify_case(casenum, vector<int>(expected_, expected_ + (sizeof expected_ / sizeof expected_[0])), received_, clock()-start_);
        }
        case 3: {
            int intensity[] = {2, 6, 15, 10, 8, 11, 99, 2, 4, 4, 4, 13};
            int L = 4;
            int leftEnd[] = {1, 7, 4, 5, 8, 0};
            int expected_[] = {39, 14, 110, 0, 13, 2};

            clock_t start_           = clock();
            vector<int> received_ = TheExperimentDiv2().determineHumidity(vector<int>(intensity, intensity + (sizeof intensity / sizeof intensity[0])), L, vector<int>(leftEnd, leftEnd + (sizeof leftEnd / sizeof leftEnd[0])));
            return verify_case(casenum, vector<int>(expected_, expected_ + (sizeof expected_ / sizeof expected_[0])), received_, clock()-start_);
        }
        default:
            return -1;
        }
    }

    //This method will only accept input files that are formatted in proper way.
    //Command line example: TheExperimentDiv2.exe -2 <TheExperimentDiv2IO.txt
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        vector<int> intensity;
        int intensity_sin;
        int L;
        vector<int> leftEnd;
        int leftEnd_sin;
        vector<int> expected_;
        int expected__sin;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            intensity.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::cin>>intensity_sin; std::cin.ignore(10, '\n');
                intensity.push_back(intensity_sin);
            }
            std::cin>>L; std::cin.ignore(10, '\n');
            leftEnd.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::cin>>leftEnd_sin; std::cin.ignore(10, '\n');
                leftEnd.push_back(leftEnd_sin);
            }
            expected_.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::cin>>expected__sin; std::cin.ignore(10, '\n');
                expected_.push_back(expected__sin);
            }
            clock_t start_           = clock();
            vector<int> received_ = TheExperimentDiv2().determineHumidity(intensity, L, leftEnd);
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
