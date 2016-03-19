/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Hr_TheGridSearch.cpp
 * Author: home
 *
 * Created on March 17, 2016, 8:44 PM
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
int g[1001][1001];
int p[1001][1001];
int rg, cg, rp, cp;

void gridInp(int r, int c, int arr[][1001]) {
    string str;
    getline(cin, str);
    for (int i = 0; i < r; i++) {
        getline(cin, str);
        for (int j = 0; j < c; j++) {
            arr[i][j]=str[j]-'0';
        }
    }
}

bool hasP(int r, int c) {
    if (r + rp > rg || c + cp > cg) {
        return false;
    }
    for (int i = 0; i < rp; i++) {
        for (int j = 0; j < cp; j++) {
            if (g[r+i][c+j] != p[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {

    int t;
    cin>>t;
    while (t-- > 0) {
        cin >> rg>>cg;
        gridInp(rg, cg, g);
        cin >> rp>>cp;
        gridInp(rp, cp, p);
        bool found = false;
        for (int i = 0; i < rg && !found; i++) {
            for (int j = 0; j < cg; j++) {
                if ( found=hasP(i, j)) {
                    break;
                }
            }
        }
        if (found) {
            cout<<"YES\n";
        } else {
            cout<<"NO\n";
        }
    }
    return 0;
}
