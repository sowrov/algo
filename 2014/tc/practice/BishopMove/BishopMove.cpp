#include "functional"
#include "vector"
#include "ctime"
#include "cstdio"
#include "queue"
#include "algorithm"
#include "stack"
#include "cassert"
#include "deque"
#include "map"
#include "iomanip"
#include "utility"
#include "iostream"
#include "bitset"
#include "fstream"
#include "cctype"
#include "cstring"
#include "numeric"
#include "set"
#include "list"
#include "sstream"
#include "cmath"
#include "cstdlib"
#include "string"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)
#define Rep(_var, _N) for (int _var=0; _var<_N; _var++ )
#define For(_var, _S,  _N) for (int _var=_S; _var<=_N; _var++ )

class BishopMove {
    int cb[8][8];
public:    
    int howManyMoves(int r1, int c1, int r2, int c2) {
        Zclr(cb);
        int out;
        if (r1==r2 && c1==c2) return 0;
        int v;
        v= move(r1, c1, r2, c2,0,-1, 1, 0, 1, -1);
        if (v!=0) return v;

        v= move(r1, c1, r2, c2,1, 0, 0, 1, 1, 1);
        if (v!=0) return v;

        v= move(r1, c1, r2, c2,0,-1,-1,0, -1, -1);
        if (v!=0) return v;

        v= move(r1, c1, r2, c2,-1, 0, 0, 1, -1, 1);
        if (v!=0) return v;
        
        v=move2(r1, c1, 1, 1);
        if (v!=0) return v;
        v=move2(r1, c1, -1, 1);
        if (v!=0) return v;
        v=move2(r1, c1, -1, -1);
        if (v!=0) return v;
        v=move2(r1, c1, 1, -1);
        if (v!=0) return v;

        return -1;
    }

    int move(int r1, int c1, int r2, int c2, int r11, int c11, int r22, int c22, int i, int j) {

        int rt[3]; int ct[3];
        rt[0]=r2; ct[0]=c2;
        while(rt[0]>-1 && ct[0]>-1 && rt[0]<8 && ct[0]<8) {
            cb[rt[0]][ct[0]]=1;
            rt[1]=rt[0]+r11; ct[1]=ct[0]+c11;
            rt[2]=rt[0]+r22; ct[2]=ct[0]+c22;
            if (rt[0]==r1 && ct[0]==c1) return 1;
            if (rt[1]>-1 && ct[1]>-1 && rt[1]<8 && ct[1]<8 && rt[1]==r1 && ct[1]==c1) return -1;
            if (rt[2]>-1 && ct[2]>-1 && rt[2]<8 && ct[2]<8 && rt[2]==r1 && ct[2]==c1) return -1;
            rt[0]+=i; ct[0]+=j;
        }

        return 0;
    }

    int move2(int r1, int c1, int i, int j) {
        while(r1>-1 && c1>-1 && r1<8 && c1<8) {
            if (cb[r1][c1]==1) {
                return 2;
            }
            r1+=i; c1+=j;
        }

        return 0;

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
            int r1 = 4;
            int c1 = 6;
            int r2 = 7;
            int c2 = 3;
            int expected_ = 1;

            clock_t start_           = clock();
            int received_ = BishopMove().howManyMoves(r1, c1, r2, c2);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            int r1 = 2;
            int c1 = 5;
            int r2 = 2;
            int c2 = 5;
            int expected_ = 0;

            clock_t start_           = clock();
            int received_ = BishopMove().howManyMoves(r1, c1, r2, c2);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            int r1 = 1;
            int c1 = 3;
            int r2 = 5;
            int c2 = 5;
            int expected_ = 2;

            clock_t start_           = clock();
            int received_ = BishopMove().howManyMoves(r1, c1, r2, c2);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            int r1 = 4;
            int c1 = 6;
            int r2 = 7;
            int c2 = 4;
            int expected_ = -1;

            clock_t start_           = clock();
            int received_ = BishopMove().howManyMoves(r1, c1, r2, c2);
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
    //Command line example: BishopMove.exe -2 <BishopMoveIO.txt
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        int r1;
        int c1;
        int r2;
        int c2;
        int expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            std::cin>>r1; std::cin.ignore(10, '\n');
            std::cin>>c1; std::cin.ignore(10, '\n');
            std::cin>>r2; std::cin.ignore(10, '\n');
            std::cin>>c2; std::cin.ignore(10, '\n');
            std::cin>>expected_; std::cin.ignore(10, '\n');
            clock_t start_           = clock();
            int received_ = BishopMove().howManyMoves(r1, c1, r2, c2);
            correct += verify_case(caseNo, expected_, received_, clock()-start_);
        }//end of testCase for loop

        if (testCase == 0) {
            cerr << "No test cases run." << endl;
        } else if (correct < testCase) {
            cerr << "Some cases FAILED (passed " << correct << " of " << testCase << ")." << endl;
        } else {
            cerr << "All " << testCase << " tests passed!" << endl;
            std::ofstream ofs("BishopMove.st", std::ios_base::app);
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
