// Programming Evaluation for RainCity Housing.cpp
// @author: Franklin Ader Mba Wetbe
// This file contains the 'main' function. Program execution begins and ends there.
//

#include "BinaryTree.h"
#include <chrono>

int main() {
    BinaryTree bTree;
    cout << "Binary Tree created\n\n";

    // Problem #1
    for (int i = 1; i < 5; i++) bTree.insertNode(i*5);
    for (int i = 1; i < 5; i++) bTree.insertNode(i);
    for (int i = 1; i < 5; i++) bTree.insertNode(i*5+2);
    bTree.swapNodes(2, 5);
    bTree.swapNodes(2, 10);
    bTree.treeSort();
    bTree.removeNode(7);

    bTree.deleteTree();

    // Problem #2
    for (int i = 1; i < 4000; i++) bTree.insert(i*10);
    bTree.treeSort();

    // Brute Force Search
    auto bruteForceStart = chrono::high_resolution_clock::now();
    if (bTree.bruteForceSearch(20000)) {
        cout << "Target Node found!\n";
    }
    else {
        cout << "Target Node not found!\n";
    }
    auto bruteForceEnd = chrono::high_resolution_clock::now();
    chrono::duration<double> bruteForceDuration = bruteForceEnd - bruteForceStart;
    cout << "Brute Force Search Time: " << bruteForceDuration.count() << " seconds\n\n";

    // Breadth-First Search
    auto bfsStart = chrono::high_resolution_clock::now();
    if (bTree.breadthFirstSearch(20000)) {
        cout << "Target Node found!\n";
    }
    else {
        cout << "Target Node not found!\n";
    }
    auto bfsEnd = chrono::high_resolution_clock::now();
    chrono::duration<double> bfsDuration = bfsEnd - bfsStart;
    cout << "Breadth-First Search Time: " << bfsDuration.count() << " seconds\n\n";

    // Depth-First Search
    auto dfsStart = chrono::high_resolution_clock::now();
    if (bTree.depthFirstSearch(20000)) {
        cout << "Target Node found!\n";
    }
    else {
        cout << "Target Node not found!\n";
    }
    auto dfsEnd = chrono::high_resolution_clock::now();
    chrono::duration<double> dfsDuration = dfsEnd - dfsStart;
    cout << "Depth-First Search Time: " << dfsDuration.count() << " seconds\n\n";

    return 0;
}

/*
Time Complexity Analysis :

Algorithm	        Best Case	Average Case	Worst Case
Brute Force Search	O(1)	    O(n)	        O(n)
Depth-First Search	O(1)	    O(log₂n)	    O(n)
BreadthFirst Search	O(1)	    O(n)	        O(n)

Comments:

Best Case: All search algorithms have a best case of O(1) when the target is found at the root node.
Average Case: Depth-First Search is the fastest at an average case of O(log₂n) because it leverages the properties of a balanced BST to efficiently search for the target. 
Worst Case: The worst case for all search algorithms is O(n) when the target is at the deepest level of the tree or not present in the tree. 
This occurs when the tree is highly unbalanced (for DFS) or the target is not present. (BFS)
*/ 