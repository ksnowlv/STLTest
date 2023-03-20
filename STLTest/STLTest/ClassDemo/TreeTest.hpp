//
//  TreeTest.hpp
//  STLTest
//
//  Created by ksnowlv on 2022/3/12.
//

#ifndef TreeTest_hpp
#define TreeTest_hpp

#include <stdio.h>
#include <vector>
using namespace std;

//Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };





class TreeTest {
public:
    TreeTest() = default;
    ~TreeTest() = default;
    
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin);
};

#endif /* TreeTest_hpp */
