//
//  StringTest.cpp
//  STLTest
//
//  Created by ksnowlv on 2022/4/9.
//

#include "StringTest.hpp"
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include "Hello.h"

using namespace std;


void StringTest::test() {
    
    int n = 12345600;
    vector<int> v;
    
    while(n != 0){
        v.emplace_back(n%10);
        n /= 10;
    }
    
    string s;
    
    for(auto it : v) {
        s += to_string(it);
    }
    
    std::cout<<s<<endl;
    
    string s1;
    
    for(auto it : v) {
        s1 +=  char(it + '0') ;
    }
    
    std::cout<<s1<<endl;
    
    reverse(s1.begin(), s1.end());
    
    std::cout<<s1<<endl;
    
    std::cout<<s1.back()<<" "<< endl;
    
    string num("11.11");
    cout<<stoi(num)<<endl;
    cout<<stof(num)<<endl;
    cout<<stod(num)<<endl;
    cout<<stoll(num)<<endl;
    
    string numString("123456");
    
    std::unique_ptr<string> p(std::make_unique<string>("abc"));
    
    std::unique_ptr<int> q(std::make_unique<int>());
    
    cout<<*p<<endl;
    
    set<char> sets;
    
    
    std::map<int , std::string> person;
    std::map<int , std::string> p1;
    map<int, int> p2;
    p2[1] = 1;
    p2.insert(pair < int,int > (1,2));
    p2.insert(pair<int, int>(2,3));
    map<char, int> m;
    m['c'] = 1;
    
    char* res = findSubString("abcdefg", "def");
    
    std::cout<<res<<endl;
}


