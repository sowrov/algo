#include "ctime"
#include "deque"
#include "algorithm"
#include "string"
#include "set"
#include "map"
#include "numeric"
#include "cstring"
#include "cstdio"
#include "vector"
#include "cassert"
#include "iostream"
#include "fstream"
#include "queue"
#include "functional"
#include "list"
#include "bitset"
#include "cctype"
#include "stack"
#include "iomanip"
#include "sstream"
#include "utility"
#include "cmath"
#include "cstdlib"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)
#define Rep(_var, _N) for (int _var=0; _var<_N; _var++ )
#define For(_var, _S,  _N) for (int _var=_S; _var<=_N; _var++ )
// trim from start
static inline std::string &ltrim(std::string &s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
        return s;
}

// trim from end
static inline std::string &rtrim(std::string &s) {
        s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
        return s;
}

// trim from both ends
static inline std::string &trim(std::string &s) {
        return ltrim(rtrim(s));
}

struct Frute {
    int x, y;
};

bool comp(Frute a, Frute b) {
    if (a.y<b.y) {
        return true;
    } else if (a.y==b.y) {
        return a.x<b.x;
    }
    return false;
}
class CatchTheBeatEasy {
    vector<Frute> frute;
public:
    string ableToCatchAll(vector<int> x, vector<int> y) {
        string out="Able to catch";
        for (int i=0; i<x.size(); i++) {
            Frute f;
            f.x=x[i];
            f.y=y[i];
            frute.push_back(f);
        }
        sort(frute.begin(), frute.end(), comp);
        Frute pl;
        pl.x=pl.y=0;
        int t=0;
        for (int i=0; i<frute.size(); i++) {
            if (i>0 && frute[i].x==frute[i-1].x && frute[i].y==frute[i-1].y) continue;

            int mt = abs(pl.x - frute[i].x);
            //cout<<"px "<<pl.x<<" fx "<<frute[i].x<<" Mt "<<mt<<endl;
            if (mt>(frute[i].y-t)) {
                return "Not able to catch";
            } else {
                pl.x=frute[i].x;
            }
            t+=frute[i].y-t;
        }
        return out;
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

    int verify_case(int casenum, string &expected, const string &received, clock_t elapsed) { 
        cerr << "Example " << casenum << "... "; 

        string verdict;
        vector<string> info;
        char buf[100];

        if (elapsed > CLOCKS_PER_SEC / 200) {
            sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
            info.push_back(buf);
        }
        expected = trim(expected);
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
            cerr << "    Expected: \"" << expected << "\"" << endl;
            cerr << "    Received: \"" << received << "\"" << endl;
        }

        return verdict == "PASSED";
    }

    int run_test_case(int casenum) {
        switch (casenum) {
        case 0: {
            int x[] = {-1, 1, 0};
            int y[] = {1, 3, 4};
            string expected_ = "Able to catch";

            clock_t start_           = clock();
            string received_ = CatchTheBeatEasy().ableToCatchAll(vector<int>(x, x + (sizeof x / sizeof x[0])), vector<int>(y, y + (sizeof y / sizeof y[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            int x[] = {-3};
            int y[] = {2};
            string expected_ = "Not able to catch";

            clock_t start_           = clock();
            string received_ = CatchTheBeatEasy().ableToCatchAll(vector<int>(x, x + (sizeof x / sizeof x[0])), vector<int>(y, y + (sizeof y / sizeof y[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            int x[] = {-1, 1, 0};
            int y[] = {1, 2, 4};
            string expected_ = "Not able to catch";

            clock_t start_           = clock();
            string received_ = CatchTheBeatEasy().ableToCatchAll(vector<int>(x, x + (sizeof x / sizeof x[0])), vector<int>(y, y + (sizeof y / sizeof y[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            int x[] = {0, -1, 1};
            int y[] = {9, 1, 3};
            string expected_ = "Able to catch";

            clock_t start_           = clock();
            string received_ = CatchTheBeatEasy().ableToCatchAll(vector<int>(x, x + (sizeof x / sizeof x[0])), vector<int>(y, y + (sizeof y / sizeof y[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 4: {
            int x[] = {70, -108, 52, -70, 84, -29, 66, -33};
            int y[] = {141, 299, 402, 280, 28, 363, 427, 232};
            string expected_ = "Not able to catch";

            clock_t start_           = clock();
            string received_ = CatchTheBeatEasy().ableToCatchAll(vector<int>(x, x + (sizeof x / sizeof x[0])), vector<int>(y, y + (sizeof y / sizeof y[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 5: {
            int x[] = {-175, -28, -207, -29, -43, -183, -175, -112, -183, -31, -25, -66, -114, -116, -66};
            int y[] = {320, 107, 379, 72, 126, 445, 318, 255, 445, 62, 52, 184, 247, 245, 185};
            string expected_ = "Able to catch";

            clock_t start_           = clock();
            string received_ = CatchTheBeatEasy().ableToCatchAll(vector<int>(x, x + (sizeof x / sizeof x[0])), vector<int>(y, y + (sizeof y / sizeof y[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 6: {
            int x[] = {0, 0, 0, 0};
            int y[] = {0, 0, 0, 0};
            string expected_ = "Able to catch";

            clock_t start_           = clock();
            string received_ = CatchTheBeatEasy().ableToCatchAll(vector<int>(x, x + (sizeof x / sizeof x[0])), vector<int>(y, y + (sizeof y / sizeof y[0])));
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
    //Command line example: CatchTheBeatEasy.exe -2 <CatchTheBeatEasy.io
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        vector<int> x;
        int x_sin;
        vector<int> y;
        int y_sin;
        string expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            x.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::cin>>x_sin; std::cin.ignore(10, '\n');
                x.push_back(x_sin);
            }
            y.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::cin>>y_sin; std::cin.ignore(10, '\n');
                y.push_back(y_sin);
            }
            std::getline(std::cin,expected_);
            clock_t start_           = clock();
            string received_ = CatchTheBeatEasy().ableToCatchAll(x, y);
            correct += verify_case(caseNo, expected_, received_, clock()-start_);
        }//end of testCase for loop

        if (testCase == 0) {
            cerr << "No test cases run." << endl;
        } else if (correct < testCase) {
            cerr << "Some cases FAILED (passed " << correct << " of " << testCase << ")." << endl;
        } else {
            cerr << "All " << testCase << " tests passed!" << endl;
            std::ofstream ofs("CatchTheBeatEasy.st", std::ios_base::app);
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
