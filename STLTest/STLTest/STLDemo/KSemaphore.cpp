//
//  KSemaphore.cpp
//  STLTest
//
//  Created by ksnowlv on 2022/2/26.
//

#include "KSemaphore.hpp"

KSemaphore::KSemaphore(const int count):mCount(count) {
    
}

KSemaphore::~KSemaphore() {
    
}

void KSemaphore::signal() {
    std::unique_lock<std::mutex> lock(mMutex);
    //std::unique_ptr<KSemaphore> mLock(std::make_unique<KSemaphore>());
    ++mCount;
    //有线程挂起
    if (mCount < 1) {
        mCV.notify_one();
    }
}

void KSemaphore::signalAll() {
    std::unique_lock<std::mutex> lock(mMutex);
    ++mCount;
    //有线程挂起
    if (mCount <= 0) {
        mCV.notify_all();
    }
}

void KSemaphore::wait() {
    std::unique_lock<std::mutex> lock(mMutex);
    --mCount;
    //资源不足，挂起等待；
    if (mCount < 0) {
        mCV.wait(lock);
    }
}
