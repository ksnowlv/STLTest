//
//  SortTest.cpp
//  STLTest
//
//  Created by ksnowlv on 2022/3/11.
//

#include "SortTest.hpp"
#include <string.h>
#include <iostream>
using namespace std;


void SortTest::test() {
        
    string s;
    s += "a";
    
    const int KLenOfArray = 10;
    int p[KLenOfArray] = {10,6,12,5,1,8,11,32,1,21};
    int q[KLenOfArray];
    memset(q, 0, sizeof(int) * KLenOfArray);
    memcpy(q, p, sizeof(int) * KLenOfArray);
    
    std::cout<<"初始数组顺序如下"<<endl;
    showArray(q, KLenOfArray);
    
    memset(q, 0, sizeof(int) * KLenOfArray);
    memcpy(q, p, sizeof(int) * KLenOfArray);
    std::cout<<"冒泡排序后为"<<endl;
    bubbleSort(p, KLenOfArray);
    showArray(q, KLenOfArray);
    
    
    std::cout<<"插入排序后为"<<endl;
    insertionSort(q, KLenOfArray);
    showArray(q, KLenOfArray);
    
    memset(q, 0, sizeof(int) * KLenOfArray);
    memcpy(q, p, sizeof(int) * KLenOfArray);
    std::cout<<"选择排序后为"<<endl;
    selectionSort(p, KLenOfArray);
    showArray(q, KLenOfArray);
    
    memset(q, 0, sizeof(int) * KLenOfArray);
    memcpy(q, p, sizeof(int) * KLenOfArray);
    std::cout<<"快速排序后为"<<endl;
    quickSort(p, 0, KLenOfArray - 1);
    showArray(q, KLenOfArray);
    
    
    
}

void SortTest::bubbleSort(int *p, const int len) {
    
    bool exchangeFlag = false;
    for (int i = 0; i < len - 1; ++i) {
        for (int j = 0; j < len - 1 - i; ++j) {
            if (p[j] > p[j + 1]) {
                swap(p[j], p[j + 1]);
                exchangeFlag = true;
            }
        }
        
        if (!exchangeFlag) {
            break;
        }
    }
}

void SortTest::bubbleSort(vector<int> &v) {
    
    bool exchangeFlag = false;
    const unsigned long len  = v.size();
    
    for (int i = 0; i < len - 1; ++i) {
        for (int j = 0; j < len - 1 - i; ++j) {
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
                exchangeFlag = true;
            }
        }
        
        if (!exchangeFlag) {
            break;
        }
    }
}

void SortTest::insertionSort(int *p, const int len) {
    
    int key = 0;
    
    for (int i = 1; i < len; ++i) {
        key = p[i];
        int j = i - 1;
        
        while (j >= 0 && p[j] > key) {
            p[j + 1] = p[j];
            --j;
        }
        
        p[j + 1] = key;
    }
}

void SortTest::selectionSort(int *p, const int len) {
    
    for (int i = 0; i < len; ++i) {
        int smallIdx = i;
        for (int j = i + 1; j < len; ++j) {
            if (p[j] < p[smallIdx]) {
                smallIdx = j;
            }
        }
        
        if (smallIdx != i) {
            swap(p[i], p[smallIdx]);
        }
    }
}

void SortTest::quickSort(int *p, const int start,const int end) {
    if (nullptr ==  p || start >= end) {
        return;
    }
    
    const int key = p[start];
    int left = start;
    int right = end;
    
    while (left < right) {
        
        while (left < right && p[right] >= key) {
            --right;
        }
        p[left] = p[right];
        
        while (left < right && p[left] <= key) {
            ++left;
        }
        
        p[right] = p[left];
        
    }
    
    p[left] = key;
    
    quickSort(p, start, left - 1);
    quickSort(p, left + 1, end);
}

void SortTest::quickSort(vector<int> &v,const int start, const int end) {
    if (v.empty() || start >= end) {
        return;
    }
    
    int left = start;
    int right = end;
    int key = v[start];
    
    while (left < right) {
        
        while (left < right && key <= v[right]) {
            --right;
        }
        
        v[left] = v[right];
        
        while (left < right && key >= v[left]) {
            ++left;
        }
        
        v[right] = v[left];
        
    }
    
    v[left] = key;
    
    quickSort(v, 0, left - 1);
    quickSort(v, left + 1, end);
    
}

const void SortTest::showArray(const int *p, const int len) const {
    if (nullptr == p || len == 0) {
        return;
    }
    
    std::cout<<"arraylist infommation:"<<endl;
    for (int i = 0; i < len; ++i) {
        std::cout<<p[i]<<",";
    }
    std::cout<<endl;
}

const void SortTest::swap(int &p, int &q) const {
    int temp = p;
    p = q;
    q = temp;
}

