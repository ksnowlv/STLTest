//
//  BaseTest.hpp
//  STLTest
//
//  Created by ksnowlv on 2022/2/26.
//

#ifndef BaseTest_hpp
#define BaseTest_hpp

#include <stdio.h>

class BaseTest {
public:
    BaseTest();
    ~BaseTest();
    
public:
    virtual void test();
};

#endif /* BaseTest_hpp */

