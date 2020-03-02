//
//  main.cpp
//  XcCpp
//
//  Created by Mahbub Mozadded on 02/03/2020.
//  Copyright © 2020 Mahbub Mozadded. All rights reserved.
//

#include <iostream>

class A {
private:
    int val;
public:
    A(){
        val=-1;
    }
    A(int val) {
        this->val = val;
    }
    int getVal() {
        return this->val;
    }
};

int main(int argc, const char * argv[]) {
    A a(10);
    std::cout << "Hello, World! "<<a.getVal()<<std::endl;
    return 0;
}
