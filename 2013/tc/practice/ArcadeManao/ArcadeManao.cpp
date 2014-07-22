#include "cctype"
#include "stack"
#include "numeric"
#include "vector"
#include "cstdio"
#include "set"
#include "iostream"
#include "bitset"
#include "sstream"
#include "utility"
#include "string"
#include "functional"
#include "map"
#include "deque"
#include "queue"
#include "ctime"
#include "cstring"
#include "cmath"
#include "cstdlib"
#include "list"
#include "algorithm"
#include "iomanip"
#include "cassert"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)

class ArcadeManao {
public:
    vector<string> lvl;
    int dr, dc;
    bool visit[51][51];
    int shortestLadder(vector<string> level, int coinRow, int coinColumn) {
        int out;
        if (coinRow == level.size()) {
            return 0;
        }

        lvl = level;

        dr = coinRow - 1;
        dc = coinColumn - 1;

        for (int ls=1; ls<level.size(); ls++) {            
            memset(visit, 0, sizeof(visit));
            visit[lvl.size()-1][0] = 1;
            if (isReachable(ls, lvl.size()-1, 0)) {
                return ls;
            }
        }
        return out;
    }

    bool isReachable(int ls, int r, int c) {
        if (r==dr && c==dc) {
            return true;
        }
        int nr, nc;
        for (int i=1; i<=ls; i++) {
            nr = r+i;
            if (nr < lvl.size() && lvl[nr][c]=='X' && !visit[nr][c]) {
                visit[nr][c] = true;
                if (isReachable(ls, nr, c)) {
                    return true;
                }
                //visit[nr][c] = false;
            }

            nr = r-i;
            if (nr >=0 && lvl[nr][c]=='X' && !visit[nr][c]) {
                visit[nr][c] = true;
                if (isReachable(ls, nr, c)) {
                    return true;
                }
                //visit[nr][c] = false;
            }
        }

        nc = c+1;
        if (nc < lvl[0].size() && lvl[r][nc]=='X' && !visit[r][nc]) {
            visit[r][nc] = true;
            if (isReachable(ls, r, nc)) {
                return true;
            }
            //visit[r][nc] = false;
        }

        nc = c-1;
        if (nc >=0 && lvl[r][nc]=='X' && !visit[r][nc]) {
            visit[r][nc] = true;
            if (isReachable(ls, r, nc)) {
                return true;
            }
            //visit[r][nc] = false;
        }

        return false;
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
            string level[] = {"XXXX....", "...X.XXX", "XXX..X..", "......X.", "XXXXXXXX"};
            int coinRow = 2;
            int coinColumn = 4;
            int expected_ = 2;

            clock_t start_           = clock();
            int received_ = ArcadeManao().shortestLadder(vector<string>(level, level + (sizeof level / sizeof level[0])), coinRow, coinColumn);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            string level[] = {"XXXX", "...X", "XXXX"};
            int coinRow = 1;
            int coinColumn = 1;
            int expected_ = 1;

            clock_t start_           = clock();
            int received_ = ArcadeManao().shortestLadder(vector<string>(level, level + (sizeof level / sizeof level[0])), coinRow, coinColumn);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            string level[] = {"..X..", ".X.X.", "X...X", ".X.X.", "..X..", "XXXXX"};
            int coinRow = 1;
            int coinColumn = 3;
            int expected_ = 4;

            clock_t start_           = clock();
            int received_ = ArcadeManao().shortestLadder(vector<string>(level, level + (sizeof level / sizeof level[0])), coinRow, coinColumn);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            string level[] = {"X"};
            int coinRow = 1;
            int coinColumn = 1;
            int expected_ = 0;

            clock_t start_           = clock();
            int received_ = ArcadeManao().shortestLadder(vector<string>(level, level + (sizeof level / sizeof level[0])), coinRow, coinColumn);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 4: {
            string level[] = {"XXXXXXXXXX", "...X......", "XXX.......", "X.....XXXX", "..XXXXX..X", ".........X", ".........X", "XXXXXXXXXX"};
            int coinRow = 1;
            int coinColumn = 1;
            int expected_ = 2;

            clock_t start_           = clock();
            int received_ = ArcadeManao().shortestLadder(vector<string>(level, level + (sizeof level / sizeof level[0])), coinRow, coinColumn);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        default:
            return -1;
        }
    }

    //This method will only accept input files that are formatted in proper way.
    //Command line example: ArcadeManao.exe -2 <ArcadeManao.io
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        vector<string> level;
        string level_sin;
        int coinRow;
        int coinColumn;
        int expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            level.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::getline(std::cin,level_sin );
                level.push_back(level_sin);
            }
            std::cin>>coinRow; std::cin.ignore(10, '\n');
            std::cin>>coinColumn; std::cin.ignore(10, '\n');
            std::cin>>expected_; std::cin.ignore(10, '\n');
            clock_t start_           = clock();
            int received_ = ArcadeManao().shortestLadder(level, coinRow, coinColumn);
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
