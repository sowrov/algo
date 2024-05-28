#include "cassert"
#include "algorithm"
#include "list"
#include "iostream"
#include "functional"
#include "sstream"
#include "set"
#include "iomanip"
#include "stack"
#include "cctype"
#include "numeric"
#include "ctime"
#include "cstdio"
#include "utility"
#include "deque"
#include "bitset"
#include "cmath"
#include "map"
#include "string"
#include "vector"
#include "cstdlib"
#include "cstring"
#include "queue"

using namespace std;

#define Zclr(arr) memset(arr, 0, sizeof(arr))
#define Nclr(arr) memset(arr, -1, sizeof(arr))
#define M31 1<<30
#define Pi (2.0*acos(0.0))
#define Eps (1e-9)

class CityMap {
public:
    string getLegend(vector<string> cityMap, vector<int> POIs) {
        string out="";
        vector<int>arr(26, 0);

        for (int i=0; i<cityMap.size(); i++) {
            for (int j=0; j<cityMap[i].length(); j++) {
                if(cityMap[i][j]!='.') {
                    arr[cityMap[i][j] - 'A']++;
                }
            }
        }

        for (int i=0; i<POIs.size(); i++) {
            for (int j=0; j<arr.size(); j++) {
                if (arr[j] == POIs[i]) {
                    out += 'A'+j;
                    break;
                }
            }
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
            string cityMap[] = {"M....M", "...R.M", "R..R.R"};
            int POIs[] = {3, 4};
            string expected_ = "MR";

            clock_t start_           = clock();
            string received_ = CityMap().getLegend(vector<string>(cityMap, cityMap + (sizeof cityMap / sizeof cityMap[0])), vector<int>(POIs, POIs + (sizeof POIs / sizeof POIs[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 1: {
            string cityMap[] = {"XXXXXXXZXYYY"};
            int POIs[] = {1, 8, 3};
            string expected_ = "ZXY";

            clock_t start_           = clock();
            string received_ = CityMap().getLegend(vector<string>(cityMap, cityMap + (sizeof cityMap / sizeof cityMap[0])), vector<int>(POIs, POIs + (sizeof POIs / sizeof POIs[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 2: {
            string cityMap[] = {"...........", "...........", "...........", "..........T"};
            int POIs[] = {1};
            string expected_ = "T";

            clock_t start_           = clock();
            string received_ = CityMap().getLegend(vector<string>(cityMap, cityMap + (sizeof cityMap / sizeof cityMap[0])), vector<int>(POIs, POIs + (sizeof POIs / sizeof POIs[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        case 3: {
            string cityMap[] = {"AIAAARRI.......GOAI.", ".O..AIIGI.OAAAGI.A.I", ".A.IAAAARI..AI.AAGR.", "....IAI..AOIGA.GAIA.", "I.AIIIAG...GAR.IIAGA", "IA.AOA....I....I.GAA", "IOIGRAAAO.AI.AA.RAAA", "AI.AAA.AIR.AGRIAAG..", "AAAAIAAAI...AAG.RGRA", ".J.IA...G.A.AA.II.AA"};
            int POIs[] = {16, 7, 1, 35, 11, 66};
            string expected_ = "GOJIRA";

            clock_t start_           = clock();
            string received_ = CityMap().getLegend(vector<string>(cityMap, cityMap + (sizeof cityMap / sizeof cityMap[0])), vector<int>(POIs, POIs + (sizeof POIs / sizeof POIs[0])));
            return verify_case(casenum, expected_, received_, clock()-start_);
        }
        default:
            return -1;
        }
    }

    //This method will only accept input files that are formatted in proper way.
    //Command line example: CityMap.exe -2 <CityMapIO.txt
    bool run_full_test() {
        int testCase, N, caseNo, correct=0;
        vector<string> cityMap;
        string cityMap_sin;
        vector<int> POIs;
        int POIs_sin;
        string expected_;

        std::cin>>testCase; std::cin.ignore(10, '\n');
        for (int i=0; i<testCase; i++) {
            std::cin>>caseNo; std::cin.ignore(10, '\n');
            cityMap.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::getline(std::cin,cityMap_sin );
                cityMap.push_back(cityMap_sin);
            }
            POIs.clear();
            std::cin>>N; std::cin.ignore(10, '\n');
            for(int j=0; j<N; j++) {
                std::cin>>POIs_sin; std::cin.ignore(10, '\n');
                POIs.push_back(POIs_sin);
            }
            std::getline(std::cin,expected_);
            clock_t start_           = clock();
            string received_ = CityMap().getLegend(cityMap, POIs);
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
