//
//  LockTest.hpp
//  STLTest
//
//  Created by ksnowlv on 2022/3/10.
//

#ifndef LockTest_hpp
#define LockTest_hpp

#include <stdio.h>

#include <mutex>
#include <condition_variable>

class LockTest {
public:
    LockTest();
    ~LockTest();
    
private:
    std::mutex mMutext;
    
};

#endif /* LockTest_hpp */
