#include "list"
#include "string"
#include "utility"
#include "vector"
#include "ctime"
#include "deque"
#include "cstdlib"
#include "iostream"
#include "cstring"
#include "cctype"
#include "algorithm"
#include "queue"
#include "fstream"
#include "cassert"
#include "map"
#include "sstream"
#include "cstdio"
#include "iomanip"
#include "stack"
#include "numeric"
#include "cmath"
#include "set"
#include "functional"
#include "bitset"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)
#define Rep(_var, _N) for (int _var=0; _var<_N; _var++ )
#define For(_var, _S,  _N) for (int _var=_S; _var<=_N; _var++ )

map<int, bool>db;

class AstronomicalRecordsEasy {
public:
    int minimalPlanets(vector<int> A, vector<int> B) {
        int out=0;
        db.clear();
        int c1, c2, m1, m2, m=1000, mc1=0, mc2=0;
        bool f1;
        int g1=A[0], g2=B[0];
        for (int i=1; i<A.size(); i++) {
            g1=gcd(A[i], g1);
        }
        printf("%d\n", g1);

        for (int i=0; i<A.size(); i++) {
            A[i] /= g1;
        }

        for (int i=1; i<B.size(); i++) {
            g2=gcd(g2, B[i]);
        }

        for (int i=0; i<B.size(); i++) {
            B[i] /= g2;
        }

        while(m) {
            c1 = matchC(A, B, m);
            c2 = matchC(B, A, m);

            if (c1>=mc1) {
                mc1=c1;
                m1=m;
            }
            if (c2>=mc2) {
                mc2=c2;
                m2=m;
            }
            m--;
        }
        printf("-- %d %d\n",mc1, mc2);
        if (mc1>mc2) {
            m2=1;
        } else {
            m1=1;
        }
        out = unique(A, m1);
        out += unique(B, m2);
        return out;
    }

    int unique(vector<int>&a, int m) {
        int c=0;
        for(int i=0; i<a.size(); i++) {
            int v=a[i]*m;
            if (!db[v]) {
                c++;
            }
            db[v]=1;
        }
        return c;
    }

    int matchC(vector<int>&A, vector<int>&B, int m) {
        int c=0;
        int v;
        for (int i=0; i<A.size(); i++) {
            v=A[i]*m;
            for (int j=0; j<B.size(); j++) {
                if (v==B[j]) {
                    c++; break;
                }
                //                if (v>B[j]) break;
            }
        }

        return c;
    }

    int gcd(int a, int b) {
        if (!b) return a;
        return gcd(b, a%b);
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
            int A[] = {1, 2, 3, 4};
            int B[] = {2, 3, 4, 5};
            int expected_ = 5;

            clock_t start_           = clock();
            int received_ = AstronomicalRecordsEasy().minimalPlanets(vector<int>(A, A + (sizeof A / sizeof A[0])), vector<int>(B, B + (sizeof B / sizeof B[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
                }
        case 1: {
            int A[] = {1, 2, 3, 4};
            int B[] = {2, 4, 6, 8};
            int expected_ = 4;

            clock_t start_           = clock();
            int received_ = AstronomicalRecordsEasy().minimalPlanets(vector<int>(A, A + (sizeof A / sizeof A[0])), vector<int>(B, B + (sizeof B / sizeof B[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
                }
        case 2: {
            int A[] = {1, 2, 3, 5, 6, 8, 9};
            int B[] = {2, 4, 5, 6, 7, 8, 9};
            int expected_ = 9;

            clock_t start_           = clock();
            int received_ = AstronomicalRecordsEasy().minimalPlanets(vector<int>(A, A + (sizeof A / sizeof A[0])), vector<int>(B, B + (sizeof B / sizeof B[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
                }
        case 3: {
            int A[] = {1, 2, 3, 4};
            int B[] = {6, 7, 8, 9};
            int expected_ = 6;

            clock_t start_           = clock();
            int received_ = AstronomicalRecordsEasy().minimalPlanets(vector<int>(A, A + (sizeof A / sizeof A[0])), vector<int>(B, B + (sizeof B / sizeof B[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
                }
        case 4: {
            int A[] = {200, 500};
            int B[] = {100, 200, 300, 400, 600, 700, 800, 900};
            int expected_ = 9;

            clock_t start_           = clock();
            int received_ = AstronomicalRecordsEasy().minimalPlanets(vector<int>(A, A + (sizeof A / sizeof A[0])), vector<int>(B, B + (sizeof B / sizeof B[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
                }
        case 5: {
            int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
            int B[] = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
            int expected_ = 15;

            clock_t start_           = clock();
            int received_ = AstronomicalRecordsEasy().minimalPlanets(vector<int>(A, A + (sizeof A / sizeof A[0])), vector<int>(B, B + (sizeof B / sizeof B[0])));
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
    //Command line example: AstronomicalRecordsEasy.exe -2 <AstronomicalRecordsEasy.io
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        vector<int> A;
        int A_sin;
        vector<int> B;
        int B_sin;
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
            B.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::cin>>B_sin; std::cin.ignore(10, '\n');
                B.push_back(B_sin);
            }
            std::cin>>expected_; std::cin.ignore(10, '\n');
            clock_t start_           = clock();
            int received_ = AstronomicalRecordsEasy().minimalPlanets(A, B);
            correct += verify_case(caseNo, expected_, received_, clock()-start_);
        }//end of testCase for loop

        if (testCase == 0) {
            cerr << "No test cases run." << endl;
        } else if (correct < testCase) {
            cerr << "Some cases FAILED (passed " << correct << " of " << testCase << ")." << endl;
        } else {
            cerr << "All " << testCase << " tests passed!" << endl;
            std::ofstream ofs("AstronomicalRecordsEasy.st", std::ios_base::app);
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
