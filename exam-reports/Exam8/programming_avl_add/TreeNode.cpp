#include "TreeNode.h"
#include <iostream>
#include <cmath>

// Part 1 code

void rotateRight(TreeNode *& root) {

    TreeNode *nuRoot = root->left_;
    root->left_ = nuRoot->right_;
    nuRoot->right_ = root;

    root = nuRoot;

    updateHeight(root);
    updateHeight(root->right_);
    return;
}


void rotateLeft(TreeNode *& root) {

    TreeNode *nuRoot = root->right_;
    root->right_ = nuRoot->left_;
    nuRoot->left_ = root;

    root = nuRoot;

    updateHeight(root);
    updateHeight(root->left_);
    return;
}

void rotateLeftRight(TreeNode* &root) {
    rotateLeft(root->left_);
    rotateRight(root);
}


void rotateRightLeft(TreeNode* &root) {
    rotateRight(root->right_);
    rotateLeft(root);
}

// Your Code

void insert(TreeNode* &root, int val) {
    // Your code here

    // The following lines are to silence compiler warnings.  Delete it.
    if(root==NULL){
      root=new TreeNode(val);
    }
    if(val<root->val_){
      insert(root->left_,val);
      rebalance(root);
    }
    if(val>root->val_){
      insert(root->right_,val);
      rebalance(root);
    }
    updateHeight(root);
}

void rebalance(TreeNode* &root) {
    // The following line is to silence compiler warnings.  Delete it.
    if(root==NULL){
      return;
    }
    if(heightOrNeg1(root->right_)-heightOrNeg1(root->left_)==2){
      if (heightOrNeg1(root->right_->right_)-heightOrNeg1(root->right_->left_)==1){
        rotateLeft(root);
      }
      else{
        rotateRightLeft(root);
      }
    }
    else if(heightOrNeg1(root->right_)-heightOrNeg1(root->left_)==-2){
      if(heightOrNeg1(root->left_->right_)-heightOrNeg1(root->left_->left_)==-1){
        rotateRight(root);
      }
      else{
        rotateLeftRight(root);
      }
    }
    updateHeight(root);
    return;
}

// Helper functions

int heightOrNeg1(TreeNode *root) {
    if (root==NULL)
        return -1;
    else
        return root->height_;
}

void updateHeight(TreeNode * node) {
    node->height_ = 1 + std::max(heightOrNeg1(node->right_), heightOrNeg1(node->left_));
}

using namespace std;

void show(TreeNode *t1) {
    if (t1==NULL) {
        cout << "x";
        return;
    }

    if (t1->left_ == NULL && t1->right_==NULL) {
        cout << t1->val_;
        return;
    }

    cout << "(" << t1-> val_ << " ";
    show(t1->left_);
    cout << " ";
    show(t1->right_);
    cout << ")";
}

void deleteTree(TreeNode* root)
{
    if (root == NULL) return;
    deleteTree(root->left_);
    deleteTree(root->right_);
    delete root;
    root = NULL;
}
