//
//  VectorTestC.c
//  STLTest
//
//  Created by ksnowlv on 2022/2/25.
//

#include "SwiftCallC.hpp"
#include "VectorTest.hpp"
#include "DequeTest.hpp"
#include "ListTest.hpp"
#include "QueueTest.hpp"
#include "ThreadTest.hpp"
#include "StackTest.hpp"
#include "ProductorConsumerTest.hpp"
#include "Magic.hpp"
#include "ArrayTest.hpp"
#include "SortTest.hpp"
#include "LambdaTest.hpp"
#include "StringTest.hpp"

static const int MAXLen = 11;

static BaseTest *gTestList[MAXLen];

void createBaseTest() {
    
    for (int i = 0; i < MAXLen; ++i) {
        gTestList[i] = NULL;
    }
    
    gTestList[0] = new VectorTest();
    gTestList[1] = new DequeueTest();
    gTestList[2] = new ListTest();
    gTestList[3] = new QueueTest();
    gTestList[4] = new ThreadTest();
    gTestList[5] = new StackTest();
    gTestList[6] = new Magic();
    gTestList[7] = new ArrayTest();
    gTestList[8] = new SortTest();
    gTestList[9] = new LambdaTest();
    gTestList[10] = new StringTest();
    //gTestList[7] = new ProductorConsumerTest();
}

void test() {
    
    for (int i = 0; i < MAXLen; ++i) {
        gTestList[i]->test();
    }
    
//    unique_ptr<ThreadTest> t(new ThreadTest());
//    t->test();
    
//    ThreadTest t;
//    t.test();
}

void destroyBaseTest() {
    
    for (int i = 0; i < MAXLen; ++i) {
        delete gTestList[i];
    }
}

