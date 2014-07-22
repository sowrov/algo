#include "vector"
#include "deque"
#include "set"
#include "ctime"
#include "cstring"
#include "algorithm"
#include "iomanip"
#include "map"
#include "queue"
#include "cassert"
#include "cctype"
#include "iostream"
#include "stack"
#include "cstdio"
#include "bitset"
#include "list"
#include "functional"
#include "cstdlib"
#include "fstream"
#include "cmath"
#include "utility"
#include "string"
#include "numeric"
#include "sstream"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)
#define Rep(_var, _N) for (int _var=0; _var<_N; _var++ )
#define For(_var, _S,  _N) for (int _var=_S; _var<=_N; _var++ )

struct Rect {
    int x, y;
    int area;
};
vector<Rect>rect;

bool comp(Rect a, Rect b) {
    return a.area<b.area;
}
class PilingRectsDiv2 {
public:
    int getmax(vector<int> X, vector<int> Y, int limit) {
        int out;
        rect.clear();
        for (int i=0; i<X.size(); i++) {
            Rect r;
            r.x=X[i];
            r.y=Y[i];
            if (r.x>r.y) {
                r.x^=r.y;
                r.y^=r.x;
                r.x^=r.y;
            }
            r.area = r.x*r.y;
            rect.push_back(r);
        }
        //sort(rect.begin(), rect.end(), comp);
        int maxR=-1, r;
        for (int i=0; i<rect.size(); i++) {
            if (rect[i].area>=limit) {
//                printf("%d %d - %d", rect[i].x, rect[i].y, rect[i].area);
                r=1;
                int minx=rect[i].x;
                int miny=rect[i].y;
                for (int j=0; j<rect.size(); j++) {
                   if (i!=j && min(minx, rect[j].x)*min(miny, rect[j].y)>=limit) {
                       r++;
                       minx = min(minx, rect[j].x);
                       miny = min(miny, rect[j].y);
                   }
                }
                maxR = max(maxR, r);
            }
        }

        return maxR;
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
            int X[] = {1, 2, 3, 1};
            int Y[] = {3, 2, 4, 4};
            int limit = 3;
            int expected_ = 3;

            clock_t start_           = clock();
            int received_ = PilingRectsDiv2().getmax(vector<int>(X, X + (sizeof X / sizeof X[0])), vector<int>(Y, Y + (sizeof Y / sizeof Y[0])), limit);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            int X[] = {4, 7};
            int Y[] = {7, 4};
            int limit = 25;
            int expected_ = 2;

            clock_t start_           = clock();
            int received_ = PilingRectsDiv2().getmax(vector<int>(X, X + (sizeof X / sizeof X[0])), vector<int>(Y, Y + (sizeof Y / sizeof Y[0])), limit);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            int X[] = {10};
            int Y[] = {10};
            int limit = 9999;
            int expected_ = -1;

            clock_t start_           = clock();
            int received_ = PilingRectsDiv2().getmax(vector<int>(X, X + (sizeof X / sizeof X[0])), vector<int>(Y, Y + (sizeof Y / sizeof Y[0])), limit);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            int X[] = {10};
            int Y[] = {3};
            int limit = 30;
            int expected_ = 1;

            clock_t start_           = clock();
            int received_ = PilingRectsDiv2().getmax(vector<int>(X, X + (sizeof X / sizeof X[0])), vector<int>(Y, Y + (sizeof Y / sizeof Y[0])), limit);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 4: {
            int X[] = {3, 6, 5, 8, 2, 9, 14};
            int Y[] = {14, 6, 13, 8, 15, 6, 3};
            int limit = 27;
            int expected_ = 4;

            clock_t start_           = clock();
            int received_ = PilingRectsDiv2().getmax(vector<int>(X, X + (sizeof X / sizeof X[0])), vector<int>(Y, Y + (sizeof Y / sizeof Y[0])), limit);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 5: {
            int X[] = {121, 168, 86, 106, 36, 10, 125, 97, 53, 26, 148, 129, 41, 18, 173, 55, 13, 73, 91, 174, 177, 190, 28, 164, 122, 92, 5, 26, 58, 188, 14, 67, 48, 196, 41, 94, 24, 89, 54, 117, 12, 6, 155, 103, 200, 128, 184, 29, 92, 149};
            int Y[] = {199, 182, 43, 191, 2, 145, 15, 53, 38, 37, 61, 45, 157, 129, 119, 123, 177, 178, 183, 188, 132, 108, 112, 137, 92, 59, 75, 196, 102, 152, 114, 121, 181, 93, 32, 3, 24, 116, 4, 163, 96, 159, 196, 43, 59, 150, 79, 113, 20, 146};
            int limit = 5345;
            int expected_ = 24;

            clock_t start_           = clock();
            int received_ = PilingRectsDiv2().getmax(vector<int>(X, X + (sizeof X / sizeof X[0])), vector<int>(Y, Y + (sizeof Y / sizeof Y[0])), limit);
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
    //Command line example: PilingRectsDiv2.exe -2 <PilingRectsDiv2.io
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        vector<int> X;
        int X_sin;
        vector<int> Y;
        int Y_sin;
        int limit;
        int expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            X.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::cin>>X_sin; std::cin.ignore(10, '\n');
                X.push_back(X_sin);
            }
            Y.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::cin>>Y_sin; std::cin.ignore(10, '\n');
                Y.push_back(Y_sin);
            }
            std::cin>>limit; std::cin.ignore(10, '\n');
            std::cin>>expected_; std::cin.ignore(10, '\n');
            clock_t start_           = clock();
            int received_ = PilingRectsDiv2().getmax(X, Y, limit);
            correct += verify_case(caseNo, expected_, received_, clock()-start_);
        }//end of testCase for loop

        if (testCase == 0) {
            cerr << "No test cases run." << endl;
        } else if (correct < testCase) {
            cerr << "Some cases FAILED (passed " << correct << " of " << testCase << ")." << endl;
        } else {
            cerr << "All " << testCase << " tests passed!" << endl;
            std::ofstream ofs("PilingRectsDiv2.st", std::ios_base::app);
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
