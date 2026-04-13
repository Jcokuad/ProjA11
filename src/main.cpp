// src/main.cpp
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm> // std::max
#include "tree/linked_binary_tree.hpp"
#include "tree/tree_traversal.hpp"

int main() {
    dsac::tree::LinkedBinaryTree<int> T;
    T.add_root(10);
    auto r = T.root();
    T.add_left(r, 5);
    T.add_right(r, 20);
    T.add_left(r.left(), 3);
    T.add_right(r.left(), 7);
    T.add_right(r.right(), 30);

    std::cout << "Left Nodes: " << T.count_left_leaves_bfs() << "\n"; //3
    std::cout << "Left Nodes: " << T.count_left_leaves() << "\n"; //3

    return 0;
}
