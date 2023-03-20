//
//  VectorTest.hpp
//  STLTest
//
//  Created by ksnowlv on 2022/2/25.
//

#ifndef VectorTest_hpp
#define VectorTest_hpp

#include <stdio.h>
#include <vector>
using namespace std;

#include "BaseTest.hpp"

class VectorTest: public BaseTest {
public:
    VectorTest();
    ~VectorTest();
    
public:
    virtual void test() override;
    
private:
    void printVector(const vector<int> &v);
};

#endif /* VectorTest_hpp */
