#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <string>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) {
    data = val;
    left = nullptr;
    right = nullptr;
    }
};

//хранит корень и размер дерева
struct CompleteBinaryTree {
    TreeNode* root;
    int size;
};

CompleteBinaryTree* createCBT();
void deleteCBT(CompleteBinaryTree* tree);
bool isEmptyCBT(const CompleteBinaryTree* tree);
void clearCBT(CompleteBinaryTree* tree);
void insertCBT(CompleteBinaryTree* tree, int value); // Это все еще вставка для BST
void deleteNodeCBT(CompleteBinaryTree* tree, int value);
bool searchCBT(CompleteBinaryTree* tree, int value);
void printTreeCBT(CompleteBinaryTree* tree);

bool isComplete(CompleteBinaryTree* tree);

//void convertToComplete(CompleteBinaryTree* tree);

#endif 
