//tree_traversal.hpp
#pragma once
#include "linked_binary_tree.hpp"
#include <queue>
#include <deque>

namespace dsac::tree {

//container must be able to store 
//objects of type Position
// Used for copying, make copy for top-level directory first, then recursively copy contents
template <typename Position, typename Container>
void preorder(Position p, Container& visited) {
    visited.push_back(p); // visit node before traversing its children
    for (Position child : p.children()) { // Recursively traverse each subtree of root
        preorder(child, visited);
    }
}

// Used for deletion, delete all contents first, then delete top-level directory
template <typename Position, typename Container>
void postorder(Position p, Container& visited) {
    for (Position child : p.children()) { // Recursively traverse all subtrees of root first
        postorder(child, visited);
    }
    visited.push_back(p); // Then visit the root (post-order)
}


template <typename Position, typename Container>
void breadthfirst(Position p, Container& visited) {
    if (!p.is_null()) {
        
        std::queue<Position> fringe;
        fringe.push(p);

        while (!fringe.empty()) {  // visit all nodes level by level
            Position curr fringe.front();
            fringe.pop();
            visited.push_back(curr);

            for (Position c : curr.children()) {
                fringe.push(c);
            }
        }
    }
}


template <typename Position>
std::queue<Position> breadthfirst_2(Position p); // ToDo



template <typename Position, typename Container>
void inorder(Position p, Container& visited) {
    if (!p.is_null()) {
        
        inorder(p.left(), visited);  // Traverses binary trees only in order:
        visited.push_back(p);        // Left -> Right -> Root
        inorder(p.right(), visited);
    }
}

}//end namespace