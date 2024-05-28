#include "bitset"
#include "iomanip"
#include "utility"
#include "cstring"
#include "algorithm"
#include "sstream"
#include "cctype"
#include "deque"
#include "cassert"
#include "cstdlib"
#include "map"
#include "list"
#include "fstream"
#include "queue"
#include "string"
#include "cstdio"
#include "numeric"
#include "set"
#include "iostream"
#include "vector"
#include "cmath"
#include "ctime"
#include "functional"
#include "stack"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)
#define Rep(_var, _N) for (int _var=0; _var<_N; _var++ )
#define For(_var, _S,  _N) for (int _var=_S; _var<=_N; _var++ )

int arr[]={-1, 0, 0, -1, 1, 0, 0, 1};
class FoxAndGo {
public:
    int maxKill(vector<string> board) {
        int out=0, count=0;
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[i].size(); j++) {
                if (board[i][j]=='o') {
                    count++;
                }
            }
        }
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[i].size(); j++) {
                if (board[i][j]=='.') {
                    board[i][j]='x';
                    int notK=findNotKill(board);
                    if (count-notK>out) {
                        out=count-notK;
                        //printf("%d %d - %d\n",i, j, notK);
                    }
                    board[i][j]='.';
                }
            }
        }
        return out;
    }
    int findNotKill(vector<string>board) {
        int c=0;
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[i].size(); j++) {
                if (board[i][j]=='o') {
                    int v=0;
                    for (int k=0; k<8; k+=2) {
                        if (i+arr[k]>-1 && i+arr[k]<board.size() &&
                            j+arr[k+1]>-1 && j+arr[k+1]<board[i].size() &&
                            board[i+arr[k]][j+arr[k+1]]=='.'
                        ) {
                            v = findAdj(board, i, j);
                            break;
                        }
                    }
                    c+=v;
                }
            }
        }
        return c;
    }
    int findAdj(vector<string>& board, int i, int j) {
        board[i][j]='-';
        int c=0;
        for (int k=0; k<8; k+=2) {
            if (i+arr[k]>-1 && i+arr[k]<board.size() &&
                j+arr[k+1]>-1 && j+arr[k+1]<board[i].size() &&
                board[i+arr[k]][j+arr[k+1]]=='o'
            ) {
                c += findAdj(board, i+arr[k], j+arr[k+1]);
            }
        }
        return c+1;
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
            string board[] = {".....", "..x..", ".xox.", ".....", "....."};
            int expected_ = 1;

            clock_t start_           = clock();
            int received_ = FoxAndGo().maxKill(vector<string>(board, board + (sizeof board / sizeof board[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            string board[] = {"ooooo", "xxxxo", "xxxx.", "xxxx.", "ooooo"};
            int expected_ = 6;

            clock_t start_           = clock();
            int received_ = FoxAndGo().maxKill(vector<string>(board, board + (sizeof board / sizeof board[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            string board[] = {".xoxo", "ooxox", "oooxx", "xoxox", "oxoox"};
            int expected_ = 13;

            clock_t start_           = clock();
            int received_ = FoxAndGo().maxKill(vector<string>(board, board + (sizeof board / sizeof board[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            string board[] = {".......", ".......", ".......", "xxxx...", "ooox...", "ooox...", "ooox..."};
            int expected_ = 9;

            clock_t start_           = clock();
            int received_ = FoxAndGo().maxKill(vector<string>(board, board + (sizeof board / sizeof board[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 4: {
            string board[] = {".......", ".xxxxx.", ".xooox.", ".xo.ox.", ".xooox.", ".xxxxx.", "......."};
            int expected_ = 8;

            clock_t start_           = clock();
            int received_ = FoxAndGo().maxKill(vector<string>(board, board + (sizeof board / sizeof board[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 5: {
            string board[] = {"o.xox.o", "..xox..", "xxxoxxx", "ooo.ooo", "xxxoxxx", "..xox..", "o.xox.o"};
            int expected_ = 12;

            clock_t start_           = clock();
            int received_ = FoxAndGo().maxKill(vector<string>(board, board + (sizeof board / sizeof board[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 6: {
            string board[] = {".......", "..xx...", ".xooox.", ".oxxox.", ".oxxxo.", "...oo..", "......."};
            int expected_ = 4;

            clock_t start_           = clock();
            int received_ = FoxAndGo().maxKill(vector<string>(board, board + (sizeof board / sizeof board[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 7: {
            string board[] = {".ox....", "xxox...", "..xoox.", "..xoox.", "...xx..", ".......", "......."};
            int expected_ = 5;

            clock_t start_           = clock();
            int received_ = FoxAndGo().maxKill(vector<string>(board, board + (sizeof board / sizeof board[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 8: {
            string board[] = {"...................", "...................", "...o..........o....", "................x..", "...............x...", "...................", "...................", "...................", "...................", "...................", "...................", "...................", "...................", "...................", "................o..", "..x................", "...............x...", "...................", "..................."};
            int expected_ = 0;

            clock_t start_           = clock();
            int received_ = FoxAndGo().maxKill(vector<string>(board, board + (sizeof board / sizeof board[0])));
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
    //Command line example: FoxAndGo.exe -2 <FoxAndGoIO.txt
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
            int received_ = FoxAndGo().maxKill(board);
            correct += verify_case(caseNo, expected_, received_, clock()-start_);
        }//end of testCase for loop

        if (testCase == 0) {
            cerr << "No test cases run." << endl;
        } else if (correct < testCase) {
            cerr << "Some cases FAILED (passed " << correct << " of " << testCase << ")." << endl;
        } else {
            cerr << "All " << testCase << " tests passed!" << endl;
            std::ofstream ofs("FoxAndGo.st", std::ios_base::app);
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
