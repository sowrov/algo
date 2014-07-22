#include "numeric"
#include "cctype"
#include "algorithm"
#include "cstdio"
#include "iostream"
#include "vector"
#include "cstring"
#include "bitset"
#include "set"
#include "functional"
#include "iomanip"
#include "stack"
#include "map"
#include "deque"
#include "cmath"
#include "list"
#include "utility"
#include "string"
#include "ctime"
#include "sstream"
#include "cassert"
#include "cstdlib"
#include "queue"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)

class Abacus {
public:
    vector<string> add(vector<string> original, int val) {
        vector<string> out;
        int num=0;
        char arr[6];
        for(int i=0; i<6; i++) {
            bool fl=0;
            int v=0;
            for(int j=0; j<original[i].size(); j++) {
                if(original[i][j]=='-') {
                    fl=1;
                }
                else if(fl) {
                    v++;
                }
            }
            num = num*10 + v;
        }
        num += val;
        sprintf(arr, "%06d", num);
        char nums[13];
        nums[12]=0;
        for(int i=0; i<6; i++) {
            int v = arr[i]-'0';
            int f=9-v;
            for (int j=0; j<f; j++) {
                nums[j]='o';
            }
            nums[f]=nums[f+1]=nums[f+2]='-';
            for(int j=f+3; j<12; j++) {
                nums[j]='o';
            }
            out.push_back(nums);
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
    template<> ostream& operator<<(ostream &os, const vector<string> &v) { os << "{"; for (vector<string>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " \"" << *vi << "\""; } os << " }"; return os; }


    int verify_case(int casenum, const vector<string> &expected, const vector<string> &received, clock_t elapsed) { 
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
            string original[] = {"ooooooooo---", "ooooooooo---", "ooooooooo---", "ooooooooo---", "ooooooooo---", "ooooooooo---"};
            int val = 0;
            string expected_[] = {"ooooooooo---", "ooooooooo---", "ooooooooo---", "ooooooooo---", "ooooooooo---", "ooooooooo---"};

            clock_t start_           = clock();
            vector<string> received_ = Abacus().add(vector<string>(original, original + (sizeof original / sizeof original[0])), val);
            return verify_case(casenum, vector<string>(expected_, expected_ + (sizeof expected_ / sizeof expected_[0])), received_, clock()-start_);
        }
        case 1: {
            string original[] = {"ooo---oooooo", "---ooooooooo", "---ooooooooo", "---ooooooooo", "oo---ooooooo", "---ooooooooo"};
            int val = 21;
            string expected_[] = {"oo---ooooooo", "ooooooooo---", "ooooooooo---", "ooooooooo---", "ooooooooo---", "ooooooooo---"};

            clock_t start_           = clock();
            vector<string> received_ = Abacus().add(vector<string>(original, original + (sizeof original / sizeof original[0])), val);
            return verify_case(casenum, vector<string>(expected_, expected_ + (sizeof expected_ / sizeof expected_[0])), received_, clock()-start_);
        }
        case 2: {
            string original[] = {"ooooooooo---", "---ooooooooo", "ooooooooo---", "---ooooooooo", "oo---ooooooo", "---ooooooooo"};
            int val = 100000;
            string expected_[] = {"oooooooo---o", "---ooooooooo", "ooooooooo---", "---ooooooooo", "oo---ooooooo", "---ooooooooo"};

            clock_t start_           = clock();
            vector<string> received_ = Abacus().add(vector<string>(original, original + (sizeof original / sizeof original[0])), val);
            return verify_case(casenum, vector<string>(expected_, expected_ + (sizeof expected_ / sizeof expected_[0])), received_, clock()-start_);
        }
        case 3: {
            string original[] = {"o---oooooooo", "---ooooooooo", "---ooooooooo", "---ooooooooo", "---ooooooooo", "---ooooooooo"};
            int val = 1;
            string expected_[] = {"---ooooooooo", "ooooooooo---", "ooooooooo---", "ooooooooo---", "ooooooooo---", "ooooooooo---"};

            clock_t start_           = clock();
            vector<string> received_ = Abacus().add(vector<string>(original, original + (sizeof original / sizeof original[0])), val);
            return verify_case(casenum, vector<string>(expected_, expected_ + (sizeof expected_ / sizeof expected_[0])), received_, clock()-start_);
        }
        default:
            return -1;
        }
    }

    //This method will only accept input files that are formatted in proper way.
    //Command line example: Abacus.exe -2 <Abacus.io
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        vector<string> original;
        string original_sin;
        int val;
        vector<string> expected_;
        string expected__sin;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            original.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::getline(std::cin,original_sin );
                original.push_back(original_sin);
            }
            std::cin>>val; std::cin.ignore(10, '\n');
            expected_.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::getline(std::cin,expected__sin );
                expected_.push_back(expected__sin);
            }
            clock_t start_           = clock();
            vector<string> received_ = Abacus().add(original, val);
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
