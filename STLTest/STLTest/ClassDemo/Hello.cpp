//
//  Hello.c
//  STLTest
//
//  Created by ksnowlv on 2022/3/2.
//

#include "Hello.h"

#include <iostream>


char *findSubString(const char* p, const char* q) {
    if (nullptr == p || nullptr == q) {
        return nullptr;
    }
    
    char *m = (char*)p;
    char *n = (char*)q;
    char *cur = m;
    
    while (cur) {
        
        char *a = cur;
        char *b = n;
        while (a && b && *a == *b) {
            ++a;
            ++b;
        }
        
        if (*b == '\0') {
            return cur;
        }else {
            ++cur;
        }
    }
    
    return nullptr;
}

//int main() {
//    std::cout << "Hello, World!" << std::endl;
//    return 0;
//}
