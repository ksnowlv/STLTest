//
//  ThreadTest.hpp
//  STLTest
//
//  Created by ksnowlv on 2022/2/26.
//

#ifndef ThreadTest_hpp
#define ThreadTest_hpp

#include <stdio.h>
#include "BaseTest.hpp"

class ThreadTest: public BaseTest {
public:
    ThreadTest();
    ~ThreadTest();
    
public:
    virtual void test() override;
    
};

#endif /* ThreadTest_hpp */
