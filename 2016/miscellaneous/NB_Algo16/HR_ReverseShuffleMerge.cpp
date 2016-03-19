/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HR_ReverseShuffleMerge.cpp
 * Author: home
 *
 * Created on March 18, 2016, 9:43 PM
 */

#include "iomanip"
#include "vector"
#include "utility"
#include "cstring"
#include "numeric"
#include "set"
#include "ctime"
#include "fstream"
#include "cstdlib"
#include "bitset"
#include "cctype"
#include "map"
#include "algorithm"
#include "cassert"
#include "cstdio"
#include "string"
#include "list"
#include "sstream"
#include "iostream"
#include "deque"
#include "stack"
#include "cmath"
#include "queue"
#include "functional"
#include "climits"

using namespace std;

#define clr0(_arr) memset(_arr, 0, sizeof(_arr))
#define clr1(_arr) memset(_arr, -1, sizeof(_arr))
//INT_MAX, LONG_MAX, ULONG_MAX
#define BIG INT_MAX
#define PI (2.0*acos(0.0))
#define Eps (1e-9)

int main() {
    string s, rs, w, out = "", tmp;
    int cou[26], cnt[26];
    clr0(cou);
    cin>>s;
    tmp = s;
    rs = s;
    reverse(rs.begin(), rs.end());
    sort(tmp.begin(), tmp.end());

    for (int i = 0; i < tmp.length(); i += 2) {
        cou[tmp[i] - 'a']++;
    }
    int vp = 0;

    for (int i = 0; i < 26; i++) {
        while (cou[i] > 0) {

            int np = -1;
            for (int j = vp; j < rs.length(); j++) {
                if (rs[j] == (i + 'a')) {
                    np = j + 1;
                    break;
                }
            }
            cou[i]--;
            clr0(cnt);
            for (int j = np; j < rs.length(); j++) {
                cnt[rs[j] - 'a']++;
            }
            bool allFound = true;
            for (int j = 0; j < 26; j++) {
                if (cou[j] > cnt[j]) {
                    allFound = false;
                }
            }
            if (allFound) {
                out += (i + 'a');
                vp = np;
                i = -1;
            } else {
                cou[i]++;
                break;
            }
        }

    }

    cout << out << endl;
    return 0;
}
