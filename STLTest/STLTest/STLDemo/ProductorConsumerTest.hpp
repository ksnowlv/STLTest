//
//  ProductorConsumerTest.hpp
//  STLTest
//
//  Created by ksnowlv on 2022/2/26.
//

#ifndef ProductorConsumerTest_hpp
#define ProductorConsumerTest_hpp

#include <stdio.h>
#include "KSemaphore.hpp"
#include "BaseTest.hpp"

/*
　　吃水果问题：桌子有一只盘子，只允许放一个水果，父亲专向盘子放苹果，母亲专向盘子放桔子 儿子专等吃盘子的桔子，女儿专等吃盘子的苹果。只要盘子为空，父亲或母亲就可以向盘子放水果， 仅当盘子有自己需要的水果时，儿子和女儿可从盘子取出。请给出四个人之间的同步关系，并用 pv操作实现四个人的正确活动的问题。
*/


class ProductorConsumerTest: public BaseTest {
public:
    ProductorConsumerTest();
    ~ProductorConsumerTest();

public:
    void test();
    
private:
    static void father(ProductorConsumerTest &test);
    static void mother(ProductorConsumerTest &test);
    static void son(ProductorConsumerTest &test);
    static void daughter(ProductorConsumerTest &test);
    
private:
    
    std::unique_ptr<KSemaphore> mPlateSemaphore;
    std::unique_ptr<KSemaphore> mOrangeSemaphore;
    std::unique_ptr<KSemaphore> mAppleSemaphore;
};

#endif /* ProductorConsumerTest_hpp */
