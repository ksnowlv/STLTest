//
//  ThreadTest.cpp
//  STLTest
//
//  Created by ksnowlv on 2022/2/26.
//

#include "ThreadTest.hpp"
#include <iostream>
#include <thread>
#include <string>
using namespace std;

void threadFuc1() {
    cout<<"thread1 id = "<<this_thread::get_id()<<endl;
    for (int i = 0; i < 10; ++i) {
        cout<<"线程使用函数指针作为参数"<<i<<endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    
}

void threadFuc2(const string &s) {
    cout<<"thread2 id ="<<this_thread::get_id()<<endl;
    
    for (int i = 0; i < 10; ++i) {
        cout<<"线程使用函数指针作为可变参数,第"<<i<<"个"<<s<<endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

void threadFuc3(int &n) {
    cout<<"thread3 id="<<this_thread::get_id()<<endl;
    for (int i = 0; i < 10; ++i) {
        ++n;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

ThreadTest::ThreadTest() {
    
}

ThreadTest::~ThreadTest() {
    
}

void ThreadTest::test() {
    
    int n = 0;
    std::thread t1(threadFuc1);
    std::thread t2(threadFuc2, "thread");
    std::thread t3(threadFuc3, std::ref(n));
    
    t1.join();
    
    if (t2.joinable()) {
        t2.join();
        cout<<"t2 join"<<endl;
    } else {
        cout<<"t2"<<endl;
    }
    
    if (t2.joinable()) {
        cout<<"t2 not join"<<endl;
    }else {
        cout<<"t2 join again"<<endl;
    }
    
   
    t3.join();
    
    cout<<"thread id = "<<this_thread::get_id()<<endl;
    
    std::cout<<"Final value of n is"<<n<<endl;
}


