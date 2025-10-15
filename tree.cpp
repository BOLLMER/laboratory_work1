#include "tree.h"
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

void deleteTreeRecursive(TreeNode* node) {
    if (node == nullptr) return;
    deleteTreeRecursive(node->left);
    deleteTreeRecursive(node->right);
    delete node;
}

TreeNode* findMin(TreeNode* node) {
    while (node && node->left != nullptr) {
        node = node->left;
    }
    return node;
}

TreeNode* deleteNodeRecursive(TreeNode* root, int value, int& size) {
    if (root == nullptr) return nullptr;

    if (value < root->data) {
        root->left = deleteNodeRecursive(root->left, value, size);
    } else if (value > root->data) {
        root->right = deleteNodeRecursive(root->right, value, size);
    } else {
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            size--;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            size--;
            return temp;
        }
        TreeNode* successor = findMin(root->right);
        root->data = successor->data;
        root->right = deleteNodeRecursive(root->right, successor->data, size);
    }
    return root;
}

void printTreeUtil(TreeNode* node, const std::string& prefix, bool isLast, const std::string& direction) {
    if (node == nullptr) return;
    
    std::cout << prefix << (isLast ? "└──" : "├──") << node->data << direction << std::endl;
    
    std::string childPrefix = prefix + (isLast ? "    " : "│   ");
    
    if (node->left != nullptr || node->right != nullptr) {
        printTreeUtil(node->left, childPrefix, node->right == nullptr, " (LEFT)");
        if (node->right != nullptr) {
            printTreeUtil(node->right, childPrefix, true, " (RIGHT)");
        }
    }
}

CompleteBinaryTree* createCBT() {
    CompleteBinaryTree* tree = new CompleteBinaryTree;
    tree->root = nullptr;
    tree->size = 0;
    return tree;
}

void deleteCBT(CompleteBinaryTree* tree) {
    if (tree == nullptr) return;
    deleteTreeRecursive(tree->root);
    delete tree;
}

void clearCBT(CompleteBinaryTree* tree) {
    if (tree != nullptr) {
        deleteTreeRecursive(tree->root);
        tree->root = nullptr;
        tree->size = 0;
        std::cout << "Дерево очищено." << std::endl;
    }
}

bool isEmptyCBT(const CompleteBinaryTree* tree) {
    return tree == nullptr || tree->root == nullptr;
}

void insertCBT(CompleteBinaryTree* tree, int value) {
    if (tree == nullptr) return;
    TreeNode* newNode = new TreeNode(value);
    if (tree->root == nullptr) {
        tree->root = newNode;
        tree->size++;
        std::cout << "Элемент " << value << " добавлен." << std::endl;
        return;
    }
    TreeNode* current = tree->root;
    while (true) {
        if (value < current->data) {
            if (current->left == nullptr) {
                current->left = newNode;
                tree->size++;
                std::cout << "Элемент " << value << " добавлен." << std::endl;
                return;
            }
            current = current->left;
        } else if (value > current->data) {
            if (current->right == nullptr) {
                current->right = newNode;
                tree->size++;
                std::cout << "Элемент " << value << " добавлен." << std::endl;
                return;
            }
            current = current->right;
        } else {
            std::cout << "Элемент " << value << " уже существует." << std::endl;
            delete newNode;
            return;
        }
    }
}

void deleteNodeCBT(CompleteBinaryTree* tree, int value) {
    if (isEmptyCBT(tree)) {
        std::cout << "Нельзя удалить из пустого дерева." << std::endl;
        return;
    }
    int initialSize = tree->size;
    tree->root = deleteNodeRecursive(tree->root, value, tree->size);
    if (tree->size < initialSize) {
        std::cout << "Элемент " << value << " удален." << std::endl;
    } else {
        std::cout << "Элемент " << value << " не найден." << std::endl;
    }
}

bool searchCBT(CompleteBinaryTree* tree, int value) {
    if (isEmptyCBT(tree)) return false;
    TreeNode* current = tree->root;
    while(current != nullptr){
        if(current->data == value) return true;
        current = (current->data > value) ? current->left : current->right;
    }
    return false;
}

void printTreeCBT(CompleteBinaryTree* tree) {
    if (isEmptyCBT(tree)) {
        std::cout << "Дерево пустое." << std::endl;
        return;
    }
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Дерево (размер: " << tree->size << "):" << std::endl;
    printTreeUtil(tree->root, "", true, " (ROOT)");
    std::cout << "------------------------------------------" << std::endl;
}


bool isComplete(CompleteBinaryTree* tree) {
    if (isEmptyCBT(tree)) {
        std::cout << "Дерево пустое, оно считается полным." << std::endl;
        return true;
    }

    std::queue<TreeNode*> q;
    q.push(tree->root);
    bool null_found = false; 

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        if (current == nullptr) {
            null_found = true;
        } else {
            if (null_found) {
                std::cout << "Дерево НЕ является полным." << std::endl;
                return false;
            }
            q.push(current->left);
            q.push(current->right);
        }
    }

    std::cout << "Дерево является полным." << std::endl;
    return true;
}

//рекурсивно собирает все значения из дерева в массив.
void extractValuesToArray(TreeNode* node, int* arr, int& index) {
    if (node == nullptr) return;
    arr[index++] = node->data;
    extractValuesToArray(node->left, arr, index);
    extractValuesToArray(node->right, arr, index);
}
