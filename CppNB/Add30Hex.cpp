/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Add30Hex.cpp
 * Author: home
 *
 * Created on February 22, 2017, 6:33 AM
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
    int v;
    scanf("%x", &v);
    int up=v;
    for (int i=0; i<20; i++) {
        up-= 0x30;
        printf("%x\n", up);
    }
    printf("-----------------\n");
    printf("%x\n", v);
    printf("-----------------\n");
    int dw=v;
    for (int i=0; i<20; i++) {
        dw+= 0x30;
        printf("%x\n", dw);
    }
    return 0;
}
