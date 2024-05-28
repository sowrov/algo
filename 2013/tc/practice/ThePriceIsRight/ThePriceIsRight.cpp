#include "string"
#include "cstdio"
#include "deque"
#include "cmath"
#include "numeric"
#include "bitset"
#include "cstring"
#include "utility"
#include "map"
#include "functional"
#include "iostream"
#include "sstream"
#include "cctype"
#include "set"
#include "vector"
#include "cstdlib"
#include "list"
#include "stack"
#include "iomanip"
#include "queue"
#include "cassert"
#include "ctime"
#include "algorithm"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)

class ThePriceIsRight {
public:
    vector<int> howManyReveals(vector<int> prices) {
        vector<int> out;
        int length[51]={1}, ways[51]={1};
        
        for (int i=0; i<prices.size(); i++) {
            length[i] = 1; ways[i] = 1;
        }

        for (int i=0; i<prices.size(); i++) {
            for (int j=i+1; j<prices.size(); j++) {
                if (prices[j]>prices[i]) {
                    if (length[i]+1 > length[j]) {
                        length[j] = length[i]+1;
                        ways[j] = ways[i];
                    } else if (length[i]+1==length[j]) {
                        ways[j] += ways[i];
                    }
                }
            }
        }

        int maxLen=0, ind, count=0;

        for (int i=0; i<prices.size(); i++) {
            if (length[i]>maxLen) {
                maxLen = length[i];
                ind = i;
            }
        }


        for (int i=0; i<prices.size(); i++) {
            if (length[i]==maxLen) {
                count+=ways[i];
            }
        }

        out.push_back(length[ind]);
        out.push_back(count);
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


    int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, clock_t elapsed) { 
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
            int prices[] = {30, 10, 20, 40, 50};
            int expected_[] = {4, 1};

            clock_t start_           = clock();
            vector <int> received_ = ThePriceIsRight().howManyReveals(vector <int>(prices, prices + (sizeof prices / sizeof prices[0])));
            return verify_case(casenum, vector <int>(expected_, expected_ + (sizeof expected_ / sizeof expected_[0])), received_, clock()-start_);
        }
        case 1: {
            int prices[] = {39, 88, 67, 5, 69, 87, 82, 64, 58, 61};
            int expected_[] = {4, 2};

            clock_t start_           = clock();
            vector <int> received_ = ThePriceIsRight().howManyReveals(vector <int>(prices, prices + (sizeof prices / sizeof prices[0])));
            return verify_case(casenum, vector <int>(expected_, expected_ + (sizeof expected_ / sizeof expected_[0])), received_, clock()-start_);
        }
        case 2: {
            int prices[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
            int expected_[] = {10, 1};

            clock_t start_           = clock();
            vector <int> received_ = ThePriceIsRight().howManyReveals(vector <int>(prices, prices + (sizeof prices / sizeof prices[0])));
            return verify_case(casenum, vector <int>(expected_, expected_ + (sizeof expected_ / sizeof expected_[0])), received_, clock()-start_);
        }
        case 3: {
            int prices[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
            int expected_[] = {1, 10};

            clock_t start_           = clock();
            vector <int> received_ = ThePriceIsRight().howManyReveals(vector <int>(prices, prices + (sizeof prices / sizeof prices[0])));
            return verify_case(casenum, vector <int>(expected_, expected_ + (sizeof expected_ / sizeof expected_[0])), received_, clock()-start_);
        }
        case 4: {
            int prices[] = {29, 31, 73, 70, 14, 5, 6, 34, 53, 30, 15, 86};
            int expected_[] = {5, 2};

            clock_t start_           = clock();
            vector <int> received_ = ThePriceIsRight().howManyReveals(vector <int>(prices, prices + (sizeof prices / sizeof prices[0])));
            return verify_case(casenum, vector <int>(expected_, expected_ + (sizeof expected_ / sizeof expected_[0])), received_, clock()-start_);
        }
        case 5: {
            int prices[] = {100, 99, 1, 2, 3};
            int expected_[] = {3, 1};

            clock_t start_           = clock();
            vector <int> received_ = ThePriceIsRight().howManyReveals(vector <int>(prices, prices + (sizeof prices / sizeof prices[0])));
            return verify_case(casenum, vector <int>(expected_, expected_ + (sizeof expected_ / sizeof expected_[0])), received_, clock()-start_);
        }
        case 6: {
            int prices[] = {10, 20, 11, 12};
            int expected_[] = {3, 1};

            clock_t start_           = clock();
            vector <int> received_ = ThePriceIsRight().howManyReveals(vector <int>(prices, prices + (sizeof prices / sizeof prices[0])));
            return verify_case(casenum, vector <int>(expected_, expected_ + (sizeof expected_ / sizeof expected_[0])), received_, clock()-start_);
        }
        default:
            return -1;
        }
    }

    //This method will only accept input files that are formatted in proper way.
    //Command line example: ThePriceIsRight.exe -2 <ThePriceIsRightIO.txt
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        vector <int> prices;
        int prices_sin;
        vector <int> expected_;
        int expected__sin;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            prices.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::cin>>prices_sin; std::cin.ignore(10, '\n');
                prices.push_back(prices_sin);
            }
            expected_.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::cin>>expected__sin; std::cin.ignore(10, '\n');
                expected_.push_back(expected__sin);
            }
            clock_t start_           = clock();
            vector <int> received_ = ThePriceIsRight().howManyReveals(prices);
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
