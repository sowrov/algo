#include "ctime"
#include "vector"
#include "numeric"
#include "iomanip"
#include "set"
#include "functional"
#include "bitset"
#include "cctype"
#include "string"
#include "cstdio"
#include "map"
#include "sstream"
#include "utility"
#include "algorithm"
#include "deque"
#include "cstring"
#include "queue"
#include "cmath"
#include "cstdlib"
#include "stack"
#include "list"
#include "iostream"
#include "cassert"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)

struct Point{
    int x, y;
};
 
// 2D cross product of OA and OB vectors, i.e. z-component of their 3D cross product.
// Returns a positive value, if OAB makes a counter-clockwise turn or left turn,
// negative for clockwise or right turn, and zero if the points are collinear.
int corssProduct(const Point &O, const Point &A, const Point &B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
// Distance between two points
int pointDist(Point &a, Point &b){
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}
 
// Leftmost lowest point
Point LowestLeft;
 
// Return true if cross-product between vector LA and LB yells left-turn.
// If Point L, A and B are one same line then it will return true if A is
// closer to L than B
bool compTurn(Point a, Point b){
    int v= corssProduct(LowestLeft, a, b);
    if(v>0) {
        return true;
    }
    else if(v==0){
        return pointDist(LowestLeft, a)<pointDist(LowestLeft, b);
    }
    return false;
}
 
vector <Point> convexHull(vector<Point>& points) {
    vector<Point> theHull;
    if (points.size()<4) {
        return points;
    }
    LowestLeft.x = LowestLeft.y= Ox; //init as infinite
    //1. Find the lowest left point
    for (int i=0; i<points.size(); i++) {
        if (points[i].y < LowestLeft.y ||
            (points[i].y == LowestLeft.y && points[i].x < LowestLeft.x) ) {
                LowestLeft = points[i];
        }
    }
    //2. Sort the points in such way that point A comes before point B if the
    //   vector (LowestLeft, A) and vector (LowestLeft, B) makes a left turn
    sort(points.begin(), points.end(), compTurn);
    theHull.push_back(points[0]);
    theHull.push_back(points[1]);
    for (int i=2; i<points.size(); i++) {
        if (theHull.size()==1) {
            theHull.push_back(points[i]);
            continue;
        }
        if (corssProduct(theHull[theHull.size()-2], theHull.back(), points[i]) > 0) { // counter-clockwise or left turn
            theHull.push_back(points[i]);
        } else {
            theHull.pop_back();
            i--; //want use the same point next time, this will nullify the effect of i++ of the loop
        }
    }
    return theHull;
}

class ElectronicScarecrows {
public:
    double largestArea(vector <int>x, vector <int>y, intn) {
        double out;
        Point p;
        vector <Point> points, theHull;
        for (int i=0; i<x.size(); i++) {
            p.x = x[i];
            p.y = y[i];
            points.push_back(p);
        }

        theHull = convexHull(points);

        return out;
    }
};

// <editor-fold defaultstate="collapsed" desc="Generated Code">
namespace otocoder {
#ifndef isinf
#define isinf(x) (!_finite(x))
#define isnan(x) _isnan(x)
#endif
    static const double epsilon = 1e-9; static bool compareDouble(double expected, double result) { return (fabs(expected - result) <= epsilon * fmax(1.0, fmax(fabs(expected), fabs(result)))); }
    double moj_relative_error(double expected, double result) { if (isnan(expected) || isinf(expected) || isnan(result) || isinf(result) || expected == 0) return 0; return fabs(result-expected) / fabs(expected); }

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

    int verify_case(int casenum, const double &expected, const double &received, clock_t elapsed) { 
        cerr << "Example " << casenum << "... "; 

        string verdict;
        vector<string> info;
        char buf[100];

        if (elapsed > CLOCKS_PER_SEC / 200) {
            sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
            info.push_back(buf);
        }

        if (compareDouble(expected, received)) {
            verdict = "PASSED";
            double rerr = moj_relative_error(expected, received); 
            if (rerr > 0) {
                sprintf(buf, "relative error %.3e", rerr);
                info.push_back(buf);
            }
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
            int x[] = {2, 1, 6, 5, 3, 7, 9};
            int y[] = {2, 5, 1, 5, 7, 6, 4};
            int n = 4;
            double expected_ = 24.0;

            clock_t start_           = clock();
            double received_ = ElectronicScarecrows().largestArea(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), n);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            int x[] = {183, 229, 723, 510, 395, 936, 447, 328};
            int y[] = {1000, 823, 0, 412, 786, 446, 312, 286};
            int n = 15;
            double expected_ = 347200.0;

            clock_t start_           = clock();
            double received_ = ElectronicScarecrows().largestArea(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), n);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            int x[] = {33, 36, 26, 8, 12, 8, 28, 19, 8, 37, 9, 22, 31, 30, 25};
            int y[] = {12, 8, 6, 16, 27, 7, 31, 33, 35, 22, 22, 36, 29, 22, 32};
            int n = 8;
            double expected_ = 740.5;

            clock_t start_           = clock();
            double received_ = ElectronicScarecrows().largestArea(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), n);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            int x[] = {327, 196, 744, 91, 709, 38, 944, 300, 927, 715, 835, 874, 958, 667, 748, 511, 377, 956, 184, 956, 
, 809, 925, 12, 45, 184, 180, 169, 374, 914, 398, 954, 875, 286, 422, 76, 315, 497, 209, 512, 938};
            int y[] = {913, 843, 73, 213, 903, 444, 444, 905, 352, 54, 194, 207, 373, 57, 105, 959, 932, 480, 843, 424, 
, 140, 661, 578, 616, 851, 132, 135, 936, 676, 23, 578, 737, 74, 959, 724, 924, 955, 854, 958, 376};
            int n = 25;
            double expected_ = 685819.5;

            clock_t start_           = clock();
            double received_ = ElectronicScarecrows().largestArea(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), n);
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        default:
            return -1;
        }
    }

    //This method will only accept input files that are formatted in proper way.
    //Command line example: ElectronicScarecrows.exe -2 <ElectronicScarecrows.io
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        vector <int> x;
        int x_sin;
        vector <int> y;
        int y_sin;
        int n;
        double expected_;

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
            std::cin>>n; std::cin.ignore(10, '\n');
            std::cin>>expected_; std::cin.ignore(10, '\n');
            clock_t start_           = clock();
            double received_ = ElectronicScarecrows().largestArea(x, y, n);
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
