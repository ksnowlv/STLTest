//
//  TreeTest.cpp
//  STLTest
//
//  Created by ksnowlv on 2022/3/12.
//

#include "TreeTest.hpp"


TreeNode* TreeTest::reConstructBinaryTree(vector<int> pre,vector<int> vin) {
    
    if(pre.empty() || vin.empty() || pre.size() != vin.size()) {
        return nullptr;
    }
    
    int rootValue = pre[0];
    TreeNode *rootNode = new TreeNode(rootValue);
    std::unique_ptr<TreeNode> rootNode1(std::make_unique<TreeNode>(-1));
  
    
    std::vector<int>::iterator it = std::find(vin.begin(), vin.end(), rootValue);
    auto index = std::distance(vin.begin(),it);
    
    vector<int> leftPre(pre.begin() + 1,pre.begin() + index + 1);
    vector<int> rightPre(pre.begin() + index + 1,pre.end());
    
    vector<int> leftVin(vin.begin(), vin.begin() + index);
    vector<int> rightVin(vin.begin() + index + 1,vin.end());
    
    rootNode->left = reConstructBinaryTree(leftPre,leftVin);
    rootNode->right = reConstructBinaryTree(rightPre, rightVin);
    return rootNode;
}
