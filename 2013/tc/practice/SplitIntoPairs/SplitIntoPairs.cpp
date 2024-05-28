#include "numeric"
#include "queue"
#include "algorithm"
#include "deque"
#include "cstdio"
#include "cstdlib"
#include "ctime"
#include "bitset"
#include "list"
#include "sstream"
#include "set"
#include "vector"
#include "cstring"
#include "cassert"
#include "iomanip"
#include "functional"
#include "map"
#include "cctype"
#include "utility"
#include "string"
#include "cmath"
#include "iostream"
#include "fstream"
#include "stack"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)
#define Rep(_var, _N) for (int _var=0; _var<_N; _var++ )
#define For(_var, _S,  _N) for (int _var=_S; _var<=_N; _var++ )

struct Pair {
    int a, b;
};
vector<Pair> grop;
vector <int> A;
bool visit[51];
class SplitIntoPairs {
public:
    int makepairs(vector<int> a, int X) {
        Zclr(visit);
        int n=a.size()/2, c=0, ii, jj;
        long long v, dif, minV;
        int out=0;
        sort(a.begin(), a.end());
    
        for (int i=0; i<a.size(); i+=2) {
            v = a[i];
            v *= a[i+1];
            if (v>=X) {
                out++;
            }
        }
        return out;
    } 

   // void search(int p, int c, int x) {
   //     if (p==A.size()/2) {
   //         if (c<minV) {
   //             minV=c;
   //         }
   //         return;
   //     }
   //     long long v;
   //     for (int i=0; i<A.size(); i++) {
   //         if (visit[i])continue;
   //         visit[i]=1;
   //         for (int j=0; j<A.size(); j++) {
   //             if (visit[j])continue;
   //             if (i>j) {
   //                 v = A[i];
   //                 v *= A[j];
   //                 int cc=c;
   //                 if (v<x) {
   //                     cc++;
   //                 }
   //                 if (cc>=minV) {
   //                     continue;
   //                 }
   //                 visit[j]=1;
   //                 grop[p].a=A[i];
   //                 grop[p].b=A[j];
   //                 search(p+1, cc, x);
   //                 visit[j]=0;
   //             }
   //         }
   //         visit[i]=0;
   //     }
   // }

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
            int A[] = {2, -1};
            int X = -1;
            int expected_ = 0;

            clock_t start_           = clock();
            int received_ = SplitIntoPairs().makepairs(vector<int>(A, A + (sizeof A / sizeof A[0])), X);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            int A[] = {1, -1};
            int X = -1;
            int expected_ = 1;

            clock_t start_           = clock();
            int received_ = SplitIntoPairs().makepairs(vector<int>(A, A + (sizeof A / sizeof A[0])), X);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            int A[] = {-5, -4, 2, 3};
            int X = -1;
            int expected_ = 2;

            clock_t start_           = clock();
            int received_ = SplitIntoPairs().makepairs(vector<int>(A, A + (sizeof A / sizeof A[0])), X);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            int A[] = {5, -7, 8, -2, -5, 3};
            int X = -7;
            int expected_ = 3;

            clock_t start_           = clock();
            int received_ = SplitIntoPairs().makepairs(vector<int>(A, A + (sizeof A / sizeof A[0])), X);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 4: {
            int A[] = {3, 4, 5, 6, 6, -6, -4, -10, -1, -9};
            int X = -2;
            int expected_ = 4;

            clock_t start_           = clock();
            int received_ = SplitIntoPairs().makepairs(vector<int>(A, A + (sizeof A / sizeof A[0])), X);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 5: {
            int A[] = {1000000, 1000000};
            int X = -5;
            int expected_ = 1;

            clock_t start_           = clock();
            int received_ = SplitIntoPairs().makepairs(vector<int>(A, A + (sizeof A / sizeof A[0])), X);
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
    //Command line example: SplitIntoPairs.exe -2 <SplitIntoPairsIO.txt
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        vector<int> A;
        int A_sin;
        int X;
        int expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            A.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::cin>>A_sin; std::cin.ignore(10, '\n');
                A.push_back(A_sin);
            }
            std::cin>>X; std::cin.ignore(10, '\n');
            std::cin>>expected_; std::cin.ignore(10, '\n');
            clock_t start_           = clock();
            int received_ = SplitIntoPairs().makepairs(A, X);
            correct += verify_case(caseNo, expected_, received_, clock()-start_);
        }//end of testCase for loop

        if (testCase == 0) {
            cerr << "No test cases run." << endl;
        } else if (correct < testCase) {
            cerr << "Some cases FAILED (passed " << correct << " of " << testCase << ")." << endl;
        } else {
            cerr << "All " << testCase << " tests passed!" << endl;
            std::ofstream ofs("SplitIntoPairs.st", std::ios_base::app);
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
