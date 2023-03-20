//
//  Magic.hpp
//  STLTest
//
//  Created by ksnowlv on 2022/3/1.
//

#ifndef Magic_hpp
#define Magic_hpp

#include <stdio.h>
#include <iostream>
#include "BaseTest.hpp"

class Magic: public BaseTest {
public:
    ~Magic();
    Magic() = default;  // 显式声明使用编译器生成的构造
    Magic& operator=(const Magic&) = delete; // 显式声明拒绝编译器生成构造
    Magic(int magic_number);

public:
    void test() override;
private:
    void printInfo();
    
};


enum class TTType: unsigned int {
    TTUnkown = 0,
    TTSucess,
    TTError,
    TTService = 100
    
};



template<typename T>
//而我们希望获得枚举值的值时，将必须显式的进行类型转换，不过我们可以通过重载 << 这个算符来进行输出，可以收藏下面这个代码段：
std::ostream& operator<<(typename std::enable_if<std::is_enum<T>::value, std::ostream>::type& stream, const T& e)

{

    return stream << static_cast<typename std::underlying_type<T>::type>(e);
}


struct Base {
    virtual void foo() final;
};

struct SubClass1 final: Base {
    
};// 合法

//struct SubClass2 : SubClass1 {
//
//};                  // 非法, SubClass1 已 final
//
//
//struct SubClass3: Base {
//        void foo(); // 非法, foo 已 final
//};



#endif /* Magic_hpp */
