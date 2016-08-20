/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   HR_CommonChild.cpp
 * Author: home
 *
 * Created on March 19, 2016, 8:33 PM
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
int memo[5002][5002];

int main() {
    string a,b;
    cin>>a>>b;
    a="-"+a;
    b="-"+b;
    clr0(memo);
    for (int i=1; i<a.length(); i++) {
        for (int j=1; j<b.length(); j++) {
            if (a[i]==b[j]) {
                memo[i][j] = memo[i-1][j-1]+1;
            } else {
                memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
            }
        }
    }
    cout<<memo[a.length()-1][b.length()-1]<<endl;
    return 0;
}
