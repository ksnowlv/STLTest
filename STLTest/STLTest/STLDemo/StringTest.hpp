//
//  StringTest.hpp
//  STLTest
//
//  Created by ksnowlv on 2022/4/9.
//

#ifndef StringTest_hpp
#define StringTest_hpp

#include <stdio.h>
#include "BaseTest.hpp"

class StringTest : public BaseTest {
public:
    StringTest() = default;
    ~StringTest() = default;
    
public:
    void test() override;
};

#endif /* StringTest_hpp */
