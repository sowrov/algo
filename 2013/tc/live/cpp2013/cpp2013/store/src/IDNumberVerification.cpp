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

class IDNumberVerification {
public:
    string verify( string id, vector <string> regionCodes ) {
        if (!isValidReg(id.substr(0, 6), regionCodes)) {
            return "Invalid";
        }
        int y, m, d;
        sscanf(id.substr(6,4).c_str(), "%d", &y);
        sscanf(id.substr(10,2).c_str(), "%d", &m);
        sscanf(id.substr(12,2).c_str(), "%d", &d);
        
        if (!isValidBday(y, m, d)) {
            return "Invalid";
        }

        string str = id.substr(14, 3);
        if (str=="000") {
            return "Invalid";
        }

        if (!isValidChk(id)) {
            return "Invalid";
        }
        int g=0;
        for (int i=0; i<str.size(); i++) {
            g = g*10+(str[i]-'0');
        }

        return (g&1)?"Male":"Female";
    }

    bool isValidChk(string str) {
        int j=17;
        int sum=0;
        for (int i=0; i<17; i++, j--) {
            int p = 1<<j;
            int v = (str[i]-'0')*p;
            sum += v;
        }
        int x = str[17]=='X' ? 10: (str[17]-'0'); 
        sum += x;
        int r = sum%11;
        return r==1;
    }
    
    bool isValidBday(int y, int m, int d) {
        int minYear = 1900;
        int maxYear = 2011;
        bool valid = true;
        int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};

        if (isLeapYear(y)) {
            days[1]++;
        }
        
        if ((m >= 1) && (m <= 12) && (d >= 1) &&
            (y >= minYear) && (y <= maxYear) && d<=days[m]) {
            return true;
        } else {
            return false;
        }
    }

    bool isLeapYear(int year) {
        bool leap = false;

        leap = (((year % 4) == 0) && ((year % 100) != 0));
        if (leap == false) {
            if (((year % 4) == 0) && ((year % 100) == 0)) {
                leap = ((year % 400) == 0);
            }
        }
        return leap;
    }

    bool isValidReg(string str, vector<string>& rcode) {
        for (int i=0; i<rcode.size(); i++) {
            if (str == rcode[i]) {
                return true;
            }
        }
        return false;
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
    
    int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) { 
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
            cerr << "    Expected: \"" << expected << "\"" << endl; 
            cerr << "    Received: \"" << received << "\"" << endl; 
        }
        
        return verdict == "PASSED";
    }

    int run_test_case(int casenum) {
        switch (casenum) {
        case 0: {
            string id                 = "441323201212060636";
            string regionCodes[]      = {"441323"};
            string expected__         = "Male";

            clock_t start__           = clock();
            string received__         = IDNumberVerification().verify(id, vector <string>(regionCodes, regionCodes + (sizeof regionCodes / sizeof regionCodes[0])));
            return verify_case(casenum, expected__, received__, clock()-start__);
        }
        case 1: {
            string id                 = "62012319240507058X";
            string regionCodes[]      = {"620123"};
            string expected__         = "Female";

            clock_t start__           = clock();
            string received__         = IDNumberVerification().verify(id, vector <string>(regionCodes, regionCodes + (sizeof regionCodes / sizeof regionCodes[0])));
            return verify_case(casenum, expected__, received__, clock()-start__);
        }
        case 2: {
            string id                 = "321669197204300886";
            string regionCodes[]      = {"610111","659004"};
            string expected__         = "Invalid";

            clock_t start__           = clock();
            string received__         = IDNumberVerification().verify(id, vector <string>(regionCodes, regionCodes + (sizeof regionCodes / sizeof regionCodes[0])));
            return verify_case(casenum, expected__, received__, clock()-start__);
        }
        case 3: {
            string id                 = "230231198306900162";
            string regionCodes[]      = {"230231"};
            string expected__         = "Invalid";

            clock_t start__           = clock();
            string received__         = IDNumberVerification().verify(id, vector <string>(regionCodes, regionCodes + (sizeof regionCodes / sizeof regionCodes[0])));
            return verify_case(casenum, expected__, received__, clock()-start__);
        }
        case 4: {
            string id                 = "341400198407260005";
            string regionCodes[]      = {"341400"};
            string expected__         = "Invalid";

            clock_t start__           = clock();
            string received__         = IDNumberVerification().verify(id, vector <string>(regionCodes, regionCodes + (sizeof regionCodes / sizeof regionCodes[0])));
            return verify_case(casenum, expected__, received__, clock()-start__);
        }
        case 5: {
            string id                 = "520381193206090891";
            string regionCodes[]      = {"532922","520381"};
            string expected__         = "Invalid";

            clock_t start__           = clock();
            string received__         = IDNumberVerification().verify(id, vector <string>(regionCodes, regionCodes + (sizeof regionCodes / sizeof regionCodes[0])));
            return verify_case(casenum, expected__, received__, clock()-start__);
        }

        // custom cases

        /*
        case 6: {
            string id                 = ;
            string regionCodes[]      = ;
            string expected__         = ;

            clock_t start__           = clock();
            string received__         = IDNumberVerification().verify(id, vector <string>(regionCodes, regionCodes + (sizeof regionCodes / sizeof regionCodes[0])));
            return verify_case(casenum, expected__, received__, clock()-start__);
        }
        //*/
        /*
        case 7: {
            string id                 = ;
            string regionCodes[]      = ;
            string expected__         = ;

            clock_t start__           = clock();
            string received__         = IDNumberVerification().verify(id, vector <string>(regionCodes, regionCodes + (sizeof regionCodes / sizeof regionCodes[0])));
            return verify_case(casenum, expected__, received__, clock()-start__);
        }
        //*/
        /*
        case 8: {
            string id                 = ;
            string regionCodes[]      = ;
            string expected__         = ;

            clock_t start__           = clock();
            string received__         = IDNumberVerification().verify(id, vector <string>(regionCodes, regionCodes + (sizeof regionCodes / sizeof regionCodes[0])));
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
