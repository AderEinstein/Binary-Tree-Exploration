#include "BinaryTree.h"
#include <algorithm>
#include <queue>

BinaryTree::BinaryTree() : root(nullptr) {
}
BinaryTree::~BinaryTree() {
    deleteTree();
}
void BinaryTree::insertNode(int value) {
    root = insertRecursive(root, value);
}
void BinaryTree::swapNodes(TreeNode* node1, TreeNode* node2) {
    if (!node1 || !node2) return;
    swap(node1, node2);
}
void BinaryTree::swapNodes(int node1, int node2) {
    swapNodesRecursive(root, node1, node2);
}
void BinaryTree::treeSort() {
    root = treeSortRecursive(root);
}
void BinaryTree::removeNode(int value) {
    root = removeNodeRecursive(root, value);
}

void BinaryTree::deleteTree() {
    deleteTreeRecursive(root);
    root = nullptr; 
}
TreeNode* BinaryTree::bruteForceSearch(int target) {
    return bruteForceSearchRecursive(root, target);
}

TreeNode* BinaryTree::depthFirstSearch(int target) {
    return dfsRecursive(root, target);
}

TreeNode* BinaryTree::breadthFirstSearch(int target) {
    if (!root) return nullptr;
    std::queue<TreeNode*> queue;
    queue.push(root);
    while (!queue.empty()) {
        TreeNode* currentNode = queue.front();
        queue.pop();
        if (currentNode->val == target) return currentNode;
        if (currentNode->left != nullptr) queue.push(currentNode->left);
        if (currentNode->right != nullptr) queue.push(currentNode->right);
    }
    return nullptr;
}

TreeNode* BinaryTree::insertRecursive(TreeNode*& node, int value) {
    if (!node)  return new TreeNode(value);
    if (value < node->val) node->left = insertRecursive(node->left, value);
    else node->right = insertRecursive(node->right, value);
    return node;
}
void BinaryTree::insert(int value) {
    if (root == nullptr) {
        root = new TreeNode(value);
        return;
    }

    TreeNode* current = root;
    TreeNode* parent = nullptr;

    while (current != nullptr) {
        parent = current;
        if (value < current->val) current = current->left;
        else current = current->right;
    }
    if (value < parent->val) 
        parent->left = new TreeNode(value);
    else 
        parent->right = new TreeNode(value);
}

void BinaryTree::swapNodesRecursive(TreeNode* node, int node1, int node2) {
    if (!node) return;
    if (node->val == node1) node->val = node2;
    else if (node->val == node2) node->val = node1;
    swapNodesRecursive(node->left, node1, node2);
    swapNodesRecursive(node->right, node1, node2);
}

void BinaryTree::inorderTraversal(TreeNode* node, vector<int>& inorder) {
    if (!node) return;
    inorderTraversal(node->left, inorder);
    inorder.push_back(node->val);
    inorderTraversal(node->right, inorder);
}

TreeNode* BinaryTree::buildTree(vector<int>& inorder, int l, int r) {
    if (l > r) return nullptr;
    int mid = (l + r) / 2;
    TreeNode* node = new TreeNode(inorder[mid]);
    node->left = buildTree(inorder, l, mid - 1);
    node->right = buildTree(inorder, mid + 1, r);
    return node;
}

TreeNode* BinaryTree::treeSortRecursive(TreeNode* node) {
    vector<int> inorder;
    inorderTraversal(node, inorder);
    sort(inorder.begin(), inorder.end());
    return buildTree(inorder, 0, inorder.size() - 1);
}

int minValue(TreeNode* node) {
    while (node->left != nullptr) node = node->left;
    return node->val;
}
TreeNode* BinaryTree::removeNodeRecursive(TreeNode* node, int valueToRemove) {
    if (node == nullptr) {
        return nullptr;
    }
    if (valueToRemove < node->val) {
        node->left = removeNodeRecursive(node->left, valueToRemove);
    }
    else if (valueToRemove > node->val) {
        node->right = removeNodeRecursive(node->right, valueToRemove);
    }
    else {
        if (node->left == nullptr) return node->right;
        else if (node->right == nullptr) return node->left;
        // if both children exist, swap curr node with inorder successor (i.e min val > curr val) & delete inorder successor node
        node->val = minValue(node->right);
        node->right = removeNodeRecursive(node->right, node->val);
    }
    return node;
}

TreeNode* BinaryTree::bruteForceSearchRecursive(TreeNode* node, int target) {
    if (node == nullptr) return nullptr;
    if (node->val == target) return node;

    TreeNode* leftResult = bruteForceSearchRecursive(node->left, target);
    if (leftResult != nullptr) return leftResult;

    TreeNode* rightResult = bruteForceSearchRecursive(node->right, target);
    if (rightResult != nullptr) return rightResult;

    return nullptr;
}

TreeNode* BinaryTree::dfsRecursive(TreeNode* node, int target) {
    if (node == nullptr) return nullptr;
    if (node->val == target) return node;
    else if (target < node->val) return dfsRecursive(node->left, target);
    else return dfsRecursive(node->right, target);
}

void BinaryTree::deleteTreeRecursive(TreeNode* node) {
    if (node == nullptr) return;
    deleteTreeRecursive(node->left);
    deleteTreeRecursive(node->right);
    delete node;
}