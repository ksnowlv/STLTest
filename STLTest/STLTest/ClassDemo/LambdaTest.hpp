//
//  LambdaTest.hpp
//  STLTest
//
//  Created by ksnowlv on 2022/3/1.
//

#ifndef LambdaTest_hpp
#define LambdaTest_hpp

#include <stdio.h>
#include "BaseTest.hpp"


auto add = [](auto x, auto y) {
    return x+y;
};





class LambdaTest: public BaseTest {
public:
    LambdaTest() = default;
    ~LambdaTest();
    
public:
    void test() override;
};

#endif /* LambdaTest_hpp */
