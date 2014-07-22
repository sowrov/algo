#include "cstdio"
#include "deque"
#include "iostream"
#include "utility"
#include "ctime"
#include "bitset"
#include "set"
#include "fstream"
#include "map"
#include "iomanip"
#include "list"
#include "functional"
#include "string"
#include "cmath"
#include "sstream"
#include "numeric"
#include "algorithm"
#include "stack"
#include "vector"
#include "cstring"
#include "cstdlib"
#include "queue"
#include "cctype"
#include "cassert"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)
#define Rep(_var, _N) for (int _var=0; _var<_N; _var++ )
#define For(_var, _S,  _N) for (int _var=_S; _var<=_N; _var++ )
static int inf = 100000;

bool mat[9][9], tmat[9][9];
int dp[9][9];
int rCount, cCount;
class PalindromeMatrixDiv2 {
public:
    int minChange(vector<string> A, int rowCount, int columnCount) {
        int out;
        int n=A.size();
        int m=A[0].size();
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                mat[i][j] = A[i][j]-'0';
                dp[i][j] = -1;
            }
        }
        rCount=rowCount;
        cCount = columnCount;
        if (palCount(n,m)) return 0;
        out = change(0, 0, n, m);
        return out;
    }

    int change(int r, int c, int n, int m) {
        
        //int &res = dp[r][c];
        //if (res>-1) return res;

        int hn=n>>1; int hm=m>>1;
        if (r>=hn || c>=hm) {
            //res = inf;
            return inf;
        }

        int ind[] = {n-r-1, c, r, m-c-1, n-r-1, m-c-1};
        vector<int> cind;
        int minV=inf;
        //copy(0, n, m);
        for (int x=0; x<2; x++) {
            cind.clear();
            int ch=0;
            for (int i=0; i<6; i+=2) {
                if (mat[r][c] != mat[ind[i]][ind[i+1]]) {
                    mat[ind[i]][ind[i+1]] = !mat[ind[i]][ind[i+1]];
                    ch++;
                    if (palCount(n,m)) {
                        minV = min(minV, x+ch);
                    }
                    minV = min (minV, x+ch+change(r, c+1, n, m));
                    minV = min (minV, x+ch+change(r+1, c, n, m));
                    cind.push_back(ind[i]);
                    cind.push_back(ind[i+1]);
                }
            }

            for (int i=0; i<cind.size(); i+=2) {
                mat[cind[i]][cind[i+1]] = !mat[cind[i]][cind[i+1]];
            }
            //copy(1, n, m);
            mat[r][c] = !mat[r][c];
            if (palCount(n,m)) minV=1;
        }
        mat[r][c] = !mat[r][c];

        //res = minV;

        return minV;
    }

    void copy(int a, int n, int m) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (a)
                    mat[i][j]=tmat[i][j];
                else 
                    tmat[i][j]=mat[i][j];
            }
        }
    }

    bool palCount(int n, int m) {
        int rc=0, cc=0;
        for (int i=0; i<n; i++) {
            bool pal=true;
            for (int j=0; j<m>>1; j++) {
                if (mat[i][j]!=mat[i][m-j-1]) {
                    pal=false;
                    break;
                }
            }
            rc += pal;
        }

        for (int i=0; i<m; i++) {
            bool pal=true;
            for (int j=0; j<n>>1; j++) {
                if (mat[j][i] != mat[n-j-1][i]) {
                    pal=false;
                    break;
                }
            }
            cc += pal;
        }
        return rCount<=rc && cCount<=cc;
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
            string A[] = {"0000", "1000", "1100", "1110"};
            int rowCount = 2;
            int columnCount = 2;
            int expected_ = 1;

            clock_t start_           = clock();
            int received_ = PalindromeMatrixDiv2().minChange(vector<string>(A, A + (sizeof A / sizeof A[0])), rowCount, columnCount);
            return verify_case(casenum, expected_, received_, clock()-start_);
                }
        case 1: {
            string A[] = {"0000", "1000", "1100", "1110"};
            int rowCount = 3;
            int columnCount = 2;
            int expected_ = 3;

            clock_t start_           = clock();
            int received_ = PalindromeMatrixDiv2().minChange(vector<string>(A, A + (sizeof A / sizeof A[0])), rowCount, columnCount);
            return verify_case(casenum, expected_, received_, clock()-start_);
                }
        case 2: {
            string A[] = {"01", "10"};
            int rowCount = 2;
            int columnCount = 2;
            int expected_ = 2;

            clock_t start_           = clock();
            int received_ = PalindromeMatrixDiv2().minChange(vector<string>(A, A + (sizeof A / sizeof A[0])), rowCount, columnCount);
            return verify_case(casenum, expected_, received_, clock()-start_);
                }
        case 3: {
            string A[] = {"1110", "0001"};
            int rowCount = 0;
            int columnCount = 0;
            int expected_ = 0;

            clock_t start_           = clock();
            int received_ = PalindromeMatrixDiv2().minChange(vector<string>(A, A + (sizeof A / sizeof A[0])), rowCount, columnCount);
            return verify_case(casenum, expected_, received_, clock()-start_);
                }
        case 4: {
            string A[] = {"01010101", "01010101", "01010101", "01010101", "01010101", "01010101", "01010101", "01010101"};
            int rowCount = 2;
            int columnCount = 2;
            int expected_ = 8;

            clock_t start_           = clock();
            int received_ = PalindromeMatrixDiv2().minChange(vector<string>(A, A + (sizeof A / sizeof A[0])), rowCount, columnCount);
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
    //Command line example: PalindromeMatrixDiv2.exe -2 <PalindromeMatrixDiv2.io
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        vector<string> A;
        string A_sin;
        int rowCount;
        int columnCount;
        int expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            A.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::getline(std::cin,A_sin );
                A.push_back(A_sin);
            }
            std::cin>>rowCount; std::cin.ignore(10, '\n');
            std::cin>>columnCount; std::cin.ignore(10, '\n');
            std::cin>>expected_; std::cin.ignore(10, '\n');
            clock_t start_           = clock();
            int received_ = PalindromeMatrixDiv2().minChange(A, rowCount, columnCount);
            correct += verify_case(caseNo, expected_, received_, clock()-start_);
        }//end of testCase for loop

        if (testCase == 0) {
            cerr << "No test cases run." << endl;
        } else if (correct < testCase) {
            cerr << "Some cases FAILED (passed " << correct << " of " << testCase << ")." << endl;
        } else {
            cerr << "All " << testCase << " tests passed!" << endl;
            std::ofstream ofs("PalindromeMatrixDiv2.st", std::ios_base::app);
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
