//
//  Magic.cpp
//  STLTest
//
//  Created by ksnowlv on 2022/3/1.
//

#include "Magic.hpp"

#include <string>

using namespace std;

void magic_fuc(const Magic&) {

    std::cout << "magic_fuc(const Magic&)" << std::endl;

}

Magic::~Magic() {
    
}

void Magic::test() {
    TTType type = TTType::TTError;
    
    std::cout<<"Magic TTType = "<<type<<std::endl;
    
    //C++11 提供了原始字符串字面量的写法，可以在一个字符串前方使用 R 来修饰这个字符串，同时，将原始字符串使用括号包裹，
    std::string str = R"(C:\\What\\The\\Fxxk)";
    std::cout << str << std::endl;
    
    std::string str1 = R"(\\\t\r\\hello<>world)";
    std::cout << str1 << std::endl;
    
    
    auto pointer = std::make_shared<int>(10);
    
    shared_ptr<int> pointer2 = pointer;    // 引用计数+1
    
    auto pointer3 = pointer;    // 引用计数+1
    
    int *p = pointer.get();             // 这样不会增加引用计数
    
    std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl;      // 3
    
    std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl;    // 3
    
    std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl;    // 3
    
    pointer2.reset();
    std::cout << "reset pointer.use_count() = " << pointer.use_count() << std::endl;      // 2
    
    std::cout << "reset pointer2.use_count() = " << pointer2.use_count() << std::endl;  // 0
    
    std::cout << "reset pointer3.use_count() = " << pointer3.use_count() << std::endl;    // 2

    pointer3.reset();
    std::cout << "reset pointer3:" << std::endl;
    std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl;      // 1
    std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl;    // 0
    std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl;    //0
    
    std::unique_ptr<Magic> p1(std::make_unique<Magic>());

    // p1 不空, 输出
    if (p1) p1->printInfo();
    {
        std::unique_ptr<Magic> p2(std::move(p1));
        

        // p2 不空, 输出
        magic_fuc(*p2);

        // p2 不空, 输出
        if(p2) p2->printInfo();

        // p1 为空, 无输出
        if(p1) p1->printInfo();

        p1 = std::move(p2);

        // p2 为空, 无输出
        if(p2) p2->printInfo();
        std::cout << "p2 被销毁" << std::endl;
    }
    // p1 不空, 输出
    if (p1) p1->printInfo();
    
    
    std::unique_ptr<int[]> pInt(new int[100]);
    
    for (int i = 0; i < 100; ++i ) {
        pInt[i] = i;
    }
    
    cout<<pInt[2]<<endl<<pInt[3]<<endl;

}

void Magic::printInfo() {
    std::cout<<"printInfo"<<std::endl;
}

