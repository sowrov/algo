#include "cassert"
#include "iomanip"
#include "numeric"
#include "utility"
#include "queue"
#include "map"
#include "cstdio"
#include "iostream"
#include "deque"
#include "string"
#include "list"
#include "set"
#include "sstream"
#include "algorithm"
#include "cstring"
#include "bitset"
#include "vector"
#include "functional"
#include "cstdlib"
#include "stack"
#include "ctime"
#include "cmath"
#include "cctype"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)

class XorBoardDivTwo {
public:
    int theMax(vector<string> board) {
        int out;
        int minR=0, zr=0, maxZ=0;

        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[i].size(); j++) {
                board[i][j] += board[i][j]=='0'?1:-1;
            }
            
            for (int k=0; k<board[0].size(); k++) {
                for (int j=0; j<board.size(); j++) {
                    board[j][k] += board[j][k]=='0'?1:-1;
                }
                out=0;
                for (int p=0; p<board.size(); p++) {            
                    for (int q=0; q<board[p].size(); q++) {
                        if(board[p][q]=='1') out++;
                    }
                }

                maxZ = max(maxZ, out);

                for (int j=0; j<board.size(); j++) {
                    board[j][k] += board[j][k]=='0'?1:-1;
                }


            }
            for (int j=0; j<board[i].size(); j++) {
                board[i][j] += board[i][j]=='0'?1:-1;
            }

        }

        return maxZ;
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
            string board[] = {"101", "010", "101"};
            int expected_ = 9;

            clock_t start_           = clock();
            int received_ = XorBoardDivTwo().theMax(vector<string>(board, board + (sizeof board / sizeof board[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            string board[] = {"111", "111", "111"};
            int expected_ = 5;

            clock_t start_           = clock();
            int received_ = XorBoardDivTwo().theMax(vector<string>(board, board + (sizeof board / sizeof board[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            string board[] = {"0101001", "1101011"};
            int expected_ = 9;

            clock_t start_           = clock();
            int received_ = XorBoardDivTwo().theMax(vector<string>(board, board + (sizeof board / sizeof board[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            string board[] = {"000", "001", "010", "011", "100", "101", "110", "111"};
            int expected_ = 15;

            clock_t start_           = clock();
            int received_ = XorBoardDivTwo().theMax(vector<string>(board, board + (sizeof board / sizeof board[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 4: {
            string board[] = {"000000000000000000000000", "011111100111111001111110", "010000000100000001000000", "010000000100000001000000", "010000000100000001000000", "011111100111111001111110", "000000100000001000000010", "000000100000001000000010", "000000100000001000000010", "011111100111111001111110", "000000000000000000000000"};
            int expected_ = 105;

            clock_t start_           = clock();
            int received_ = XorBoardDivTwo().theMax(vector<string>(board, board + (sizeof board / sizeof board[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        default:
            return -1;
        }
    }

    //This method will only accept input files that are formatted in proper way.
    //Command line example: XorBoardDivTwo.exe -2 <XorBoardDivTwo.io
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        vector<string> board;
        string board_sin;
        int expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            board.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::getline(std::cin,board_sin );
                board.push_back(board_sin);
            }
            std::cin>>expected_; std::cin.ignore(10, '\n');
            clock_t start_           = clock();
            int received_ = XorBoardDivTwo().theMax(board);
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
