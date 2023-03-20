//
//  LambdaTest.cpp
//  STLTest
//
//  Created by ksnowlv on 2022/3/1.
//

#include "LambdaTest.hpp"
#include <iostream>
using namespace std;

using foo = void(int);  // 定义函数指针, using 的使用见上一节中的别名语法
using fuc = int(const char *s);

void LambdaFunctional(foo f) {

    f(1);
}

int LambdaFooo(int para) {
    return para;
}


LambdaTest::~LambdaTest() {
    
}

void LambdaTest::test() {
    
    auto x = add(10, 20);
    std::cout<<"10 + 20"<<x<<endl;
    
    auto y = add(1.2, 1.3);
    std::cout<<"1.2 + 1.3"<<y<<endl;
    
    auto func = [] (int value) {
        std::cout<<"value="<<value<<std::endl;
    };
    
    LambdaFunctional(func);// 函数指针调用
    
    func(2);// lambda 表达式调用
    
    
    //C++11 std::function 是一种通用、多态的函数封装，它的实例可以对任何可以调用的目标实体进行存储、复制和调用操作，它也是对 C++中现有的可调用实体的一种类型安全的包裹（相对来说，函数指针的调用不是类型安全的），换句话说，就是函数的容器。当我们有了函数的容器之后便能够更加方便的将函数、函数指针作为对象进行处理
    // std::function 包装了一个返回值为 int, 参数为 int 的函数
    std::function<int(int)> f = LambdaFooo;
    

    int important = 10;
    std::function<int(int)> func2 = [&](int value) ->int {
        return 1+value+important;
    };
    
    std::function<int(int)> fun= [&](int value) ->int {
        return 1+value +important;
    };
    
    std::function<int()> fun3= [&]() ->int {
        return 1 +important;
    };
    
    std::function<void()> fun4= [&]() ->void {
       int res =  1  + important;
    };
    
    std::cout << f(10) << std::endl;
    std::cout << func2(10) << std::endl;
    
    //指针
    
    int a[5] = {1,2,3,4,5};
    int *p = (int*)(&a + 1);
    
    std::cout<<"a+1="<<*(a + 1)<<endl;
    std::cout<<"p-1="<<*(p - 1)<<endl;
    
    std::cout<<"int:"<<typeid(int).name()<<endl;
    std::cout<<"string:"<<typeid(string).name()<<endl;
    std::cout<<"BaseTest:"<<typeid(BaseTest).name()<<endl;
    std::cout<<"LambdaTest:"<<typeid(LambdaTest).name()<<endl;
   
    
}
