//
//  VectorTest.cpp
//  STLTest
//
//  Created by ksnowlv on 2022/2/25.
//

#include "VectorTest.hpp"
#include <iostream>


VectorTest::VectorTest() {
    
}

VectorTest::~VectorTest() {
    
}

void VectorTest::test() {
    
    vector<int> v{1,20};
    
    constexpr int vectorSize = 20;
    
    for (int i = 0; i < vectorSize; ++i) {
        v.push_back(i);
    }
    
    cout<< "vector size = "<<v.size()<<endl;
    
    //访问其中10个值
    for (int i =0; i < 10; ++i) {
        cout<<"vector["<<i<<"]="<<v[i]<<endl;
    }
    
    swap(v[0], v[1]);
    
    printVector(v);
    
    //反向遍历
    cout<<"反向遍历"<<endl;
    for (std::vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it) {
        cout<<*it<<",";
    }
    cout<<endl;
    
    
    //删除指定区间内的元素
    for (::vector<int>::iterator it = v.begin(); it != v.end();) {
        
        if (*it == 3 || *it == 11) {
            v.erase(it);
        } else {
            ++it;
        }
    }
    cout<<"删除3,11元素后"<<endl;
    printVector(v);
    
    
    cout<<"删除[3,5]区间的元素后"<<endl;
    ::vector<int>::iterator it = v.begin();
    
    v.erase(it+3, it+5);
    printVector(v);
    

    //添加元素
    cout<<"在第5个位置添加10个数"<<endl;
    for (int i = 0; i < 10; ++i) {
        v.insert(it + 5, 100 +i);
    }
    
    printVector(v);
    
    std::vector<int>::iterator resIt =  std::find(v.begin(), v.end(), 109);
    
    if(resIt == v.end()) {
        cout<<"not find 9"<<endl;
    }else {
        cout<<"index = "<<distance(v.begin(), resIt)<<endl;
    }
    
    sort(v.begin(), v.end(), [](const int &a,const int &b) -> bool { return  a < b; });
    
}

void VectorTest::printVector(const vector<int> &v) {
    
//    std::vector<int>::const_iterator it = v.begin();
//
//    while (it != v.end()) {
//        cout<<*it<<",";
//        ++it;
//    }
//    cout<<endl;
    
    for (auto it :v) {
        std::cout<<it<<",";
    }
    std::cout<<endl;
}
