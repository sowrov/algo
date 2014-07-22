#include "sstream"
#include "bitset"
#include "iomanip"
#include "set"
#include "list"
#include "deque"
#include "algorithm"
#include "cstring"
#include "stack"
#include "numeric"
#include "cstdlib"
#include "queue"
#include "cassert"
#include "functional"
#include "cmath"
#include "cctype"
#include "iostream"
#include "string"
#include "ctime"
#include "vector"
#include "utility"
#include "map"
#include "cstdio"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)

class ValueHistogram {
public:
    vector<string> build(vector<int> values) {
        vector<string> out;
        vector <int> arr(10, 0);
        int maxv = 0;
        for (int i=0; i<values.size(); i++) {
            arr[values[i]]++;
            if (arr[values[i]]>maxv) {
                maxv = arr[values[i]];
            }
        }

        string str;

        for (int i=0; i<=maxv; i++) {
            str = "..........";
            for (int j=0; j<10; j++) {
                if (arr[j]>0) {
                    str[j] = 'X';
                    arr[j]--;
                }
            }

            out.push_back(str);

        }

        reverse(out.begin(), out.end());

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
            int values[] = {2, 3, 5, 5, 5, 2, 0, 8};
            string expected_[] = {"..........", ".....X....", "..X..X....", "X.XX.X..X."};

            clock_t start_           = clock();
            vector<string> received_ = ValueHistogram().build(vector<int>(values, values + (sizeof values / sizeof values[0])));
            return verify_case(casenum, vector<string>(expected_, expected_ + (sizeof expected_ / sizeof expected_[0])), received_, clock()-start_);
        }
        case 1: {
            int values[] = {9, 9, 9, 9};
            string expected_[] = {"..........", ".........X", ".........X", ".........X", ".........X"};

            clock_t start_           = clock();
            vector<string> received_ = ValueHistogram().build(vector<int>(values, values + (sizeof values / sizeof values[0])));
            return verify_case(casenum, vector<string>(expected_, expected_ + (sizeof expected_ / sizeof expected_[0])), received_, clock()-start_);
        }
        case 2: {
            int values[] = {6, 4, 0, 0, 3, 9, 8, 8};
            string expected_[] = {"..........", "X.......X.", "X..XX.X.XX"};

            clock_t start_           = clock();
            vector<string> received_ = ValueHistogram().build(vector<int>(values, values + (sizeof values / sizeof values[0])));
            return verify_case(casenum, vector<string>(expected_, expected_ + (sizeof expected_ / sizeof expected_[0])), received_, clock()-start_);
        }
        case 3: {
            int values[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
            string expected_[] = {"..........", "XXXXXXXXXX"};

            clock_t start_           = clock();
            vector<string> received_ = ValueHistogram().build(vector<int>(values, values + (sizeof values / sizeof values[0])));
            return verify_case(casenum, vector<string>(expected_, expected_ + (sizeof expected_ / sizeof expected_[0])), received_, clock()-start_);
        }
        case 4: {
            int values[] = {6, 2, 3, 3, 3, 7, 8, 1, 0, 9, 2, 2, 4, 3};
            string expected_[] = {"..........", "...X......", "..XX......", "..XX......", "XXXXX.XXXX"};

            clock_t start_           = clock();
            vector<string> received_ = ValueHistogram().build(vector<int>(values, values + (sizeof values / sizeof values[0])));
            return verify_case(casenum, vector<string>(expected_, expected_ + (sizeof expected_ / sizeof expected_[0])), received_, clock()-start_);
        }
        default:
            return -1;
        }
    }

    //This method will only accept input files that are formatted in proper way.
    //Command line example: ValueHistogram.exe -2 <ValueHistogram.io
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        vector<int> values;
        int values_sin;
        vector<string> expected_;
        string expected__sin;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            values.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::cin>>values_sin; std::cin.ignore(10, '\n');
                values.push_back(values_sin);
            }
            expected_.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::getline(std::cin,expected__sin );
                expected_.push_back(expected__sin);
            }
            clock_t start_           = clock();
            vector<string> received_ = ValueHistogram().build(values);
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
