#include "set"
#include "cmath"
#include "iostream"
#include "ctime"
#include "cstring"
#include "bitset"
#include "utility"
#include "map"
#include "stack"
#include "vector"
#include "iomanip"
#include "sstream"
#include "functional"
#include "cstdlib"
#include "cassert"
#include "string"
#include "list"
#include "cctype"
#include "numeric"
#include "queue"
#include "cstdio"
#include "deque"
#include "algorithm"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)

class Box{
public:
    int h, ind;
};
class BlockTower {
public:
    int getTallest(vector<int> blockHeights) {
        int odd=0, evn=0, maxV;
        vector<Box> od, ev;
        Box b;
        for (int i=0; i<blockHeights.size(); i++) {
            b.h = blockHeights[i];
            b.ind = i;
            if (b.h&1) {
                od.push_back(b);                
            } else {
                ev.push_back(b);
            }
        }

        maxV = 0;

        while(true) {
            evn=0;
            int li=-1;
            for (int i=0; i<ev.size(); i++) {
                evn+=ev[i].h;
                li = ev[i].ind;
            }

            for (int i=0; i<od.size(); i++) {
                if (od[i].ind>li) {
                    evn +=od[i].h;
                }
            }
            if (evn>maxV) maxV = evn;

            if (!ev.empty())
                ev.pop_back();
            else break;
        }
        return maxV;
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
            int blockHeights[] = {4, 7};
            int expected_ = 11;

            clock_t start_           = clock();
            int received_ = BlockTower().getTallest(vector<int>(blockHeights, blockHeights + (sizeof blockHeights / sizeof blockHeights[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            int blockHeights[] = {7, 4};
            int expected_ = 7;

            clock_t start_           = clock();
            int received_ = BlockTower().getTallest(vector<int>(blockHeights, blockHeights + (sizeof blockHeights / sizeof blockHeights[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            int blockHeights[] = {7};
            int expected_ = 7;

            clock_t start_           = clock();
            int received_ = BlockTower().getTallest(vector<int>(blockHeights, blockHeights + (sizeof blockHeights / sizeof blockHeights[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            int blockHeights[] = {4};
            int expected_ = 4;

            clock_t start_           = clock();
            int received_ = BlockTower().getTallest(vector<int>(blockHeights, blockHeights + (sizeof blockHeights / sizeof blockHeights[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 4: {
            int blockHeights[] = {48, 1, 50, 1, 50, 1, 48};
            int expected_ = 196;

            clock_t start_           = clock();
            int received_ = BlockTower().getTallest(vector<int>(blockHeights, blockHeights + (sizeof blockHeights / sizeof blockHeights[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 5: {
            int blockHeights[] = {49, 2, 49, 2, 49};
            int expected_ = 147;

            clock_t start_           = clock();
            int received_ = BlockTower().getTallest(vector<int>(blockHeights, blockHeights + (sizeof blockHeights / sizeof blockHeights[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 6: {
            int blockHeights[] = {44, 3, 44, 3, 44, 47, 2, 47, 2, 47, 2};
            int expected_ = 273;

            clock_t start_           = clock();
            int received_ = BlockTower().getTallest(vector<int>(blockHeights, blockHeights + (sizeof blockHeights / sizeof blockHeights[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        default:
            return -1;
        }
    }

    //This method will only accept input files that are formatted in proper way.
    //Command line example: BlockTower.exe -2 <BlockTower.io
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        vector<int> blockHeights;
        int blockHeights_sin;
        int expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            blockHeights.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::cin>>blockHeights_sin; std::cin.ignore(10, '\n');
                blockHeights.push_back(blockHeights_sin);
            }
            std::cin>>expected_; std::cin.ignore(10, '\n');
            clock_t start_           = clock();
            int received_ = BlockTower().getTallest(blockHeights);
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
