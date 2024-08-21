#pragma once
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
    int val;
    TreeNode* left;
    TreeNode* right;
};

class BinaryTree {
public:
    BinaryTree();
    ~BinaryTree();

    void insert(int value);
    void insertNode(int value);
    void swapNodes(TreeNode* node1, TreeNode* node2);
    void swapNodes(int node1, int node2);
    void treeSort(); // sorts & balances 
    void removeNode(int value);

    void deleteTree();

    TreeNode* bruteForceSearch(int target); 
    TreeNode* depthFirstSearch(int target); 
    TreeNode* breadthFirstSearch(int target); 

private:
    TreeNode* root;

    TreeNode* insertRecursive(TreeNode*& node, int value);
    void swapNodesRecursive(TreeNode* node, int node1, int node2);
    void inorderTraversal(TreeNode* node, vector<int>& inorderVals);
    TreeNode* buildTree(vector<int>& vals, int l, int r);
    TreeNode* treeSortRecursive(TreeNode* root); 
    TreeNode* removeNodeRecursive(TreeNode* node, int value);

    TreeNode* bruteForceSearchRecursive(TreeNode* node, int target);
    TreeNode* dfsRecursive(TreeNode* node, int target);

    void deleteTreeRecursive(TreeNode* node);
};