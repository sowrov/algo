#include "set"
#include "iomanip"
#include "vector"
#include "algorithm"
#include "cstring"
#include "functional"
#include "list"
#include "iostream"
#include "cstdlib"
#include "map"
#include "ctime"
#include "cctype"
#include "cstdio"
#include "deque"
#include "cmath"
#include "string"
#include "stack"
#include "utility"
#include "numeric"
#include "bitset"
#include "sstream"
#include "queue"
#include "cassert"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
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
        cout<<y<<" "<<days[m-1]<<" "<<d<<endl; 
        if ((m >= 1) && (m <= 12) && (d >= 1) &&
            (y >= minYear) && (y <= maxYear) && d<=days[m-1]) {
            return true;
        } else {
            return false;
        }
    }

    bool isLeapYear(int year) {
        return ((year%4==0 && year%100!=0) || year%400==0);
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
            string id = "441323200312060636";
            string regionCodes[] = {"441323"};
            string expected_ = "Male";

            clock_t start_           = clock();
            string received_ = IDNumberVerification().verify(id, vector<string>(regionCodes, regionCodes + (sizeof regionCodes / sizeof regionCodes[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            string id = "62012319240507058X";
            string regionCodes[] = {"620123"};
            string expected_ = "Female";

            clock_t start_           = clock();
            string received_ = IDNumberVerification().verify(id, vector<string>(regionCodes, regionCodes + (sizeof regionCodes / sizeof regionCodes[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            string id = "321669197204300886";
            string regionCodes[] = {"610111", "659004"};
            string expected_ = "Invalid";

            clock_t start_           = clock();
            string received_ = IDNumberVerification().verify(id, vector<string>(regionCodes, regionCodes + (sizeof regionCodes / sizeof regionCodes[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            string id = "230231198306900162";
            string regionCodes[] = {"230231"};
            string expected_ = "Invalid";

            clock_t start_           = clock();
            string received_ = IDNumberVerification().verify(id, vector<string>(regionCodes, regionCodes + (sizeof regionCodes / sizeof regionCodes[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 4: {
            string id = "341400198407260005";
            string regionCodes[] = {"341400"};
            string expected_ = "Invalid";

            clock_t start_           = clock();
            string received_ = IDNumberVerification().verify(id, vector<string>(regionCodes, regionCodes + (sizeof regionCodes / sizeof regionCodes[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 5: {
            string id = "520381193206090891";
            string regionCodes[] = {"532922", "520381"};
            string expected_ = "Invalid";

            clock_t start_           = clock();
            string received_ = IDNumberVerification().verify(id, vector<string>(regionCodes, regionCodes + (sizeof regionCodes / sizeof regionCodes[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        default:
            return -1;
        }
    }

    //This method will only accept input files that are formatted in proper way.
    //Command line example: IDNumberVerification.exe -2 <IDNumberVerificationIO.txt
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        string id;
        vector<string> regionCodes;
        string regionCodes_sin;
        string expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            std::getline(std::cin,id);
            regionCodes.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::getline(std::cin,regionCodes_sin );
                regionCodes.push_back(regionCodes_sin);
            }
            std::getline(std::cin,expected_);
            clock_t start_           = clock();
            string received_ = IDNumberVerification().verify(id, regionCodes);
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
