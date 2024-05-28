#include "vector"
#include "set"
#include "algorithm"
#include "ctime"
#include "queue"
#include "iomanip"
#include "list"
#include "cassert"
#include "stack"
#include "cstdlib"
#include "map"
#include "string"
#include "cstring"
#include "bitset"
#include "numeric"
#include "cmath"
#include "cstdio"
#include "sstream"
#include "iostream"
#include "cctype"
#include "utility"
#include "functional"
#include "deque"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)

class MoneyRun {
public:
    int collect3(vector<string>&grid) {
        int r=0;
        int memo[8][8];
        Nclr(memo);
        int up, le;

        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[i].length(); j++) {
                memo[i][j]=grid[i][j]-'0';
                up = le = 0;
                if (i>0) {
                    up = memo[i-1][j];
                }
                if (j>0) {
                    le = memo[i][j-1];
                }
//                printf("%d %d\n", up, le);
                if (up>=le) {
                    memo[i][j] += up;
                } else {
                    memo[i][j] += le;
                }
            }
        }

        int i = grid.size()-1;
        int j = grid[0].length()-1;
        r = memo[i][j];
        return r;
    }

    int bForce(vector<string>& grid, int x, int y, int mX, int mY, int v) {
        if (x==mX && y==mY) {
            return collect3(grid)+v;
        }
        int t, b, r;
        b=r=0;
        if (x!=mX) {
            t=grid[x+1][y] - '0';
            grid[x+1][y] = '0';
            b=bForce(grid, x+1, y, mX, mY, v+t);
            grid[x+1][y] = t+'0';
        }

        if (y!= mY) {
            t=grid[x][y+1] - '0';
            grid[x][y+1] = '0';
            r=bForce(grid, x, y+1, mX, mY, v+t);
            grid[x][y+1] = t+'0';
        }

        return max(b,r);
    }
    void showGrid(vector<string>&grid) {
        for(int i=0; i<grid.size();i++) {
            printf("%s\n",grid[i].c_str());
        }
        printf("\n");
    }

    int getMost(vector<string> grid) {
        int out;
        out = bForce(grid, 0, 0, grid.size()-1, grid[0].size()-1, 0);
        //showGrid(grid);
        //out += collect(grid);
        //showGrid(grid);
        return out;
    }

    int collect2(vector<string>&grid) {
        int memo[8][8];
        int up, le, bo;
        for (int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[i].size(); j++) {
                memo[i][j] = grid[i][j]-'0';
                up = le = bo = 0;
                if (i>0) up= memo[i-1][j];
                if (j>0) le= memo[i][j-1];
                if(i>0 && j>0) bo = up + le - memo[i-1][j-1];
                memo[i][j] += max(bo, max(up, le));
                //printf("%d ", memo[i][j]);
            }
            //printf("\n");
        }

        return memo[grid.size()-1][grid[0].size()-1];
    }

    int collect(vector<string>&grid) {
        int r=0;
        int memo[8][8];
        int direciton[8][8];
        Nclr(memo);
        Nclr(direciton);
        int up, le;

        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[i].length(); j++) {
                memo[i][j]=grid[i][j]-'0';
                up = le = 0;
                if (i>0) {
                    up = memo[i-1][j];
                }
                if (j>0) {
                    le = memo[i][j-1];
                }
//                printf("%d %d\n", up, le);
                if (up>=le) {
                    memo[i][j] += up;
                    direciton[i][j] = 1;
                } else {
                    memo[i][j] += le;
                    direciton[i][j] = 0;
                }
            }
        }
        direciton[0][0] = -1;
//        printf("---\n");

        int i = grid.size()-1;
        int j = grid[0].length()-1;
        r = memo[i][j];

        while(1) {
//            printf("%d %d\n", i, j);
            if (i<0 || j<0) break;
            grid[i][j] = '/';

            if (direciton[i][j]==1) {
                i--;
            } else if (direciton[i][j]==0){
                j--;
            } else {
                break;
            }
        }
        
//        printf("--- %d\n", r);
        return r;
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
            string grid[] = {"111", "101", "111"};
            int expected_ = 8;

            clock_t start_           = clock();
            int received_ = MoneyRun().getMost(vector<string>(grid, grid + (sizeof grid / sizeof grid[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            string grid[] = {"99", "09"};
            int expected_ = 27;

            clock_t start_           = clock();
            int received_ = MoneyRun().getMost(vector<string>(grid, grid + (sizeof grid / sizeof grid[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            string grid[] = {"09933", "29333", "03333", "41111"};
            int expected_ = 52;

            clock_t start_           = clock();
            int received_ = MoneyRun().getMost(vector<string>(grid, grid + (sizeof grid / sizeof grid[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            string grid[] = {"11111", "22222"};
            int expected_ = 15;

            clock_t start_           = clock();
            int received_ = MoneyRun().getMost(vector<string>(grid, grid + (sizeof grid / sizeof grid[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 4: {
            string grid[] = {"5560000",
            "5050000",
            "5055550",
            "5565050",
            "0005055",
            "0005555"};
            int expected_ = 112;

            clock_t start_           = clock();
            int received_ = MoneyRun().getMost(vector<string>(grid, grid + (sizeof grid / sizeof grid[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        default:
            return -1;
        }
    }

    //This method will only accept input files that are formatted in proper way.
    //Command line example: MoneyRun.exe -2 <MoneyRunIO.txt
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        vector<string> grid;
        string grid_sin;
        int expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            grid.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::getline(std::cin,grid_sin );
                grid.push_back(grid_sin);
            }
            std::cin>>expected_; std::cin.ignore(10, '\n');
            clock_t start_           = clock();
            int received_ = MoneyRun().getMost(grid);
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
