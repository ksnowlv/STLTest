//
//  KSemaphore.hpp
//  STLTest
//
//  Created by ksnowlv on 2022/2/26.
//

#ifndef KSemaphore_hpp
#define KSemaphore_hpp

#include <stdio.h>

#include <mutex>
#include <condition_variable>

class KSemaphore {
public:
    KSemaphore(const int count = 0);
    ~KSemaphore();
    
public:
    
    void signal();
    void signalAll();
    void wait();
    
private:
    std::mutex mMutex;
    std::condition_variable mCV;
    long mCount;
    
};

#endif /* KSemaphore_hpp */
