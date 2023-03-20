//
//  ProductorConsumerTest.cpp
//  STLTest
//
//  Created by ksnowlv on 2022/2/26.
//

#include "ProductorConsumerTest.hpp"
#include <iostream>
#include <thread>
using namespace std;

ProductorConsumerTest::ProductorConsumerTest(){
//    mPlateSemaphore.reset(new KSemaphore());
//    mOrangeSemaphore.reset(new KSemaphore());
//    mAppleSemaphore.reset(new KSemaphore());
    mPlateSemaphore = std::make_unique<KSemaphore>(1);
    mAppleSemaphore = std::make_unique<KSemaphore>();
    mOrangeSemaphore = std::make_unique<KSemaphore>();
}

ProductorConsumerTest::~ProductorConsumerTest() {
    
}


void ProductorConsumerTest::test() {
    
    std::thread f(ProductorConsumerTest::father, std::ref(*this));
    std::thread m(ProductorConsumerTest::mother, std::ref(*this));
    std::thread s(ProductorConsumerTest::son, std::ref(*this));
    std::thread d(ProductorConsumerTest::daughter, std::ref(*this));
    f.join();
    m.join();
    s.join();
    d.join();
}

void ProductorConsumerTest::father(ProductorConsumerTest &test)
 {
      while (true && test.mPlateSemaphore)
      {
          
          test.mPlateSemaphore->wait();
          cout<< "爸爸往盘中放一个苹果" <<endl;
          test.mAppleSemaphore->signal();
          //std::this_thread::sleep_for(std::chrono::milliseconds(500));
      }
 }

void ProductorConsumerTest::mother(ProductorConsumerTest &test)
{
     while (true &&  test.mPlateSemaphore) {
         test.mPlateSemaphore->wait();
         cout << "妈妈往盘中放一个橘子" << endl;
         test.mOrangeSemaphore->signal();
         //std::this_thread::sleep_for(std::chrono::milliseconds(700));
     }
 }

 void ProductorConsumerTest::son(ProductorConsumerTest &test)
 {
     while (true && test.mAppleSemaphore)
     {
         test.mAppleSemaphore->wait();
         cout << "儿子吃苹果" << endl;
         test.mPlateSemaphore->signal();
     }
 }

void ProductorConsumerTest::daughter(ProductorConsumerTest &test)
 {
     while (true)
     {
         test.mOrangeSemaphore->wait();
         cout << "女儿吃橘子" << endl;
         test.mPlateSemaphore->signal();
     }
 }



