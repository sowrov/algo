#pragma warning ( disable : 4786)
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <bitset>
#include <deque>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 2147483647
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)
struct Point {
    int x, y;
};
class EnclosingTriangleColorful {
public:
    int getNumber( int m, vector <int> x, vector <int> y ) {
        vector<Point>red, grn, blu, yel, blk;
        Point p;
        for (int i=1; i<m; i++) {
            p.x=i;
            p.y=0;
            red.push_back(p);
            p.x=m;
            p.y=i;
            grn.push_back(p);
            p.x=i;
            p.y=m;
            blu.push_back(p);
            p.x=0;
            p.y=i;
            yel.push_back(p);
        }
        for (int i=0; i<x.size(); i++) {
            p.x=x[i];
            p.y=y[i];
            blk.push_back(p);
        }
        int out = find(red, grn, blu, blk);
        out += find(grn, blu, yel, blk);
        out += find(blu, yel, red, blk);
        out += find(yel, red, grn, blk);
        return out;
    }
    int sign(Point p1, Point p2, Point p3)
    {
        return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
    }

    bool PointInTriangle(Point pt, Point v1, Point v2, Point v3)
    {
        bool b1, b2, b3;

        b1 = sign(pt, v1, v2) < 0;
        b2 = sign(pt, v2, v3) < 0;
        b3 = sign(pt, v3, v1) < 0;

        return ((b1 == b2) && (b2 == b3));
    }

    int find(vector<Point>& a,vector<Point>& b, vector<Point>& c, vector<Point>& blk) {
        int count=0;
        for (int i=0; i<a.size(); i++) {
            for (int j=0; j<b.size(); j++) {
                for (int k=0; k<c.size(); k++) {
                    bool allIn=true;
                    for (int p=0; p<blk.size(); p++) {
                        if (!PointInTriangle(blk[p], a[i], b[j], c[k])) {
                            allIn=false;
                            break;
                        }
                    }
                    if (allIn) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};

// <editor-fold defaultstate="collapsed" desc="Generated Code">
namespace moj_harness {
    int run_test_case(int);
    void run_test(int casenum = -1, bool quiet = false) {
        if (casenum != -1) {
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
            int m                     = 4;
            int x[]                   = { 1, 2, 3 };
            int y[]                   = { 1, 3, 2 };
            int expected__            = 8;

            clock_t start__           = clock();
            int received__            = EnclosingTriangleColorful().getNumber(m, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
            return verify_case(casenum, expected__, received__, clock()-start__);
        }
        case 1: {
            int m                     = 7;
            int x[]                   = { 1, 1, 6, 6 };
            int y[]                   = { 1, 6, 1, 6 };
            int expected__            = 0;

            clock_t start__           = clock();
            int received__            = EnclosingTriangleColorful().getNumber(m, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
            return verify_case(casenum, expected__, received__, clock()-start__);
        }
        case 2: {
            int m                     = 4;
            int x[]                   = { 2 };
            int y[]                   = { 2 };
            int expected__            = 72;

            clock_t start__           = clock();
            int received__            = EnclosingTriangleColorful().getNumber(m, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
            return verify_case(casenum, expected__, received__, clock()-start__);
        }
        case 3: {
            int m                     = 10;
            int x[]                   = { 2, 6, 7, 6 };
            int y[]                   = { 7, 7, 9, 3 };
            int expected__            = 52;

            clock_t start__           = clock();
            int received__            = EnclosingTriangleColorful().getNumber(m, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
            return verify_case(casenum, expected__, received__, clock()-start__);
        }
        case 4: {
            int m                     = 15;
            int x[]                   = { 7, 6, 5, 4, 3 };
            int y[]                   = { 1, 4, 7, 10, 13 };
            int expected__            = 150;

            clock_t start__           = clock();
            int received__            = EnclosingTriangleColorful().getNumber(m, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
            return verify_case(casenum, expected__, received__, clock()-start__);
        }
        case 5: {
            int m                     = 300;
            int x[]                   = { 117, 183, 181, 118, 132, 128, 184, 150, 168, 121, 179, 132, 168, 182, 119, 117, 180, 120, 175, 177, 116, 175, 128, 163, 181, 178, 123, 118, 172, 143, 163, 157, 179, 122, 121, 119, 157, 122, 150, 180, 137, 177, 125, 123, 172, 125, 137, 143, 120, 178 } ;
            int y[]                   = { 157, 157, 132, 163, 181, 180, 150, 116, 181, 125, 125, 119, 119, 163, 132, 143, 172, 172, 179, 178, 150, 121, 120, 118, 168, 123, 178, 137, 120, 117, 182, 117, 175, 177, 175, 168, 183, 123, 184, 128, 118, 122, 179, 122, 180, 121, 182, 183, 128, 177 } ;
            int expected__            = 21690886;

            clock_t start__           = clock();
            int received__            = EnclosingTriangleColorful().getNumber(m, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
            return verify_case(casenum, expected__, received__, clock()-start__);
        }

        // custom cases

        /*
        case 6: {
            int m                     = ;
            int x[]                   = ;
            int y[]                   = ;
            int expected__            = ;

            clock_t start__           = clock();
            int received__            = EnclosingTriangleColorful().getNumber(m, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
            return verify_case(casenum, expected__, received__, clock()-start__);
        }
        //*/
        /*
        case 7: {
            int m                     = ;
            int x[]                   = ;
            int y[]                   = ;
            int expected__            = ;

            clock_t start__           = clock();
            int received__            = EnclosingTriangleColorful().getNumber(m, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
            return verify_case(casenum, expected__, received__, clock()-start__);
        }
        //*/
        /*
        case 8: {
            int m                     = ;
            int x[]                   = ;
            int y[]                   = ;
            int expected__            = ;

            clock_t start__           = clock();
            int received__            = EnclosingTriangleColorful().getNumber(m, vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
            return verify_case(casenum, expected__, received__, clock()-start__);
        }
        //*/
        default:
            return -1;
        }
    }
}


int main(int argc, char *argv[]) {
    if (argc == 1) {
        moj_harness::run_test();
    } else {
        for (int i=1; i<argc; ++i)
            moj_harness::run_test(atoi(argv[i]));
    }
}
// </editor-fold>
